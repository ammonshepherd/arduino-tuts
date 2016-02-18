from Adafruit_IO import *
import serial, sys

# Adafruit IO Key, read it from a file named aio-key
with open ("aio-key", "r") as keyfile:
    aiokey = keyfile.read().strip()

aio = Client(aiokey)

with serial.Serial(port=sys.argv[1], baudrate=sys.argv[2]) as ser:
    if ser.isOpen():
        ser.readline()
    while ser.isOpen():
        aio.send('Foo', ser.readline())



