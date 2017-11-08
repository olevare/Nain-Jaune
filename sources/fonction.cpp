#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<fstream>

#include"fonction.h"
#include "carte.h"

using namespace std;

void initialisation(carte tableauE[])
{
    int i=0,j=0,mod=0;
    //nombre possede les 13 valeurs des cartes differentes
    string nombre[13]= {"as","2","3","4","5","6","7","8","9","10","valet","dame","roi"};
    string colour[4]; // les 4 couelurs differentes
    colour[0]="\xE2\x99\xA3";
    colour[1]="\xE2\x99\xA6";
    colour[2]="\xE2\x99\xA5";
    colour[3]="\xE2\x99\xA0";
    for(i=0; i<4; i++) // on fait une boucle pour insere les differentes couleurs
    {
        while(j<13) // on insere egalement les 13 differentes valeurs de cartes
        {
            if(nombre[j] == "valet" || nombre[j] == "dame", nombre[j] == "roi" )
                tableauE[j+mod].setcarte(colour[i],nombre[j],j+1, 10, (j+mod+1), 0);
                /*
                si la carte est une tete, on lui donne une valeur monétaire de 10

                sinon on lui met la couleur i, la valeur j ...
                */
            else tableauE[j+mod].setcarte(colour[i],nombre[j],j+1, j+1, (j+mod+1), 0);
            j++;
        }
        mod+=13; // cela nous sert pour mettre la valeur graphie de 0 à 52
        j=0;
    }
};


void initRepet(int tableau[])
{
    int i;
    for (i=0; i<52; i++)
    {
        tableau[i] = 99;
    }
};


int quantiteJoueur()
{
    int quantR, quantV, quantT, mini;
    // quantR = joueurs réels, quantv = joueurs virtuel, quantT = joueurs total
    string stringQuant,montanArg;
    cout << "combien de joueurs réels etes vous? (de 0 a 8 joueurs)"<< endl;
    cin >> stringQuant;
    quantR = motentier(stringQuant);
    cout << endl;
    // si la quantité n'est pas bonne
                                       // on a du mettre ça dû à une erreur si un joueur entré une lettre
    while (quantR<0 || quantR>8  || ( stringQuant=="a" ||  stringQuant=="b" ||  stringQuant=="c" || stringQuant=="d" || stringQuant=="e" || stringQuant=="f"|| stringQuant=="g" || stringQuant=="h"))
    {
        cout << "le nombre n'est pas valide, veuillez revoir votre requete" << endl;
        cin >> stringQuant;
        quantR = motentier(stringQuant);
    }
    mini= 3-quantR; // calcul le minimum de joeurs virutels pour le jeu
    cout << "combien de joueurs virtuels souhaitez-vous ? ";
    if(mini >0)
        cout<<"Au minimum : "<< mini;
    else cout<<"Au minimum : 0";
    cout <<" Au maximum : " << 8-quantR<<endl;
    cin >> stringQuant;
    quantV = motentier(stringQuant);
    while (quantV<mini || quantV>8-quantR  || ( stringQuant=="a" ||  stringQuant=="b" ||  stringQuant=="c" || stringQuant=="d" || stringQuant=="e" || stringQuant=="f"|| stringQuant=="g" || stringQuant=="h"))
    {
        cout << "le nombre n'est pas valide, veuillez revoir votre requete" << endl;
        cin >> stringQuant;
        quantV = motentier(stringQuant);
    }
    quantT=quantR+quantV;
    return quantT;
};


int motentier(string entre) // passage d'un string à un entier
{
    int i, resultat=0, mult=1;
    int taille = entre.size();
    for(i=taille-1; i>=0; i--)
    {
        resultat+= (((entre[i])%48) * mult);
        mult=mult*10;
    }
    return resultat;
}

int calculNombreCarte(int nbreJoueur)
{
    int nbCarte;
    switch(nbreJoueur)
    {
    case 3:
        nbCarte = 15;
        break;
    case 4:
        nbCarte=12;
        break;
    case 5:
        nbCarte=9;
        break;
    case 6:
        nbCarte=8;
        break;
    case 7:
        nbCarte=7;
        break;
    case 8:
        nbCarte=6;
        break;
    }
    return nbCarte;
}

