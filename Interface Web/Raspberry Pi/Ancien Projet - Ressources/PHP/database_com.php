<?php 

header( 'content-type: text/html; charset=utf-8' );

try {
	$bdd = new PDO('mysql:host=localhost;dbname=muons_detector;charset=utf8', 'pi', 'muons');
} catch(Exception $e) {
	die('Erreur :'. $e->getMessage());
}

$req = $bdd->prepare('SELECT * FROM muons_trames ORDER BY time_on DESC LIMIT 5');
$req->execute();

while($donnees = $req->fetch()) {
	$texte = '<table><tr><td id="date">' .
		$donnees['annee'] .
		'-' .
		$donnees['mois'] .
		'-' .
		$donnees['jour'] .
		'</td><td id="heure">' .
		$donnees['heure'] .
		'h' .
		$donnees['minute'] .
		'</td><td id="seconde">' .
		$donnees['seconde'] .
		'</td><td id="nb_satellites">' .
		$donnees['nb_satellites'] .
		'</td><td id="latitude">' .
		$donnees['latitude'] .
		'</td><td id="longitude">' .
		$donnees['longitude'] .
		'</td><td id="altitudegps">' .
		$donnees['altitude_GPS'] .
		'</td><td id="temperature">' .
		$donnees['temperature'] .
		'</td><td id="pression">' .
		$donnees['pression'] .
		'</td><td id="trigger1">' .
		$donnees['trigger1'] .
		'</td><td id="trigger2">' .
		$donnees['trigger2'] .
		'</td><td id="trigger_both">' .
		$donnees['trigger_both'] .
		'</td><td id="compteur1">' .
		$donnees['compteur1'] .
		'</td><td id="compteur2">' .
		$donnees['compteur2'] .
		'</td><td id="coincidences">' .
		$donnees['coincidences'] .
		'</td></tr></table>';


	echo utf8_decode($texte);
}

?>
