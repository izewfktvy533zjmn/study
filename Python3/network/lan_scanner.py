#!/usr/bin/env python3
import socket


class LANScanner():
    def __init__(self):
        self._hostname = socket.gethostname()
        print(self._hostname)
        self._network_ip = socket.gethostbyname(self._hostname)
        print(self._network_ip)
        self._network_prefix = self._network_ip.split(".")
        del(self._network_prefix[-1])
        self._network_prefix = '.'.join(self._network_prefix)

    def check_ip(self, current_ip):
        soc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        soc.settimeout(0.01)

        if not soc.connect_ex((current_ip, 135)):
            soc.close()
            return 1

        else:
            soc.close()
            return 0

    def start_scan(self):
        print("Your IP: {}".format(self._network_ip))
        print("scanning lan network...")

        for ip in range(1, 255):
            current_ip = self._network_prefix + '.' + str(ip)

            if self.check_ip(current_ip):
                print("{0} \t- {1}".format(current_ip, socket.getfqdn(current_ip)))

        print("scan finished")


if __name__ == "__main__":
    lan_scanner = LANScanner()
    lan_scanner.start_scan()
