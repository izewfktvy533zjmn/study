#!/usr/bin/env python3
import sys
import socket
import threading


class TCPProxy():
    def __init__(self, local_host, local_port, remote_host, remote_port, receive_first):
        self._local_host = local_host
        self._local_port = local_port
        self._remote_host = remote_host
        self._remote_port = remote_port
        self._receive_first = receive_first
        self._server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

        try:
            self._server.bind((self._local_host, self._local_port))
        
        except Exception:
            sys.stderr.write("[!!] Failed to listen on {0}:{1}\n".format(self._local_host, self._local_port))
            sys.stderr.write("[!!] Check for other listening sockets or correct permissions.\n")
            sys.exit(1)
        
        print("[!!] Listening on {0}:{1}".format(self._local_host, self._local_port))


    def server_loop(self):
        self._server.listen(5)

        while True:
            local_socket, local_addr = self._server.accept()
            
            print("[==>] Received incoming connection from {0}:{1}".format(local_addr[0], local_addr[1]))

            proxy_thread = threading.Thread(target=self._proxy_handler, args=(local_socket,))
            proxy_thread.start()


    def _proxy_handler(self, local_socket):
        remote_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        remote_socket.connect((self._remote_host, self._remote_port))

        if self._receive_first:
            remote_data = self._receive_from(remote_socket)
            print("[==>] Receiving {0} bytes from remote.".format(len(remote_data)))
            self._hexdump(remote_data)
            response_data = self._resopnse_handler(remote_data)

            if len(response_data):
                print("[==>] Sending {0} bytes to localhost.".format(len(response_data)))
                local_socket.send(response_data)

        while True:
            local_data = self._receive_from(local_socket)

            if len(local_data):
                print("[<==] Receiving {0} bytes from localhost.".format(len(local_data)))
                self._hexdump(local_data)
                request_data = self._request_handler(local_data)
                remote_socket.send(request_data)
                print("[<==] Sent to remote.")

            remote_data = self._receive_from(remote_socket)
            
            if len(remote_data):
                print("[==>] Receiving {0} bytes from remote.".format(len(remote_data)))
                self._hexdump(remote_data)
                response_data = self._response_handler(remote_data)
                local_socket.send(response_data)
                print("[==>] Sent to local.")

            if not len(local_data) or not len(remote_data):
                local_socket.close()
                remote_socket.close()
                print("[*] No more data. Closeing connections.")
                break


    def _receive_from(self, soc):
        soc.settimeout(3)
        buff = bytes()

        try:
            while True:
                data = soc.recv(4096)

                if len(data) < 4096:
                    buff += data
                    break

                buff += data

        except Exception as e:
            print(e)
            sys.stderr.write("[!!] Failed to receive data\n")

        return buff


    def _hexdump(self, data, length=16):
        result = []
        digits = 4 if isinstance(data, str) else 2

        for i in range(0, len(data), length):
            line = data[i:i+length].decode()
            
            hex_data = " ".join([str("{:0" + str(digits) + "X}").format(ord(c)) for c in line])

            if not len(hex_data) == 48:
                for _ in range(48 - len(hex_data)):
                        hex_data += " "

            text_data = "".join([c if 0x20 <= ord(c) < 0x7F else "." for c in line])
            result.append("{0:04X}   {1}  {2}".format(i, hex_data, text_data))

        print("\n".join(result))




    def _request_handler(self, data):
        return data


    def _response_handler(self, data):
        return data


    def tear_down(self):
        self._server.close()



if __name__ == "__main__":
    tcp_proxy = TCPProxy("localhost", 5555, "www.google.com", 80, False)
    
    try:
        tcp_proxy.server_loop()

    except KeyboardInterrupt:
        tcp_proxy.tear_down()
