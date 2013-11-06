				|Projet Diff - Répartition des tâches|
				-------------------------------------

/*************************************************************************/
								|ORGANISATION|
								 ------------
	
	(Les procédures représentant les option du diff devront avoir un nom assez explicite,
	par exemple pour l'option "-a", diffLineByLine [Comparaison brute ligne par ligne] 
	serait judicieux)
	
	nbFonctionsParTour = 3
	TantQue( (Date < DateRendu) && (nbFonctionsDiff != nbFonctionsRealisees) ) Faire
		Jamal.Repartition(nbFonctionsParTour)
		Julie.Travail()
		Amaury.Travail()
		Jamal.Travail()
		Groupe.PartageGIT()
		Groupe.Concertation()

/*************************************************************************/

--------------------------------------------------------------------------
Groupe entier:
----------------
A) Réaliser le fichier "diff.c/h" permettant de rediriger le résultat
de l'opération selon le nombre d'arguments et leur nature reçu dans 
le main

B) Tester les fonctionnalités une par une et vérifier la concordance
avec le cahier des charges (améliorer les procédures du mieux que possible)
--------------------------------------------------------------------------

Première étape: Bases du diff

--------------------------------------------------------------------------
II) Julie M'KPI:
----------------
A) "-a" : Comparaison de deux fichiers lignes par lignes
B) "-b" : diff basique (comparaison caractère par caractère) mais en ignorant les espaces blancs
C) "-i" : Ignorer les différences entre minuscules et majuscules
--------------------------------------------------------------------------

--------------------------------------------------------------------------
II) Jamal BOUIZEM:
----------------
A) Version basique du diff sans option
B) "-y" : Utiliser l'affichage côte-à-côte (side-by-side).
C) "--expand-tabs" : Développer les tabulations en espaces en sortie, afin de préserver l'alignement des tabulations des fichiers d'entrée.
--------------------------------------------------------------------------


--------------------------------------------------------------------------
II) Amaury COLMANT:
----------------
A) "--brief" : Comparaison de deux fichiers et retourne simplement si il y a une différence ou pas
sans indiquer en détail la différence entre les deux fichiers
B) "-B" : Ne pas tenir compte des différences qui concernent des lignes blanches.
C) "--suppress-common-lines" : Ne pas afficher les lignes communes dans le format side-by-side.
--------------------------------------------------------------------------
