import paho.mqtt.publish as publish

 

publish.single("ifn649","LED_OFF",hostname="13.211.229.65") #Your IP Address
print("Done, LED is OFF")
