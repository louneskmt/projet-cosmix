#include <SPI.h>
#include <Ethernet2.h>

byte mac[] = {0x90, 0xA2, 0xDA, 0x11, 0x12, 0x11}; // Adresse MAC du shield
IPAddress ip(192,168,0,55); // Adresse IP du shield

EthernetServer serveur(4200); //Initialisation du serveur sur le port 4200

void setup() 
{
  Serial.begin(9600); // Démarrage port série
  
  char erreur = 0; // Variable de retour de fonction
  erreur = Ethernet.begin(mac); // Récupération du retour de fonction

  if(erreur == 0) // Si il y a une erreur...
  {
    Serial.println("Parametrage avec une IP fixe...");
    Ethernet.begin(mac, ip);
  }
  Serial.print("Initialisation avec l'IP locale ");
  Serial.print(Ethernet.localIP());
  Serial.println("...");
  delay(1000);
  serveur.begin(); // Lancement du serveur
  Serial.println("Prêt !");
}

void loop() 
{
  EthernetClient client = serveur.available();

  if(client) {
    Serial.println("Envoi de données");

    client.println("HTTP/1.1 200 OK"); // Code de réponse 200 (réussite)
    client.println("Content-Type: application/json");
    client.println();

    // Réponse JSON
    client.println("{"); // On commence notre JSON par une accolade ouvrante
    client.print("\t\"uptime (ms)\": "); // On envoie la première clé : "uptime"
    client.print(millis()); // Puis la valeur de l'uptime
    client.println(","); //Une petite virgule pour séparer les deux clés
    client.print("\t\"analog 0\": "); // Et on envoie la seconde nommée "analog 0"
    client.println(analogRead(A0));
    client.println("}"); // Et enfin on termine notre JSON par une accolade fermante

    // Donne le temps au client de prendre les données
    delay(10);
    // Ferme la connexion avec le client
    client.stop();
  }
  delay(100);
}
