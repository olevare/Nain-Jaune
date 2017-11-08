#ifndef fonction_h
#define fonction_h

#include"carte.h"
#include"joueur.h"

using namespace std;


void initialisation(carte*); // initialise un tableau de 52 cartes differentes
void initRepet(int*); //initialise le tableau de repetition, qui servira pour la distribution de cartes
int quantiteJoueur(); // fonction qui initialise les joueurs
int calculNombreCarte(int); // retourne le nombre de cartes à distribuer suivant le nombre de joueurs
int motentier(string); // passer un string en entier
int debutJeu(joueur*, carte*, int*, int); // articule le debut du jeu
void my_delay(int i); // à remplacer par sleep en passant sous linux
void melangejoueur(joueur*,int);//melange l'ordre des joueurs
void gainCarteRobot(joueur*, int, int, int); // donne la mise d'une carte joué par le robot
void score(int, joueur*, int, int, int, int); // permet d'actualiser le tableau des scores

#endif
