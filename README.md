# Sokoban
Marcoly ANTOINE
Adrien GAME
# Utilite et retours 

Ce projet est réalisée dans le cadre de notre cours Technique de developpement. On y génère le jeu tres connu Sokoban.

Lors de la réalisation de notre projet nous avons eu des difficultés au niveau de la gestion des versions et des outils à utiliser. En effet n'ayant aucun de nous un ordinateur portable avec Ubuntu nous n'avons pas pu profiter intégralement, ou du moins à distance, de ces outils ce qui nous faisait avancer lentement dans la programmation.De plus habitant en dehors de Strasbourg nous ne pouvons nous reunir tous les jours. Pour pallier à cela nous avons organisé le weekend du 12/11 une grande séance de codage à distance en utilisant l'outil Virtual Studio Code via l'option code live qui nous a permis de coder ensemble. 
Nous y sommes parvenus au bout du weekend et avons au cours de la semaine suivante fait le dépot du fichier en y apportant les dernières modifications. 
La première partie du projet fut une réussite.

Version de gcc utilise:
gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
Copyright (C) 2019 Free Software Foundation, Inc.


version de clang
clang version 10.0.0-4ubuntu1 
Target: x86_64-pc-linux-gnu
Thread model: posixersion 

## Fichiers principaux:

- main.c
- grid.c
- player.c 

## Dépendances: 

- librairie <stdbool.h>
- librairie <stiod.h>


# Partie 2

Cette partie du projet fut tres laborieux. De par la difficulte de se procurer le materiel necessaire pour avancer.
Decouvrant les bibiotheques et cette maniere de gerer nous avons du passer beaucoup d'heures avant de reussir a mettre la bibliotheque sdl2 sur nos ordis respectifs. Utilisant un mac et mon binome un windows nous avons galerer sur plusieurs semaines.
De plus, la faculte etant ferme pendant les vacances nous n'avons plus eu le materiel de la faculte a disposition ce qui nous a retarde dans nos avancees. 
De machine virtuelle a ssh les solutions trouvees n'ont pas pu nous aider a avancer comme nous nous le voulions .


Nous avons durant la derniere semaine de decembre donne tout ce que nous avions afin d'avoir ce resultat vu nos difficultes a nous coordonner.

Cependant nous sommes arrives a la fin.

Deux erreurs sont a deplorer :
En version sdl2 nous avons verifies avec valgrind et trouves des fuites memoires que nous avons cherche en vain.
(En console tout marche bien)

De meme avec la librairie sdl2 l'inclusion du fichier level.txt pose probleme si on le met en second.

Faire :
    make 
    cd bin/
    ./main bug
Cependant nous avons remarque que si nous faisions :
    make 
    cd ./bin/main tout se lance sans probleme