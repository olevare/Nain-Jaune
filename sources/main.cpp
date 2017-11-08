#include<iostream>
#include<string>
#include<fstream>

#include"joueur.h"
#include"carte.h"
#include"fonction.h"
#include"affichage.h"
#include"deroulementJeu.h"
#include"regle.h"

using namespace std;


int main(int argc, char* argv[])
{
  
   if (argv[1] == "help")
  {
    cout<<"on est dedans..."<<endl;
        help();
        //cin.clear();
   }
    ofstream scoreUN("score.txt", ios::app);
    scoreUN.close();

    int i,ratioUn, ratioFichier, montantDepart, nbreJouDepart, avant;
    ofstream journal("journal.txt", ios::app); // on ouvre le fichier journal

    if (journal)
    {
        journal<<"------------------------ !! Nouveau Jeu !! --------------------"<<endl<<endl;
    }
    else
    {
        cout<<"ERREUR ! Le fichier journal est introuvable. Vous n'aurez pas de suivi de partie."<<endl;
    }

    carte tableauE[52]; // on créer un tableau qui comportera toutes les cartes différentes
    int repet[52], cptLigne=0; // on créer un tableau pour mettre les indices des cartes distribués afin d'éviter les répétitions.
    initialisation(tableauE); // on initialise le tableau de cartes.
    string recommence, contenu, contenuDeu;
    do
    {
        initRepet(repet); // on remet le tableau de repetition a 0.
        int nbreJoueur = quantiteJoueur();// on appelle une fonction externe qui deandera le nombre de participants au jeu
        nbreJouDepart=nbreJoueur;
        //-----------------------------------------------------------------------
        journal<<"Une partie va commencer avec "<<nbreJoueur<<" joueurs."<<endl;
        //-----------------------------------------------------------------------
        joueur* tableauJou = new joueur[nbreJoueur]; // on créer un tableau dynamique de joueurs
        journal.close(); // on ferme le fichier jounral, car on n'en a plus besoin.
        montantDepart=debutJeu(tableauJou, tableauE, repet,nbreJoueur); // appelle de la fonction externe
        int nbcarte = calculNombreCarte(nbreJoueur); // on calcule le nombre de carte a distribuer
        while (nbreJoueur >=3)//tant qu'il y a assez de joueur pour jouer
        {
            string continu;
            tableauJou = jeux(tableauJou, repet, nbreJoueur, tableauE, nbcarte); // on actualise tableau de joueurs avec le nouveau tableau renvoyer par notre fonction
            cout<<endl<<"voulez-vous continuer le jeu ?"<<endl;
            cin>>continu;
            while (continu != "oui" && continu != "non")
            {
                cout<<endl<<"je n'ai pas compris ...."<<endl;
                cin>>continu;
            }
            if (continu == "non")
                nbreJoueur = 0; // comme ça, on quitte le jeu
        }
        //a la fin, on inscrit les scores
        score(nbreJoueur, tableauJou, ratioUn, ratioFichier, montantDepart, nbreJouDepart);
        cout<<endl<<endl<<"voulez vous recommencer le jeu ?    ";
        cin>>recommence;
        while (recommence != "oui" && recommence != "non")
        {
            cout<<"je n'ai pas compris ce que vous souhaitez ..."<<endl;
            cin>>recommence;
        }
    }
    while (recommence == "oui");
    return 0;
}


