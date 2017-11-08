#include<iostream>
#include<string>

#include"carte.h"


carte::carte()
{
};

carte::carte(string couleur, string numero, int puissance, int argent, int graph, int position):coloration(couleur),nombre(numero),valeur(puissance),valeurMoney(argent),valeurGraph(graph),indiceGraph(position) {};


void carte::setcarte(string couleur,string numero, int puissance, int argent, int graph, int position)
{
    coloration=couleur;
    nombre=numero;
    valeur=puissance;
    valeurMoney=argent;
    valeurGraph=graph;
    indiceGraph=position;
};


void carte::setValeur(int puissance)
{
    valeur = puissance;
};

void carte::setIndiceGraph(int position)
{
    indiceGraph=position;
};

string carte::getColor()
{
    return coloration;
};

string carte::getNbrCarte()
{
    return nombre;
};

int carte::getValeur()
{
    return valeur;
};


int carte::getMoney()
{
    return valeurMoney;
};


int carte::getValeurGraph()
{
    return valeurGraph;
};


int carte::getIndiceGraph()
{
    return indiceGraph;
};


string carte::getNombre()
{
    return nombre;
}

