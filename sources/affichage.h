#ifndef affichage_h
#define affichage_h

#include"carte.h"
#include"joueur.h"

using namespace std;


void hautCartes(int); // affiche le haut des cartes
void finCarte(int); // affiche le dessous des cartes
void milieuCarte(int, joueur&); //affiche le milieu des cartes ( valuer et couleur de la carte)
void plateau(joueur*, int); // affiche le plateau ainsi que l'argent des joueurs et le nombre de carte restantes à jouer
void affichActu(carte); // affiche la carte actuel, qui est posé
void affichage(carte, joueur*, int, int); //  combine les 5 fonctions precendentes.

#endif
