import serial

arduino_serial = serial.Serial('/dev/rfcomm0', 9600)  # Use the correct serial port
while True:
    data = arduino_serial.readline().decode('utf-8')
    print(data, end='')
