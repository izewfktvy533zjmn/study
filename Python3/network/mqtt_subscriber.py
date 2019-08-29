#!/usr/bin/env python3
import paho.mqtt.client as mqtt


MQTT_BROKER_ADDR = '172.29.156.95'
MQTT_BROKER_PORT = 1883


def onConnect(client, userdata, flags, response_code):
    print(userdata)
    client.subscribe("#", qos=0)


def onMessage(client, userdata, msg):
    print("userdata: " + userdata)
    print("topic   : " + msg.topic)
    print("payload : " + msg.payload.decode('utf-8'))
    print()


if __name__ == "__main__":
    client = mqtt.Client(userdata="SmartInoueLab", protocol=mqtt.MQTTv31)
    client.on_connect = onConnect
    client.on_message = onMessage
    client.connect(host=MQTT_BROKER_ADDR, port=MQTT_BROKER_PORT, keepalive=0)

    try:
        client.loop_forever()
    
    except KeyboardInterrupt:
        client.disconnect()
