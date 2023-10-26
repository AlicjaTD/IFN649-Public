import serial
import paho.mqtt.client as mqtt
import sys

sensor_t = "/dev/rfcomm0"
buzzer_t = "/dev/rfcomm1"

bt_rate = 9600

ADD = "3.106.227.78"
PORT = 1883
MQTT_Topic = "Phone-Peek-Preventer"

import paho.mqtt.publish as publish

publish.single("Phone-Peek-Preventer", "LED_ON", hostname="3.106.227.78")
