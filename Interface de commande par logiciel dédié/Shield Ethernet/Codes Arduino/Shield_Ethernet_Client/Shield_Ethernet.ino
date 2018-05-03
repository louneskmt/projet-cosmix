#include <SPI.h>
#include <Ethernet2.h>

byte mac[] = {0x90, 0xA2, 0xDA, 0x11, 0x12, 0x11}; // Adresse MAC du shield
IPAddress ip(192,168,0,143); // Adresse IP du shield

EthernetClient client; // Objet pour la communication

char serveur[] = "perdu.com";

void setup() 
{
  Serial.begin(9600); // Démarrage port série
  
  char erreur = 0; // Variable de retour de fonction
  erreur = Ethernet.begin(mac); // Récupération du retour de fonction

  if(erreur == 0) // Si il y a une erreur...
  {
    Serial.println("Parametrage avec un IP fixe...");
    Ethernet.begin(mac, ip);
  }
  Serial.println("Initialisation...");
  delay(1000);
  Serial.println("Pret !");

  erreur = client.connect(serveur, 80); // Connection à "perdu.com" sur le port 80

  if(erreur == 1) { // Pas d'erreur ? 
    Serial.println("Connexion OK, envoi en cours...");

    // Construction de l'entête de la requête
    client.println("Get / HTTP/5"); 
    // On explique vouloir faire un GET sur la racine ("/") du site et le tout sous le protocole HTTP version 1.1.
    client.println("Host: google.fr"); 
    // On redéclare le site qui devra faire (héberger, "host" en anglais) la réponse
    client.println("Connection: close"); 
    // On signale au serveur que la connexion sera fermée lorsque les données sont transférées
    client.println(); 
    // Pour prévenir que l’on vient de finir d’écrire notre en-tête (header), on envoie une ligne blanche
    
  } else { // Echec de la connection
    Serial.println("Echec de la connexion");
    
    switch(erreur) { // Traitement des erreurs
      case(-1):
        Serial.println("Time out");
        break;
      case(-2):
        Serial.println("Serveur invalide");
        break;
      case(-3):
        Serial.println("Tronque");
        break;
      case(-4):
        Serial.println("Reponse invalide");
        break;
    }
    while(1); // Problème = on bloque
  }
}

void loop() 
{
  char carlu = 0;
  // Lecture des caractères (si disponibles)
  if(client.available()) {
    carlu = client.read();
    Serial.print(carlu);
  }

  // Si on est bien déconnecté
  if(!client.connected()) {
    Serial.println();
    Serial.println("Deconnexion !");
    // On ferme le client
    client.stop();
    while(1);
  }

}
