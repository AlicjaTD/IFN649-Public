import paho.mqtt.publish as publishoff

 

publishoff.single("ifn649","LED_OFF",hostname="13.211.229.65") 
print("Done! The light is now off")
