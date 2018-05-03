import serial
import time

n = 5
for i in range(n):
	file = open("../Resources/Data.txt","w")
	ser = serial.Serial("/dev/ttyACM0", 9600).readline()
	try:
		#i = 1
		#20
		#trame = ser.split(",", 1)
		#annee = trame[i]
		#mois = trame[i+1]
		#jour = trame[i+2]
		#heure = trame[i+3]
		#minute = trame[i+4]
		#seconde = trame[i+5]
		#nbsat = trame[i+6]
		#temps_marche = trame[i+7]
		#latitude = trame[i+8]
		#longitude = trame[i+9]
		#altitude_GPS = trame[i+10]
		#temperature = trame[i+11]
		#pression = trame[i+12]
		#trigger1 = trame[i+13]
		#trigger2 = trame[i+14]
		#trigger12 = trame[i+15]
		#compteur1 = trame[i+16]
		#compteur2 = trame[i+17]
		#coincidence = trame[i+18]
		file.write(ser)
	finally:
		file.close()
		time.sleep(0.9)
file.close()
