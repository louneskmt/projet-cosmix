import time
import serial

ser = serial.Serial("/dev/ttyACM0",9600)

while 1 == 1:
	file = open("Data.txt", "w")
	trame = ser.readline()
	try:
		file.write(trame)
		file.close()
		time.sleep(1)
	finally:
		file.close() 
