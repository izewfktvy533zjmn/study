#!/usr/bin/env python3
import socket


target_host = "localhost"
target_port = 5555

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((target_host, target_port))
client.send(b"GET / HTTP/1.1\r\nHost: google.com\r\n\r\n")

response_data = client.recv(4096)
print(response_data)
