#ifndef carte_h
#define carte_h

using namespace std;


class carte
{
private :
    string nombre;    //nombre de la carte [as-roi]
    string coloration;  //couleur de la carte
    int valeur;    // valeur de la carte [1-13]
    int valeurMoney; //valeur monetaire de la carte [1-10]
    int valeurGraph; //choix du dessin [1-52]
    int indiceGraph; //inde de carte dans l'ordre de l'affichage [1-15]

public :
    carte(); //constructeur par défaut
    carte(string,string, int, int, int, int); //constructeur parametré

    void setcarte(string,string, int, int, int, int); //modifie toutes les valeurs de cartes
    void setValeur(int);//modifie la valeur [1-13]
    void setIndiceGraph(int);//modifie l'indice graphique de la carte

    int getIndiceGraph(); // renvoie indice des cartes à l'écran
    string getNombre();
    string getNbrCarte(); // renvoie nbre carte
    string getColor(); // renvoie la couleur de la carte
    int getValeur(); // renvooie la valeur de la carte
    int getMoney(); // renvoie la valeur monetaire de la carte
    int getValeurGraph(); // renvoie la valeur graphique des 52 cartes

};

#endif
