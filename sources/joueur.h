#ifndef joueur_h
#define joueur_h

#include"carte.h"

using namespace std;


class joueur
{
private :
    int argent;         // argent du joueur
    string pseudo;      // pseudo du joueur
    int nbcarte_Restante; // nombre de carte lui restant à jouer
    carte carteEnMain[15];  // tableau de carte que le joeueur possede, initialisé à 15, pour le max de cartes possibles.
    bool humain;            // si oui : humain, sinon, robot

public:
    joueur();
    joueur(int,string,int, bool);

    void perteArgent(int); // enleve le montant au joueur
    void gainArgent(int);  // rajoute le montant au joueur
    void poseCarte(int);    // pose la carte (nombre de carte -1, et mise à 0 de la carte dans le tableau
    void distriCarte(carte*,int*,int); // distribue les crates au joueur
    void triCarte(); // trie les cartes en main du joueurs
    carte donneActu(int); // retourne la carte que l'on veut jouer

    int getNombre(); // retourne le nombre de carte restante à jouer
    bool getHumain();//si oui : humain, sinon, robot
    int getArgent(); //retourne la valeur de l'argent
    string getNom(); // retourne le pseudo
    int getValeur(int); //retourne la valeur de la carte se trouvant à l'indice du tableau
    int getValeurMoney(int); // retourne la valeur monétaire de la carte se situant à l'indice du tableau de carte en main
    int getValeurGraphique(int); // retourne la valeur graphique de la carte se situant à l'indice du tableau de carte en main
    int getIndiceCarteGraphique(int); // retourne la valeur de l'indice graphique(affichage) de la carte se situant à l'indice du tableau de carte en main
    string getCouleur(int); // retourne la couleur de la carte se situant à l'indice du tableau de carte en amin

    void setIndiceCarteGraphique(int, int); // change la valeur de l'indice graphique de la carte se situant à l'indice du tableau de carte en main
    void setNombreCarteRestante(int); // change le nombre de carte restante au joueur
};

#endif
