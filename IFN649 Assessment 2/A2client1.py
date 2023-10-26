import serial
import paho.mqtt.client as mqtt
import sys

sensor_t = "/dev/rfcomm0"
buzzer_t = "/dev/rfcomm1"

bt_rate = 9600

ADD = "3.106.227.78"
PORT = 1883
MQTT_Topic = "Phone-Peek-Preventer"

def on_connect(client, userdata, flags, rc):
    print(f"Connected to MQTT broker with result code {rc}")
    client.subscribe(MQTT_Topic)

def on_message(client, userdata, msg):
    print(f"Received message on topic {msg.topic}:{msg.payload.decode()}")
    ser = buzzer_serial
    message_to_send = msg.payload.decode('utf-8') + '\n'
    ser.write(message_to_send.encode())


mqtt_client = mqtt.Client()
mqtt_client.on_connect = on_connect
mqtt_client.on_message = on_message
mqtt_client.connect(ADD, PORT, 60)

sensor_serial = serial.Serial(sensor_t, bt_rate)
buzzer_serial = serial.Serial(buzzer_t, bt_rate)
sensor_serial.write(str.encode('Start\r\n'))
buzzer_serial.write(str.encode('Start\r\n'))

while True:
    if sensor_serial.in_waiting > 0:
        rawserial = sensor_serial.readline()
        cookedserial = rawserial.decode('utf-8').strip('\r\n')
        print(f"Received data: {cookedserial}")

        try:
            mqtt_client.loop_start()
            print("Listening")
            sensor_data = sensor_serial.readline().decode().strip()

            if "Object removed" in sensor_data:
                 mqtt_client.publish(MQTT_Topic, "LED_ON")
		 
            else:
                 mqtt_client.publish(MQTT_Topic, "LED_OFF")

        except KeyboardInterrupt:
            print("Exiting the script.")
            sensor_serial.close()
            buzzer_serial.close()
            sys.exit(0)