int debutJeu(joueur tableauJou[], carte tableauE[], int repet[], int nbreJoueur)
{
    string choix;
    int nbCarte, montant, choixInt;
    ofstream journal("journal.txt", ios::app);

    nbCarte = calculNombreCarte(nbreJoueur);
    cout << "quelle sera le montant d'argent de départ commun à tous les joueurs?"<<endl;
    cout<< "1) 50\n2) 100\n3) 200\n4) 400\n5) 800\n6) 1000"<<endl;
    cin >>choix;
    while(choix!="1" && choix!="2" && choix!="3" && choix!="4" && choix!="5" && choix!="6")
    {
        cout<<"je n'ai pas compris..."<<endl;
        cin>>choix;
    }
    choixInt=motentier(choix);
    switch(choixInt)
    {
    case 1:
        montant=50;
        break;
    case 2:
        montant=100;
        break;
    case 3:
        montant=200;
        break;
    case 4:
        montant=400;
        break;
    case 5:
        montant=800;
        break;
    case 6:
        montant=1000;
        break;
    }
    journal<<"Le montant de départ de tous les joueurs est : " <<montant<< " €." <<endl<<endl;
    // ecriture dans le journal
    for(int i=0; i<nbreJoueur; i++) // on parcours tous les joueurs
    {
        string nom, humain;
        cout << "joueur "<< i+1<< " etes vous humain? (oui ou non)"<<endl;
        cin>> humain;
        while(humain != "oui" && humain != "non")
        {
            cout<<"heu... es-tu un extra-terrestre? je n'ai pas compris ta réponse."<<endl;
            cin>>humain;
        }
        cout << "joueur "<< i+1<< " veuillez nous donner votre pseudo."<<endl;
        cin >> nom;

        if(humain =="oui")
        {
            joueur j(montant, nom, nbCarte, true); // on créer un joueur
            j.distriCarte(tableauE, repet, nbCarte); // on lui distribue des cartes
            j.triCarte(); // on lui trie les cartes
            tableauJou[i] = j; // on le met dans le tableau
            //on ecrit dans le journal
            journal<<"Le joueur "<<j.getNom()<< " € rejoint la partie. "<<endl;
        }
        else // sinon, c'est un robot
        {
            joueur j(montant, nom, nbCarte, false); // on créer le robot
            j.distriCarte(tableauE, repet, nbCarte);
            j.triCarte();
            tableauJou[i] = j;
            journal<<"Le bot "<<j.getNom()<< " à rejoint la partie. "<<endl;
        }

    }
    melangejoueur(tableauJou,nbreJoueur); // on mélange le tableua de joueurs
    journal.close();
    return montant;
}




void melangejoueur(joueur tab[], int nbreJoueur)
{
    srand(time(0));
    int alea;
    joueur Jt;

    for(int i=0; i<nbreJoueur; i++)
    {
        alea=rand()%nbreJoueur;
        Jt=tab[alea];
        tab[alea]=tab[i];
        tab[i]=Jt;
        cout<<"il a "<<tab[i].getNombre()<<"et "<< Jt.getNombre()<<endl;

    }
}

void gainCarteRobot(joueur tableauJou[], int indice, int nbreJoueur, int h)
{
    ofstream journal("journal.txt", ios::app);
    switch(tableauJou[indice%nbreJoueur].getValeurGraphique(h)) //si la carte est une du plateau
    {
    case 23:
        tableauJou[indice%nbreJoueur].gainArgent(nbreJoueur);
        journal<<tableauJou[indice%nbreJoueur].getNom()<<" pose un 10 de carreau et empoche la mise de "<<nbreJoueur<<" €."<<endl;
        break;
    case 37:
        tableauJou[indice%nbreJoueur].gainArgent(2*nbreJoueur);
        journal<<tableauJou[indice%nbreJoueur].getNom()<<" pose un Valet de trèfle et empoche la mise de "<<2*nbreJoueur<<" €."<<endl;
        break;
    case 51:
        tableauJou[indice%nbreJoueur].gainArgent(3*nbreJoueur);
        journal<<tableauJou[indice%nbreJoueur].getNom()<<" pose une Dame de pique et empoche la mise de "<<3*nbreJoueur<<" €."<<endl;
        break;
    case 13:
        tableauJou[indice%nbreJoueur].gainArgent(4*nbreJoueur);
        journal<<tableauJou[indice%nbreJoueur].getNom()<<" pose un Roi de coeur et empoche la mise de "<<4*nbreJoueur<<" €."<<endl;
        break;
    case 20:
        tableauJou[indice%nbreJoueur].gainArgent(5*nbreJoueur);
        journal<<tableauJou[indice%nbreJoueur].getNom()<<" pose un 7 de carreau et empoche la mise de "<<5*nbreJoueur<<" €."<<endl;
        break;
    }
    journal.close();
}

