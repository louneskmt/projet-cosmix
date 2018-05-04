## **Idées pour le développement d’une interface web pour le COSMIX**

###   I.	Shield Ethernet Arduino  

Utilisation d’un Shield Ethernet connecté directement à la carte Arduino Méga principale.  

Plus :
-	Coût moins important (Shield à 25€ environ)
-	Mise en place plus simple ? (A voir, car le code peut être plus complexe à réaliser)
Moins : 
-	Peut de possibilité d’empiler le Shield sur la carte. A voir.
-	Peut-être incompatible avec les autres Shields déjà présents.
-	Difficulté pour les pages web dans des fichiers .html sur la carte SD
-	Alourdit le code alors qu’une autre partie du projet consiste à l’alléger

###   II.	Raspberry Pi  

Connection d’un mini-ordinateur Raspberry Pi sous Raspbian, qui servirait de serveur au Cosmix, mais également de « traiteur de données » (avant de les envoyer).
  
Plus :
-	Allège le code de la carte Arduino
-	Données plus claires et mises en forme pour l’utilisateur
-	Mise en place d’un serveur plus simple (car ordinateur sous Linux, système d’exploitation de référence pour les serveurs)
-	Idée - Possibilité de gestion de la carte Arduino selon nos besoins : injection d’un programme différent selon l’utilisation voulu (avec ou sans GPS, baromètre, …), vu que la carte Arduino sera directement reliée au Raspberry Pi
Moins :
-	Coût plus important (une soixantaine d’euros pour le Starter Kit), mais possibilité d’en récupérer une du lycée ? 

###   III.	Conclusion  

Le Raspberry Pi semble être la meilleure option mais il faudrait se pencher plus sur les deux idées.

