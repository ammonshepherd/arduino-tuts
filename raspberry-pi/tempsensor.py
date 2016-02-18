# Call with three arguments
# 1 = port
# 2 = Baudrate
# 3 = output file name
# ex: python tempsensor.py /dev/ttyACM0 9600 readings.csv

import serial, sys, datetime


with open(sys.argv[3], "w") as f:
  with serial.Serial(port=sys.argv[1], baudrate=sys.argv[2]) as ser:
    if ser.isOpen():
      ser.readline()
    while ser.isOpen():
      f.write('{}, {}'.format(datetime.datetime.now().strftime('%c'), ser.readline()))
