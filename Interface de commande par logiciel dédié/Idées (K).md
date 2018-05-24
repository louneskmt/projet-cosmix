# Idées par Killian

TODO : https://github.com/arduino/Arduino/blob/master/build/shared/manpage.adoc

# Logiciel (client)

Le logiciel client peut être utilisé afin de se connecter à distance ou en USB au [serveur] Cosmix.

### Fontionnalités du logiciel
- Gestionnaire de périphériques : Affiche l'état de la connexion et le type de connexion (Internet ou USB).
- Enregistrer ou afficher une mesure
- Afficher un graphique des mesures obtenues (SVG)
- Lancer une mesure pour un temps donné
- Paramètrer les mesures (GPS, Baromètre, temps)
- Sauvegarder et ouvrir des paramètres (`.cms` ➞ Cosmix Mesure Settings)
- Programmer une mesure pour une date donnée (éventuellement, éveiller automatiquement l'appareil puis l'éteindre)
- Arrêter les mesures après un certains nombres d'événements
- Afficher en temps réel les mesures sur un graphique
- Filtrer les données manuellement et automatiquement (coïncidences, ...)

# Gestion des données

### Sauvegardes et traîtements des fichiers

#### Sauvegarder le fichier
- Sauvegardes des mesures dans un fichier `.csmx`


### Traîter le fichier
Le fichier `.csmx` est un fichier au format `Plain Text`. 

Chaque fichier doit contenir les informations suivantes :
- Version
- Date précise de démarrage des mesures
- Date précise de fin des mesures
- Paramètrage
- Unité utilisée (Multiplicateur)
- Mesures observées
- Donées GPS*
- Données baromètre*
- Nom du projet*

*\* optionnel*

#### Traîtement des mesures observées
Afin de minimiser le temps d'écriture des données, il faut minimiser les données. 

Pour minimiser les données écrites, au lieu d'écrire la Date de l'événement, il sera écrit le temps (en secondes!) depuis le précédent événement.

#### Exemple de fichier :

```
v1.1
$Start: Wed May 23 2018 21:33:32 GMT+0400 (+04)
$End: Wed May 23 2018 22:33:32 GMT+0400 (+04)
$Unit: 10 (Secondes à multiplier par 10)
$Options: 7 (111 en binaire = GPS:oui / $Baromètre:oui / Données Serial en temps réel:oui)
$DataEventBegin
1,10,23,45
$DataEventEnd
$DataGPSBegin
        //...
$DataGPSEnd
```