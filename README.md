 ______      ____       ______      __         _____       __  __      ____      
/\  _  \    /\  _`\    /\  _  \    /\ \       /\  __`\    /\ \/\ \    /\  _`\    
\ \ \L\ \   \ \ \L\ \  \ \ \L\ \   \ \ \      \ \ \/\ \   \ \ `\\ \   \ \ \L\_\  
 \ \  __ \   \ \  _ <'  \ \  __ \   \ \ \  __  \ \ \ \ \   \ \ , ` \   \ \  _\L  
  \ \ \/\ \   \ \ \L\ \  \ \ \/\ \   \ \ \L\ \  \ \ \_\ \   \ \ \`\ \   \ \ \L\ \
   \ \_\ \_\   \ \____/   \ \_\ \_\   \ \____/   \ \_____\   \ \_\ \_\   \ \____/
    \/_/\/_/    \/___/     \/_/\/_/    \/___/     \/_____/    \/_/\/_/    \/___/ 

#README

	Le principe du projet est de recoder le principe du jeu de 
	billes Abalone pour 2 joueurs en C++ avec une version graphique
    à l'aide de QT et une autre dans le terminal en implementent
    un observateur observer.
	
	Abalone est un jeu de stratégie combinatoire abstrait où 
    s’affrontent deux joueurs chacun possedant 14 billes de sa couleur,
    c'est à dire blanche ou noire. Le but du jeu étant de faire tombé 
    au moins 7 billes de l'adversaire avant qu'il ne fasse tomber 
    7 des nôtres.
	
#Règles du jeu
	
	https://www.letempledujeu.fr/IMG/pdf/abalone.pdf

#Fonctionnement du jeu
    
    Afin de jouer correctement au jeu, il est nécessaire de comprendre
    comment lui passer notre mouvement. Dans la version graphique,
    Le joueur aura le choix entre trois entrées.

    La première étant de 2 billes, il choisira sa bille de départ sur 
    le plateau en cliquant dessus dans la version graphique, ou en 
    donnant sa position dans la version terminal. Après celle-ci, 
    le joueur devra à nouveau choisir une des positions qui sont collées
    à la bille de départ. Ce mouvement peut inclure une autre billes de 
    la couleur du joueur mais pas de l'adversaire. Voir règles du jeu.

    La deuxième étant de 3 billes. Ceci servira à effectuer un mouvement
    de groupe latéral c'est à dire vers le coté gauche ou droit du groupe.
    Il choisira d'abord la bille de départ/indicatrice pour la direction,
    une seconde bille pour indiquer ou se termine le groupe à bouger
    (Ne pas oublier, maximum de trois billes peuvent être bougée 
    la fois) et la dernière bille doit se trouver autour mais collée à
    la première et aidera à determiner dans quelle direction doit bouger
    le groupe.


##Done by Gregory van der Pluijm et Maciej Rolecki