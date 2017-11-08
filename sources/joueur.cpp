#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>

#include"joueur.h"

using namespace std;


joueur::joueur ()
{
    argent=0;
    pseudo="sansNom";
    nbcarte_Restante=0;
    carteEnMain[0];
};

joueur::joueur (int arg, string nomJ, int cartMain, bool hum):argent(arg),pseudo(nomJ),nbcarte_Restante(cartMain), humain(hum) {};


void joueur::perteArgent(int montant)
{
    argent-=montant;
};

void joueur::gainArgent(int montant)
{
    argent+=montant;
};

void joueur::poseCarte(int indice)
{
    nbcarte_Restante--;
    carteEnMain[indice].setcarte("0","0", 0, 0, 0, 0); // appelle une methode de carte
};                                                     // afin de mettre la carte à 0

void joueur::setNombreCarteRestante(int nbCarte)
{
    nbcarte_Restante= nbCarte;
};

void joueur::distriCarte(carte liste[], int repete[], int nbCaDi)
{
    int alea, i, j, compteur;
    bool repetition = false;
    srand(time(0));
    for(i=0; i<nbCaDi; i++)
    {
        alea=rand()%52; // on prend un nombre aleatoire de 0 à 51
        compteur=0;
        repetition = false;
        for(j=0; j<52; j++) // on regarde si cet indice est deja dans le tableua de repetition
        {
            if(repete[j] != 99) // si un indice est dans la case
                compteur++;     // cela nous servira pour savoir ou placer le prochain indice qu'on donner

            if(alea == repete[j]) // si l'indice est déja dans le tableau
            {
                i--; // il faut recommencer cette carte
                repetition = true; // on sort de la boucle de verification des doublons
            }
        }
        if(!repetition) //si on est sortie sans repetition, c'est que c'est bon
        {
            repete[compteur] = alea; // on met a la premiere case "vide" (99) l'indice qu'on donne au joueur
            carteEnMain[i] = liste[alea]; // on donne la carte d'indice alea au joueur
        }
    }
};

void joueur::triCarte()
{
    int i, j, indice=0;
    carte tableau[nbcarte_Restante]; // on créer un nouveau tableau de carte
    for (i=0; i<nbcarte_Restante; i++) // pour remplir le nouveau tableau
    {
        for(j=0; j<nbcarte_Restante; j++)//on parcours l'ancien tableau
        {
            if(carteEnMain[indice].getValeur() > carteEnMain[j].getValeur()) // si la valeur est plus petite que la variable
            {
                indice = j; // on garde en mémoire son indice
            }
        }
        tableau[i] = carteEnMain[indice];//on peut mettre la carte la plus petite trouvé dans ce nouveau tableau
        carteEnMain[indice].setValeur(99);//on met la valeur de la carte de l'ancien tableau a 99 afin d'être sur de ne pas la réutiliser
    }
    for(i=0; i<nbcarte_Restante; i++) // on repasse tout le nouveau tableau dans la main du joueur
    {
        carteEnMain[i] = tableau[i];
    }
};

int joueur::getNombre()
{
    return nbcarte_Restante;
};

int joueur::getValeurMoney(int indice)
{
    return carteEnMain[indice].getMoney(); // appele la methode getMoney de carte
};

bool joueur::getHumain()
{
    return humain;
};

int joueur::getValeurGraphique(int indice)
{
    return carteEnMain[indice].getValeurGraph(); // appelle la methode de carte
};

void joueur::setIndiceCarteGraphique(int indice, int po)
{
    carteEnMain[indice].setIndiceGraph(po); // appelle la methode de carte
};

int joueur::getIndiceCarteGraphique(int indice)
{
    return carteEnMain[indice].getIndiceGraph();// appelle la methode de carte
};

int joueur::getArgent()
{
    return argent;
};

carte joueur::donneActu(int indice)
{
    return carteEnMain[indice];
};

int joueur::getValeur(int indice)
{
    return carteEnMain[indice].getValeur(); // appelle la methode de carte
}

string joueur::getNom()
{
    return pseudo;
};

string joueur::getCouleur(int indice)
{
    return carteEnMain[indice].getColor(); // appelle la methode de carte
}