void score(int nbreJoueur, joueur tableauJou[], int ratioUn, int ratioFichier, int montantDepart, int nbreJouDepart)
{
    int cptLigne, avant=0, i;
    string contenu, contenuDeu;
    for(i=0; i<nbreJoueur; i++) // on parcours tous les joueurs
        {
            if(tableauJou[i].getArgent()>0 && tableauJou[i].getHumain()) // si le joeur possede de l'argent, c'est qu'il est suceptible d'aller dans les scores
            {
                ratioUn = ((tableauJou[i].getArgent())-montantDepart)/nbreJouDepart; // on calcul le ratio
                if (ratioUn>0) // si le joueur a un ratio positif
                {
                    ifstream scoreLecture("score.txt", ios::in);
                    scoreLecture.seekg(0, ios::end); // on se positinnne a la fin du fichier afin de savoir s'il est vide
                    if(scoreLecture.tellg() == 0) // s'il est vide
                    {
                        ofstream scoreEcriture("score.txt", ios::app);
                        // on va inscrire le score dans le fichier score
                        scoreEcriture<<tableauJou[i].getNom()<<" avec: "<<ratioUn<<endl;
                    }
                    else //sinon, c'est que le fichier possede deja des lignes de scores
                    { // il va falloir desormais savoir combien il en a
                        cptLigne=0; // compteur de ligne initialisé à 0
                        scoreLecture.seekg(0, ios::beg); // on se place au début du fichier
                        remove("buffer.txt");
                        ofstream bufferEcriture("buffer.txt", ios::app);
                        avant=0; // variable nous permettant de savoir quelle est la ligne a laquelle on doit ajouter juste apres notre score
                        while(!scoreLecture.eof())
                        {
                            cptLigne++;
                            scoreLecture>>contenu>>contenuDeu>>ratioFichier; // notre score etant composé de "nom avec: ratio", on met le premier mot dans une variable, mle deuxieme dans une autre et le ratio dans une variable ratioFichier
                            bufferEcriture<<contenu<<" "<<contenuDeu<<" "<<ratioFichier<<endl; // on réecrit la ligne lu dans le buffer
                            if (ratioFichier>ratioUn)
                            {
                                avant = cptLigne; // nous permet de savoir ou placer notre score
                            }
                        }
                        cptLigne--; // car il lit une ligne de trop
                        ifstream bufferLecture("buffer.txt", ios::in);
                        if(cptLigne<10) // si le fichier ne possede pas encore 10 scores, on peut le rajouter, à la bonne place
                        {
                            scoreLecture.close();
                            remove("score.txt");
                            ofstream scoreEcriture("score.txt", ios::app);
                            for(int y=0; y<avant; y++) // on réecrit dans le fichier score les scores plus elevé que le present
                            {
                                bufferLecture>>contenu>>contenuDeu>>ratioFichier;
                                scoreEcriture<<contenu<<" "<<contenuDeu<<" "<<ratioFichier<<endl;
                            }
                            scoreEcriture<<tableauJou[i].getNom()<<" avec: "<<ratioUn<<endl; // on inscirt dans le fichier score le present score
                            for(int y=avant; y<cptLigne; y++)// on complete le fichier score avec le reste du buffer
                            {
                                bufferLecture>>contenu>>contenuDeu>>ratioFichier;
                                scoreEcriture<<contenu<<" "<<contenuDeu<<" "<<ratioFichier<<endl;
                            }
                            scoreEcriture.close();
                            scoreLecture.close();
                            bufferEcriture.close();
                            bufferLecture.close();
                        }
                        else // si le fichier possede deja 10 scores
                        {
                            if(avant<10) // cela veut dire que le score present est plus elevé que le dernier score du fichier, donc il faut l'inserer
                            {
                                scoreLecture.close();
                                remove("score.txt");
                                ofstream scoreEcriture("score.txt", ios::app);
                                for(int y=0; y<avant; y++)
                                {
                                    bufferLecture>>contenu>>contenuDeu>>ratioFichier;
                                    scoreEcriture<<contenu<<" "<<contenuDeu<<" "<<ratioFichier<<endl;
                                }
                                scoreEcriture<<tableauJou[i].getNom()<<" avec: "<<ratioUn<<endl;
                                for(int y=avant+1; y<cptLigne; y++)
                                {
                                    bufferLecture>>contenu>>contenuDeu>>ratioFichier;
                                    scoreEcriture<<contenu<<" "<<contenuDeu<<" "<<ratioFichier<<endl;
                                }
                                scoreEcriture.close();
                                scoreLecture.close();
                                bufferEcriture.close();
                                bufferLecture.close();
                            }
                        }
                    }
                }
            }
        }
}
