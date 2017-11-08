#ifndef deroulementJeu_h
#define deroulementJeu_h


void jouer (joueur*, int, carte*,int,int); // fonction articulant tous le jeu
joueur* jeux (joueur*, int*, int&, carte*, int);
/*
la fonction jeux articule la fonction jouer et prend en charge
le renouvellement du tableau de joeurs, et permet la boucle de jeu
*/
#endif
