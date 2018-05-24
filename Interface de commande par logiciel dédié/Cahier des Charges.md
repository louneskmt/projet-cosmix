# Cahier des Charges Fonctionnel du projet

## Serveur Cosmix

### Présentation générale 

Création et hébergement d’un serveur dédié au Cosmix sur un nano-ordinateur Raspberry Pi Model 3B. Il sera connecté par USB à la carte Arduino du Cosmix. 

Le serveur en question sera un serveur Apache 2, avec les modules :
- PHP
- MySQL
- PHPMyAdmin

Il est pour l’instant connecté à la box d’un des participants au projet, en attendant de l’installer au Lycée Roland Garros. 

### Fonctionnalités

Ce serveur devra : 
- Récupérer les données envoyées en SERIAL par la carte Arduino
- Pouvoir contrôler la carte Arduino : lancer des mesures, les arrêter, modifier les options, ...
- Répondre aux requêtes du logiciel dédié associé
- Héberger les données nécessaires au bon fonctionnement du logiciel
- Posséder une adresse IP fixe (du Lycée Roland Garros)
- Être accessible de partout (pas de restrictions d’adresses IP, or dangereuses)
—-

## Logiciel dédié

### Présentation générale

Il s'agirait d'un logiciel développé spécialement pour le Cosmix programmé en langages Web (mais sous forme d’application de bureau grâce à au framework Electron). Ce logiciel se connecterait au serveur Raspberry relié au Cosmix, et pourrait échanger des données avec celui-ci.

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
- Page explicative quant au fonctionnement du détecteur, sur les muons, etc, pour les collèges et lycées qui l'utiliseront potentiellement
