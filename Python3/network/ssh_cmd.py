#!/usr/bin/env python3
import threading
import paramiko
import subprocess


def ssh_command(ip, user, passwd, command):
    client = paramiko.SSHClient()
    #client.load_host_key("")
    client.set_missing_host_key_policy(paramiko.AutoAddPolicy)
    client.connect(ip, username=user, password=passwd)
    ssh_session = client.get_transport().open_session()

    if ssh_session.active:
        ssh_session.exec_command(command)
        print(ssh_session.recv(1024))

    return None


if __name__ == "__main__":
    ssh_command("172.29.156.91", "pi", "6RI1BDVqdofEQUQd", "ls")
