#!/usr/bin/env python3
import time


try:
    while True:
        with open("/sys/class/thermal/thermal_zone0/temp", 'r') as fp:
            cpu_temp = fp.readline()
            
        print(cpu_temp, end="")
        time.sleep(1)

except KeyboardInterrupt:
    pass
