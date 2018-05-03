import serial
import MySQLdb
dbConnect = MySQLdb.connect("localhost","pi","muons","muons_detector") or die ("Impossible de se connecter a la base de donnee") #Etablissement de la connexion avec la base de donnees muons_detector servant a stocker les donnees provenant de l'arduino
n = 0
i = 0
trame_state = 0
trame = ""
y = 0
t = 1
breaker = 0
device = '/dev/ttyACM0'


#device = input("SERIAL PORT (='/dev/ttyACM0' si vide) : ") #Definition du port USB depuis lequel les donnees envoyees par l'Arduino sont recoltees
print("-DEMARRAGE DE LA TENTATIVE DE CONNEXION-")
print(serial.Serial(device,9600).readline())

while i<10:
	print "-TENTATIVE D'ENTREE DE LA TRAME",i,"-"
	cursor = dbConnect.cursor() #Creation de l'objet permettant la communication avec la base de donnee muons_detector
	try:
		arduino = serial.Serial(device,9600) #Tentative de recuperation des donnees sur le port definit dans device
		arduino.flushInput()
		arduino.flushOutput()
		if arduino.write("get") == 3:
			print("-CONNEXION A L'ARDUINO REUSSIE-")
	except:
		print "-IMPOSSIBLE DE RECUPERATION DE LA TRAME",i,"DEPUIS L'ARDUINO-" #Si la tentative echoue, le programme le previent a l'utilisateur
	try:
		while trame_state <> 2:
			character = arduino.read()
			trame += character
			if trame == "DATA ":
				trame = ""
				trame_state = 1
				print '-RECUPERATION DE TRAME DEMARREE-'
			if len(trame.split(",")) == 19:
				trame_state = 2
				print "-FIN DE LA RECUPERATION DE TRAME-"
		trame = trame.split(",")
		print(trame)
		if len(trame) == 19: #Si la chaine est complete (Pas d'erreur de transmission)
			try:
				print len(trame)
				#trame[n+7] = trame[n+7]/1000
				
				#Insertion des donnees obtenues par l'arduino dans la base de donnees muons_detector, dans la table muons_trames
				cursor.execute("INSERT INTO muons_trames (time_on,annee,mois,jour,heure,minute,seconde,nb_satellites,latitude,longitude,altitude_GPS,temperature,pression,trigger1,trigger2,trigger_both,compteur1,compteur2,coincidences) VALUES (%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s)", (trame[n+7],trame[n],trame[n+1],trame[n+2],trame[n+3],trame[n+4],trame[n+5],trame[n+6],trame[n+8],trame[n+9],trame[n+10],trame[n+11],trame[n+12],trame[n+13],trame[n+14],trame[n+15],trame[n+16],trame[n+17],trame[n+18]))
				print '-TRAME',i,'ENTREE DANS LA BASE DE DONNEES-'
				dbConnect.commit()
				cursor.close()
			except MySQLdb.IntegrityError:
				print("L'INSERTION DES DONNEES A ECHOUE") #Le programme previent l'utilisateur d'une eventuelle erreur de communication avec la base de donnees
			finally:
				cursor.close()
	except:
		print("-ECHEC DE LA PROCEDURE-")
	i = i+1
	trame_state = 0
	trame = ""
