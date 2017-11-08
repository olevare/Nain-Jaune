#include<iostream>
#include<string>
#include<fstream>
#include<unistd.h>

#include"fonction.h"
#include "carte.h"
#include"joueur.h"
#include"regle.h"
#include"deroulementJeu.h"
#include"affichage.h"


using namespace std;


void jouer (joueur tableauJou[], int indice, carte tableauE[], int nbreJoueur,int nbcartedi)
{
    ofstream journal("journal.txt", ios::app);
    journal<<endl<<"C'est "<<tableauJou[indice].getNom()<<" le premier à jouer."<<endl;
    // ecriture dans le journal

    int nombreCarte = 10, cpt, cptTour=0, cartePrece=0, valeur;
    bool passe,bon;
    string entre;
    carte actuel("0", "0", 1,1,1,0); // on initialise la carte actuelle à 0
    /*
    on utilise le %nbreJoueur car on increment toujours indice, ce qui nous
    permet de faire le tour du tableau de joueurs
    */
    while(tableauJou[indice%nbreJoueur].getNombre() >0) // tant que le joueur en jeu possede des cartes.
    {
        passe = true; // on initialise passe a true pour pouvoir rentrer dans notre while
        while(passe && tableauJou[indice%nbreJoueur].getNombre()>0) // tant que le joueur ne souhaite pas passser son tour, ou qu'il ne possede plus de carte
        {
            if(tableauJou[indice%nbreJoueur].getHumain()) // si le joueur en question est un humain
            {
                affichage(actuel, tableauJou, nbreJoueur, indice); // affichage
                cout << "quelle carte ou commande souhaitez vous jouer?"<< endl;
                cin >> entre;
                valeur = motentier(entre);
                /*
                   la prochaine boucle servira a redemander au joueeur ce qu'il souahite jouer s'il n'a pas rentrer
                  le mot clé passe, prendre, ou help, ou alors qu'il ai rentré un numero d'indice de carte
                  qu'il ne possede pas
                */
                while(entre!="passe" && entre!="prendre" && (valeur<0 || valeur>tableauJou[indice%nbreJoueur].getNombre()) )
                {
                    if(entre == "help") // s'il a entré help
                    {
                        help();          // affichage de l'aide
                        cin.clear();
                        cout<<"que voulez vous jouer ?"<<endl;
                    }
                    else
                    {
                        cout << "Yo man tu sais pas écrire ? recommence "<< endl;
                    }
                    cin >> entre;
                    valeur = motentier(entre);
                }
                if (entre == "prendre")
                {
                    gainCarte(tableauJou[indice%nbreJoueur], actuel, nbreJoueur);//on passe à la fonction permettant de gagner une mise lorsqu'un joueur pose une carte du plateau
                }
                else
                {
                    if (entre == "passe")
                    {
                        passe = false;  // cela nous fait sortir de notre boucle pour changer de joueur
                        indice++; // on passera au joueur suivant
                        if(cartePrece==actuel.getValeurGraph()) // si la carte actuelle est la meme que celle stocké dans la variable, on incremente un compteur de tour, afin que le dernier à avoir posé une carte non jouable puisse en poser une autre
                            cptTour++;
                        else
                        {
                            cptTour=0; // sinon on remet le compteur de tour à 0
                            cartePrece=actuel.getValeurGraph(); // et on stocke la nouvelle carte actuelle dans la variable
                        }
                        //ecriture dans le journal
                        journal<<tableauJou[indice%nbreJoueur].getNom()<<" passe son tour."<<endl;
                    }
                    else  // si ce n'est aucune des commandes au dessus, c'est que le joueur veux poser une carte.
                        //il nous faut donc désormais decouvrir laquelle.
                    {
                        cpt=0; // initialisation du compteur à 0 pour trouver la carte que le joeur veut jouer
                        while(tableauJou[indice%nbreJoueur].getIndiceCarteGraphique(cpt) != motentier(entre)) // tant que cpt n'est pas l'indice écrit par le joeur, on incremente le compteur
                        {
                            cpt++;
                        }
                        //une fois sortie, nous avons l'indice dans le tableau des carte en main de la carte que le joueur veut jouer
                        //la prochaine condition est très longue, désolé, mais nécessaire.
                        // elle nous permet de redemander au joueur une nouvelle indice si jamais il n'a pas mis la bonne.
                        //cptTour sert à savoir si c'est ce joueur qui a posé la derniere carte non jouable, dans ce cas, il pourra poser celle de son choix.
                        if((motentier(entre) > tableauJou[indice%nbreJoueur].getNombre()) || ((actuel.getValeur() != NULL) && (tableauJou[indice%nbreJoueur].getValeur(cpt) != actuel.getValeur()+1) && (actuel.getValeur() != 13)) && cptTour!=(nbreJoueur-1))
                        {
                            cout<<"l'indice ou la commande que vous avez entré n'est pas valide."<<endl;
                        }
                        else // ça veut dire que a carte est posable, ce qu'on va donc faire ...
                        {
                            actuel = tableauJou[indice%nbreJoueur].donneActu(cpt); // on met à jour la carte actuelle
                            // on ecrit dans le journal
                            journal<<tableauJou[indice%nbreJoueur].getNom()<<" pose la carte "<<tableauJou[indice%nbreJoueur].getValeur(cpt)<<" de "<<tableauJou[indice%nbreJoueur].getCouleur(cpt)<<endl;

                            tableauJou[indice%nbreJoueur].poseCarte(cpt);//on pose la carte du joueur, en appelant la fonctin prévue à cet effet
                        }
                    }
                }
            }
            else // jeu du robot si ce n'est pas un humain !!
            {
                affichage(actuel, tableauJou, nbreJoueur, indice);
                int h=0; // à la palce de cpt, on utilise la variable h
                // parcours le tableau afin de trouver la premiere carte que le robot puisse jouer
                while(((actuel.getValeur()+1)!=tableauJou[indice%nbreJoueur].getValeur(h) && h<15) && (((cptTour != nbreJoueur-1 || tableauJou[indice%nbreJoueur].getValeur(h) == 0))) && actuel.getValeur() != 13  || tableauJou[indice%nbreJoueur].getValeur(h) == 0)
                {
                    h++;
                }
                if(h<15)
                {
                    gainCarteRobot(tableauJou, indice, nbreJoueur, h); // si la carte est une carte du plateau, on donne la mise au robot
                    actuel=tableauJou[indice%nbreJoueur].donneActu(h);
                    journal<<tableauJou[indice%nbreJoueur].getNom()<<" pose la carte "<<tableauJou[indice%nbreJoueur].getValeur(h)<<" de "<<tableauJou[indice%nbreJoueur].getCouleur(h)<<endl;
                    cout<<tableauJou[indice%nbreJoueur].getNom()<<" pose la carte "<<tableauJou[indice%nbreJoueur].getValeur(h)<<" de "<<tableauJou[indice%nbreJoueur].getCouleur(h)<<endl;
                    tableauJou[indice%nbreJoueur].poseCarte(h);
                }
                else // si le robot ne possede aucune carte posable
                {
                    passe = false; // il passe son tour
                    indice++;
                    if(cartePrece==actuel.getValeurGraph())
                        cptTour++;
                    else
                    {
                        cptTour=0;
                        cartePrece=actuel.getValeurGraph();
                    }
                }
                sleep(3); // fonction d'attente
            }
        }
    }
    gainPartie(tableauJou,nbcartedi, nbreJoueur ); //appel de la fonction externe permettant le traitment de la fin d'une manche
    journal.close(); // on ferme le journal
};

