import serial, sys, datetime

with open(sys.argv[3], "w") as f:
  with serial.Serial(port=sys.argv[1], baudrate=sys.argv[2]) as ser:
    if ser.isOpen():
      ser.readline()
    while ser.isOpen():
      f.write('{}, {}'.format(datetime.datetime.now().strftime('%c'), ser.readline()))
