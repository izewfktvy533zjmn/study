#!/usr/bin/env python3
import sys
import socket
import struct


class PacketSniffer():
    def __init__(self):
        self._host = "wlp5s0"
        self._host = "enp4s0"
        self._port = 3
        ETH_P_ALL = 3
        self._soc = socket.socket(socket.AF_PACKET, socket.SOCK_RAW, socket.htons(ETH_P_ALL))
        self._soc.setblocking(True)

        try:
            self._soc.bind((self._host, self._port))
        
        except Exception as e:
            print(e)
            sys.stderr.write("[!!] Failed to listen on {0}:{1}\n".format(self._host, self._port))
            sys.stderr.write("[!!] Check for other listening sockets or correct permissions.\n")
            sys.exit(1)
        
        print("[!!] Listening on {0}:{1}".format(self._host, self._port))


    def start_up(self):
        while True:
            data = self._soc.recv(6+6+2+1500+4+1)
            #data = self._soc.recv(6+6+2)

            if len(data) > 6+6+2+1500+4:
                sys.stderr.write("[!!] Not ethernet frame.\n")

            self._hexdump(data)
            print()


    def _hexdump(self, data, length=16):
        result = []

        for i in range(0, len(data), length):
            line = data[i:i+length]
            
            hex_data = " ".join(["{:02X}".format(c) for c in line])

            if not len(hex_data) == 48:
                for _ in range(48 - len(hex_data)):
                        hex_data += " "

            text_data = "".join([chr(c) if 0x20 <= int(c) < 0x7F else "." for c in line])
            result.append("{0:04X}   {1}  {2}".format(i, hex_data, text_data))

        print("\n".join(result))

    
    def tear_down(self):
        self._soc.close()



if __name__ == "__main__":
    sniffer = PacketSniffer()
    
    try:
        sniffer.start_up()

    except KeyboardInterrupt:
        sniffer.tear_down()