joueur* jeux(joueur tableauJou[], int repet[], int &nbreJoueur, carte tableauE[], int nbcarte)
{
    int i, cptJou=0, cptPlace=0;
    initRepet(repet);//on reinitialise le tableua repet
    joueur* nouveau; // on créer un pointeur vers un tableau de jouer qui nous sera util plus bas
    prendreMise(tableauJou, nbreJoueur); // on prend les mises de tous les joueurs
    jouer(tableauJou, 0, tableauE, nbreJoueur, nbcarte); // on appelle la fonction jouer decrite precedemment
    //une fois la manche finit, il va falloir eliminer les personnes n'ayant plus sufissament d'argent pour continuer
    for(i=0; i<nbreJoueur; i++) // parcours de tous les joueurs
    {
        if(tableauJou[i].getArgent()>0) // s'il possède de l'argent
        {
            cptJou++; // incrementation du compteur de joueurs actifs
        }
    }
    if (cptJou <3) // s'il n'y a pas assez de jouers
        nbcarte=1; // il faut mettre un chiffre dans le nombre de cartes restantes, sans quoi, le programme continuera a faire tourner la fonction de triatement de fin de manche
    else
    {
        nbcarte=calculNombreCarte(cptJou); // on calcul le nombre de carte à distribuer
    }
    nouveau = new joueur[nbreJoueur]; // on créer un nouveau tableau de joueurs à la bonne dimension
    for(i=0; i<nbreJoueur; i++) // on parcours l'ancien tableau de joeurs
    {
        if (tableauJou[i].getArgent()>0)// ceux qui peuvent continuer à jouer
        {
            nouveau[cptPlace]= tableauJou[i]; // on les copies dans le nouveau tableau
            nouveau[cptPlace].setNombreCarteRestante(nbcarte); // on reinitialise le nombre de carte à jouer
            nouveau[cptPlace].distriCarte(tableauE, repet, nbcarte); // on distribue les cartes
            nouveau[cptPlace].triCarte(); // on trie les cartes
            cptPlace++; // on incremente la variable de place afin de savoir où placer le prochain joueur actif dans ce nouveau tableau
        }
    }
    delete[] tableauJou; // on supprime l'ancien tableau de joueurs.
    nbreJoueur = cptJou; // on actualise le nombre de joeurs
    return nouveau; // on retourne le nouveau tableau de joueurs
}
