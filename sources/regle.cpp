#include<iostream>
#include<string>
#include<fstream>

#include"fonction.h"
#include "carte.h"
#include"joueur.h"
#include"affichage.h"

using namespace std;


void prendreMise(joueur tableau[], int nbJoueur) // prendre les mises de tous les joueurs.
{
    int i;
    for (i=0; i<nbJoueur; i++)
    {
        tableau[i].perteArgent(15); // on enleve 15 € à tous les joueurs
    }
};

void gainPartie(joueur tableau[], int nbCaDi, int nbJoueur) // lors de la fin des parties, pour que les perdants payent le gagnant
{
    ofstream journal("journal.txt", ios::app);
    cout<<endl;
    cout<<"------------------------------------------------------"<<endl<<endl;
    int i(0), j, indice(20),somme, sommeTotal=0;
    while (indice == 20) // on cherche le joueur qui gagne
    {
        if (tableau[i].getNombre() == 0) // si le joueur a 0 cartes, c'est le gagnant
            indice = i;
        else i++;
    }
    for (i=0; i<nbJoueur; i++) // on va parcourir tous les joueurs
    {
        somme=0; // on réinitialise la somme à 0
        for(j=0; j<nbCaDi; j++) // on parcours toutes les cartes
        {
            tableau[i].perteArgent(tableau[i].getValeurMoney(j)); // on enleve la somme d'argent adéquate
            somme+=tableau[i].getValeurMoney(j); // on additionne ce prelevement à la somme
            tableau[indice].gainArgent(tableau[i].getValeurMoney(j)); // on donne ce prelevement au gagnant
        }
        if(somme != 0)
        {
            cout<< tableau[i].getNom() << " a donné " << somme << " €."<<endl;
            journal<< tableau[i].getNom() << " a donné " << somme <<" €."<<endl;
            sommeTotal+=somme;
        }
    }

            cout<< tableau[indice].getNom() << " a gagné "<<sommeTotal<<endl;
            journal<< tableau[indice].getNom() << " a gagné " <<sommeTotal<<endl;
            cout<<endl<<endl<<"Bravo "<<tableau[indice].getNom()<<" tu as gagné !"<<endl;
    plateau(tableau,nbJoueur);
    journal.close();
};

void gainCarte(joueur &j, carte &actuel, int quantiteDeJoueur)
{
    ofstream journal("journal.txt", ios::app);
    string entre;
    bool bon = true;
    int cpt,valeur;
    while(bon)
    {
        cout << "Donnez-moi l'indice de la carte que vous souhaitez jouer?"<<endl;
        cout<< "si vous ne pouvez jouer aucune carte, veuillez entrer passe !" << endl;
        cin >> entre;
        while(entre!="passe" && entre!="prendre" && (valeur<0 || valeur>j.getNombre()) )
        {
            cout << "Yo man tu sais pas écrire ? recommence "<< endl;
            cin >> entre;
            valeur = motentier(entre);
        }
        if (entre == "passe")
        {
            bon = false; // pour sortir de la boucle
        }
        else // c'est que le joueur nous donne un indice à jouer
        {
            cpt=0;
            while(j.getIndiceCarteGraphique(cpt) != motentier(entre)) // on cherche la carte dont il souhaite jouer
            {
                cpt++;
            }
            //la prochaine condition, la meme que dans la fonction jouer, nous permet de savoir s'il peut pretendre poser la carte qu'il souhaite
            if((motentier(entre) > j.getNombre()) || ((actuel.getValeur() != NULL) && (j.getValeur(cpt) != actuel.getValeur()+1) && (actuel.getValeur() != 13)))
            {
                cout<<"l'indice ou la commande que vous avez entré n'est pas valide."<<endl;
            }
            else // si c'est valide
            {
                actuel = j.donneActu(cpt); // on met a jour la carte actuelle
                j.poseCarte(cpt); // on pose la carte
                switch(actuel.getValeurGraph()) // on regarde s'il peut vraiment pretendre à un gain de mise par rapport à sa catre posé
                {
                case 23:
                    j.gainArgent(quantiteDeJoueur);
                    journal<<j.getNom()<<" pose un 10 de carreau et empoche la mise de "<<quantiteDeJoueur<<" €."<<endl;
                    break;
                case 37:
                    j.gainArgent(2 * quantiteDeJoueur);
                    journal<<j.getNom()<<" pose un Valet de trèfle et empoche la mise de "<<2*quantiteDeJoueur<<" €."<<endl;
                    break;
                case 51:
                    j.gainArgent(3 * quantiteDeJoueur);
                    journal<<j.getNom()<<" pose une Dame de pique et empoche la mise de "<<3*quantiteDeJoueur<<" €."<<endl;
                    break;
                case 13:
                    j.gainArgent(4 * quantiteDeJoueur);
                    journal<<j.getNom()<<" pose un Roi de coeur et empoche la mise de "<<4*quantiteDeJoueur<<" €."<<endl;
                    break;
                case 20:
                    j.gainArgent(5 * quantiteDeJoueur);
                    journal<<j.getNom()<<" pose un 7 de carreau et empoche la mise de "<<5*quantiteDeJoueur<<" €."<<endl;
                    break;
                default:
                    cout<<"yo ! tu t'es gourré de carte! ta pas un rond  !!"<<endl;
                }
            }
            bon = false; // on sort de la boucle
        }
    }
    journal.close();
};

void help()
{
    int fermer;
    cout<<"Les règles et comment jouer au nain jaune * par Cossin, De Boisvillier, Gaune*"<<endl<<endl<<endl<<endl<<endl;
    cout<<"Chaque joueur reçoit au départ la somme qui a était convenu  "<<endl;
    cout<<"lors du lancement du jeu puis des cartes sont distribués, et "<<endl;
    cout<<" les mises de départ sont prises. "<<endl<<endl<<endl;
    cout<<"le jeu commence. vous avez un emplacement avec 'carte acteulle'."<<endl;
    cout<<" si vous possédez la carte qui est juste un point supérieur à la "<<endl;
    cout<<"carte actuelle, alors, vous la jouez."<<endl<<endl;
    cout<<"si vous possédez une carte figurant sur le plateau, vous récuperez "<<endl;
    cout<<"la mise qui lui correspond. "<<endl<<endl;
    cout<<"vous gagnez si vous avez posé toutes vos cartes. à la fin de cette "<<endl;
    cout<<"manche, les joueurs perdants vous donne la somme de leur en carte "<<endl;
    cout<<"restante en argent."<<endl<<endl<<endl;
    cout<<"Comment manipulez le terminal pour jouer ?"<<endl<<endl;
    cout<<"pour poser une carte, entrez l'indice de la carte indiqué dans "<<endl;
    cout<<"votre main apparu au bas de l'écran."<<endl<<endl;
    cout<<"pour prendre l'argent des mises, vous devez tout d'abord écrire "<<endl;
    cout<<"'prendre', et ensuite, vous écrivez l'indice de la carte correspondante."<<endl<<endl;
    cout<<"si vous ne pouvez pas jouer, ecrivez 'passe'."<<endl<<endl<<endl<<endl;

    cout<<"si jamais je vous manque, vous pouvez me faire réapparaitre en "<<endl;
    cout<<"tapant lors de votre saisiede l'indice d'une carte le mot 'help'."<<endl<<endl<<endl;
    cout<<"bonne chance, et que le gain soit avec vous !"<<endl<<endl;

    cout<<"ps.: si vous n'avez plus besion de moi, "<<endl;
    cout<<"faites moi disparaitre en appuyant sur n'importe quelle touche.  "<<endl<<endl;
    cin>>fermer;
    cout<<endl;
}
