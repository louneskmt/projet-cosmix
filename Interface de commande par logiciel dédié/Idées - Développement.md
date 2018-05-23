## **Idées pour le développement d’une interface web pour le COSMIX**

###   I.	Shield Ethernet Arduino  

Utilisation d’un Shield Ethernet connecté directement à la carte Arduino Méga principale.  

Plus :
-	Coût moins important (Shield à 25€ environ)
-	Mise en place plus simple ? (A voir, car le code peut être plus complexe à réaliser).  

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
-	Idée - Possibilité de gestion de la carte Arduino selon nos besoins : injection d’un programme différent selon l’utilisation voulu (avec ou sans GPS, baromètre, …), vu que la carte Arduino sera directement reliée au Raspberry Pi.
  
Moins :
-	Coût plus important (une soixantaine d’euros pour le Starter Kit), mais possibilité d’en récupérer une du lycée ? 

###   III.	Conclusion  

Le Raspberry Pi semble être la meilleure option mais il faudrait se pencher plus sur les deux idées.



## Logiciel dédié

### Présentation générale

Il s'agirait d'un logiciel développé spécialement pour le Cosmix programmé en langages Web (mais en application de bureau grâce à au framework Electron). Ce logiciel se connecterait au serveur Raspberry relié au Cosmix, et pourrait échanger des données avec celui-ci.

### Fonctionnalités 

Fonctionnalités certaines :
- Lancement et arrêt de mesure
- Affichage des données à la fin de la mesure 
- Possibilité de réupération du fichier source reçu du Cosmix

Fonctionnalités à implémenter :
- Traitement automatique des données -> création d'un tableur à partir de la chaîne DATA reçue du serveur
- Sélectionner les données voulues
- Affichage des données en temps réel
- Affichage d'un (de) graphique(s) en temps réel (courbes, ...)
- Possibilité de choisir des "options" pour la mesure (avec ou sans GPS, baromètre, ...) -> un programme avec les fonctions appropriées serait téléversé directement dans l'Arduino, afin d'éviter le ralentissement causé par un programme trop lourd
- Possibilité de lancer une mesure avec un temps et intervalle déterminés
- Téléchargement systèmatique de tous les fichiers de mesure, afin d'y avoir accès hors-ligne
- Mot de passe afin d'éviter l'accès à des personnes "non-autorisés" ?
- Pour renforcer la "sécurité" d'une mesure, donner une clé ou quelque chose de précis à la personne ayant lancé la mesure afin qu'elle uniquement puisse y mettre fin en la rentrant (pour éviter que quelqu'un arrête la mesure sans le consentement de ceui qui l'a lancé)
- Page explicative quand au fonctionnement du détecteur, sur les muons, etc, pour les collèges et lycées qui l'utiliseront potentiellement
