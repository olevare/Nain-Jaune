#include<iostream>
#include<string>

#include "carte.h"
#include"joueur.h"
#include"affichage.h"

void hautCartes(int nombreCarte)
{
    switch(nombreCarte)
    {
    case 1:
        cout <<" ____"<<endl;
        cout <<"|    |"<< endl;
        cout <<"|    |"<< endl;
        break;
    case 2:
        cout <<" ____  ____"<<endl;
        cout <<"|    ||    |"<< endl;
        cout <<"|    ||    |"<< endl;
        break;
    case 3:
        cout <<" ____  ____  ____"<<endl;
        cout <<"|    ||    ||    |"<< endl;
        cout <<"|    ||    ||    |"<< endl;
        break;
    case 4:
        cout <<" ____  ____  ____  ____"<<endl;
        cout <<"|    ||    ||    ||    |"<< endl;
        cout <<"|    ||    ||    ||    |"<< endl;
        break;
    case 5:
        cout <<" ____  ____  ____  ____  ____"<<endl;
        cout <<"|    ||    ||    ||    ||    |"<< endl;
        cout <<"|    ||    ||    ||    ||    |"<< endl;
        break;
    case 6:
        cout <<" ____  ____  ____  ____  ____  ____"<<endl;
        cout <<"|    ||    ||    ||    ||    ||    |"<< endl;
        cout <<"|    ||    ||    ||    ||    ||    |"<< endl;
        break;
    case 7:
        cout <<" ____  ____  ____  ____  ____  ____  ____"<<endl;
        cout <<"|    ||    ||    ||    ||    ||    ||    |"<< endl;
        cout <<"|    ||    ||    ||    ||    ||    ||    |"<< endl;
        break;
    case 8:
        cout <<" ____  ____  ____  ____  ____  ____  ____  ____"<<endl;
        cout <<"|    ||    ||    ||    ||    ||    ||    ||    |"<< endl;
        cout <<"|    ||    ||    ||    ||    ||    ||    ||    |"<< endl;
        break;
    case 9:
        cout <<" ____  ____  ____  ____  ____  ____  ____  ____  ____"<<endl;
        cout <<"|    ||    ||    ||    ||    ||    ||    ||    ||    |"<< endl;
        cout <<"|    ||    ||    ||    ||    ||    ||    ||    ||    |"<< endl;
        break;
    case 10:
        cout <<" ____  ____  ____  ____  ____  ____  ____  ____  ____  ____"<<endl;
        cout <<"|    ||    ||    ||    ||    ||    ||    ||    ||    ||    |"<< endl;
        cout <<"|    ||    ||    ||    ||    ||    ||    ||    ||    ||    |"<< endl;
        break;
    case 11:
        cout <<" ____  ____  ____  ____  ____  ____  ____  ____  ____  ____  ____"<<endl;
        cout <<"|    ||    ||    ||    ||    ||    ||    ||    ||    ||    ||    |"<< endl;
        cout <<"|    ||    ||    ||    ||    ||    ||    ||    ||    ||    ||    |"<< endl;
        break;
    case 12:
        cout <<" ____  ____  ____  ____  ____  ____  ____  ____  ____  ____  ____  ____"<<endl;
        cout <<"|    ||    ||    ||    ||    ||    ||    ||    ||    ||    ||    ||    |"<< endl;
        cout <<"|    ||    ||    ||    ||    ||    ||    ||    ||    ||    ||    ||    |"<< endl;
        break;
    case 13:
        cout <<" ____  ____  ____  ____  ____  ____  ____  ____  ____  ____  ____  ____  ____"<<endl;
        cout <<"|    ||    ||    ||    ||    ||    ||    ||    ||    ||    ||    ||    ||    |"<< endl;
        cout <<"|    ||    ||    ||    ||    ||    ||    ||    ||    ||    ||    ||    ||    |"<< endl;
        break;
    case 14:
        cout <<" ___  ___  ___  ___  ___  ___  ___  ___  ___  ___  ___  ___  ___  ___"<<endl;
        cout <<"|   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   |"<< endl;
        cout <<"|   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   |"<< endl;
        break;
    case 15:
        cout <<" ___  ___  ___  ___  ___  ___  ___  ___  ___  ___  ___  ___  ___  ___  ___"<<endl;
        cout <<"|   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   |"<< endl;
        cout <<"|   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   |"<< endl;
        break;
    }
}

/*
afin de garder la bonne largeur d'affichage, il a fallu retrecir les largeurs des
cartes lorsque nous en avions plus de 14
*/

void finCarte(int nombreCarte)
{
    switch(nombreCarte)
    {
    case 1:
        cout <<"|    |"<< endl;
        cout <<"|____|"<<endl;
        cout <<"  01  "<<endl;
        break;
    case 2:
        cout <<"|    ||    |"<< endl;
        cout <<"|____||____|"<<endl;
        cout <<"  01    02 "<<endl;
        break;
    case 3:
        cout <<"|    ||    ||    |"<< endl;
        cout <<"|____||____||____|"<<endl;
        cout <<"  01    02    03 "<<endl;
        break;
    case 4:
        cout <<"|    ||    ||    ||    |"<< endl;
        cout <<"|____||____||____||____|"<<endl;
        cout <<"  01    02    03    04  "<<endl;
        break;
    case 5:
        cout <<"|    ||    ||    ||    ||    |"<< endl;
        cout <<"|____||____||____||____||____|"<<endl;
        cout <<"  01    02    03    04    05"<<endl;
        break;
    case 6:
        cout <<"|    ||    ||    ||    ||    ||    |"<< endl;
        cout <<"|____||____||____||____||____||____|"<<endl;
        cout <<"  01    02    03    04    05    06"<<endl;
        break;
    case 7:
        cout <<"|    ||    ||    ||    ||    ||    ||    |"<< endl;
        cout <<"|____||____||____||____||____||____||____|"<<endl;
        cout <<"  01    02    03    04    05    06    07"<<endl;
        break;
    case 8:
        cout <<"|    ||    ||    ||    ||    ||    ||    ||    |"<< endl;
        cout <<"|____||____||____||____||____||____||____||____|"<<endl;
        cout <<"  01    02    03    04    05    06    07    08"<<endl;
        break;
    case 9:
        cout <<"|    ||    ||    ||    ||    ||    ||    ||    ||    |"<< endl;
        cout <<"|____||____||____||____||____||____||____||____||____|"<<endl;
        cout <<"  01    02    03    04    05    06    07    08    09"<<endl;
        break;
    case 10:
        cout <<"|    ||    ||    ||    ||    ||    ||    ||    ||    ||    |"<< endl;
        cout <<"|____||____||____||____||____||____||____||____||____||____|"<<endl;
        cout <<"  01    02    03    04    05    06    07    08    09    10"<<endl;
        break;
    case 11:
        cout <<"|    ||    ||    ||    ||    ||    ||    ||    ||    ||    ||    |"<< endl;
        cout <<"|____||____||____||____||____||____||____||____||____||____||____|"<<endl;
        cout <<"  01    02    03    04    05    06    07    08    09    10    11"<<endl;
        break;
    case 12:
        cout <<"|    ||    ||    ||    ||    ||    ||    ||    ||    ||    ||    ||    |"<< endl;
        cout <<"|____||____||____||____||____||____||____||____||____||____||____||____|"<<endl;
        cout <<"  01    02    03    04    05    06    07    08    09    10    11    12"<<endl;
        break;
    case 13:
        cout <<"|    ||    ||    ||    ||    ||    ||    ||    ||    ||    ||    ||    ||    |"<< endl;
        cout <<"|____||____||____||____||____||____||____||____||____||____||____||____||____|"<<endl;
        cout <<"  01    02    03    04    05    06    07    08    09    10    11    12    13"<<endl;
        break;
    case 14:
        cout <<"|   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   |"<< endl;
        cout <<"|___||___||___||___||___||___||___||___||___||___||___||___||___||___|"<<endl;
        cout <<" 01   02   03   04   05   06   07   08   09   10   11   12   13   14"<<endl;
        break;
    case 15:
        cout <<"|   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   |"<< endl;
        cout <<"|___||___||___||___||___||___||___||___||___||___||___||___||___||___||___|"<<endl;
        cout <<" 01   02   03   04   05   06   07   08   09   10   11   12   13   14   15"<<endl;
        break;
    }
}

void milieuCarte(int nombreCarte, joueur& j)
{
    int i=0, cpt=0, pos=1;;
    string c, k, t, p;
    c="\xE2\x99\xA5";   // met les caracteres utf-8 afin d'avoir les petites images dans le terminal.
    k="\xE2\x99\xA6";
    t="\xE2\x99\xA3";
    p="\xE2\x99\xA0";           
    if (nombreCarte>=14)  // affichage des mileiu cartes lorsque les largeurs des cartes sont plus petites
    {
        for(i=0; i<nombreCarte; i++)
        {
            switch(j.getValeurGraphique(cpt))
            {
            case 0:
                i=i-1;
                cpt++;
                break;
            case 1:
                cout << "|As"<< c << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 2:
                cout << "|2 "<< c << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 3:
                cout << "|3 "<< c << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 4:
                cout << "|4 "<< c << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 5:
                cout << "|5 "<< c << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 6:
                cout << "|6 "<< c << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 7:
                cout << "|7 "<< c << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 8:
                cout << "|8 "<< c << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 9:
                cout << "|9 "<< c << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 10:
                cout << "|10"<< c << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 11:
                cout << "|J "<< c << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 12:
                cout << "|Q "<< c << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 13:
                cout << "|R "<< c << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 14:
                cout << "|As"<< k << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 15:
                cout << "|2 "<< k << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 16:
                cout << "|3 "<< k << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 17:
                cout << "|4 "<< k << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 18:
                cout << "|5 "<< k << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 19:
                cout << "|6 "<< k << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 20:
                cout << "|7 "<< k << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 21:
                cout << "|8 "<< k << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 22:
                cout << "|9 "<< k << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 23:
                cout << "|10"<< k << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 24:
                cout << "|J "<< k << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 25:
                cout << "|Q "<< k << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 26:
                cout << "|R "<< k << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 27:
                cout << "|As"<< t << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 28:
                cout << "|2 "<< t << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 29:
                cout << "|3 "<< t << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 30:
                cout << "|4 "<< t << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 31:
                cout << "|5 "<< t << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 32:
                cout << "|6 "<< t << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;

                break;
            case 33:
                cout << "|7 "<< t << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 34:
                cout << "|8 "<< t << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 35:
                cout << "|9 "<< t << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 36:
                cout << "|10"<< t << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 37:
                cout << "|J "<< t << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 38:
                cout << "|Q "<< t << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 39:
                cout << "|R "<< t << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 40:
                cout << "|As"<< p << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 41:
                cout << "|2 "<< p << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 42:
                cout << "|3 "<< p << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 43:
                cout << "|4 "<< p << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 44:
                cout << "|5 "<< p << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 45:
                cout << "|6 "<< p << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 46:
                cout << "|7 "<< p << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 47:
                cout << "|8 "<< p << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 48:
                cout << "|9 "<< p << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 49:
                cout << "|10"<< p << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 50:
                cout << "|J "<< p << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 51:
                cout << "|Q "<< p << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 52:
                cout << "|R "<< p << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            }
        }
    }
    else  // affichage milieu pour les cartes plus large
    {
        for(i=0; i<nombreCarte; i++)
        {
            switch(j.getValeurGraphique(cpt))
            {
            case 0:
                i--;
                cpt++;
                break;
            case 1:
                cout << "| As"<< c << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 2:
                cout << "| 2 "<< c << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 3:
                cout << "| 3 "<< c << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 4:
                cout << "| 4 "<< c << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 5:
                cout << "| 5 "<< c << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 6:
                cout << "| 6 "<< c << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 7:
                cout << "| 7 "<< c << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 8:
                cout << "| 8 "<< c << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 9:
                cout << "| 9 "<< c << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 10:
                cout << "| 10"<< c << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 11:
                cout << "| J "<< c << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 12:
                cout << "| Q "<< c << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 13:
                cout << "| R "<< c << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 14:
                cout << "| As"<< k << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 15:
                cout << "| 2 "<< k << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 16:
                cout << "| 3 "<< k << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 17:
                cout << "| 4 "<< k << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 18:
                cout << "| 5 "<< k << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 19:
                cout << "| 6 "<< k << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 20:
                cout << "| 7 "<< k << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 21:
                cout << "| 8 "<< k << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 22:
                cout << "| 9 "<< k << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 23:
                cout << "| 10"<< k << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 24:
                cout << "| J "<< k << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 25:
                cout << "| Q "<< k << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 26:
                cout << "| R "<< k << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 27:
                cout << "| As"<< t << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 28:
                cout << "| 2 "<< t << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 29:
                cout << "| 3 "<< t << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 30:
                cout << "| 4 "<< t << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 31:
                cout << "| 5 "<< t << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 32:
                cout << "| 6 "<< t << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 33:
                cout << "| 7 "<< t << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 34:
                cout << "| 8 "<< t << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 35:
                cout << "| 9 "<< t << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 36:
                cout << "| 10"<< t << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 37:
                cout << "| J "<< t << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 38:
                cout << "| Q "<< t << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 39:
                cout << "| R "<< t << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 40:
                cout << "| As"<< p << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 41:
                cout << "| 2 "<< p << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 42:
                cout << "| 3 "<< p << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 43:
                cout << "| 4 "<< p << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 44:
                cout << "| 5 "<< p << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 45:
                cout << "| 6 "<< p << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 46:
                cout << "| 7 "<< p << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 47:
                cout << "| 8 "<< p << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 48:
                cout << "| 9 "<< p << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 49:
                cout << "| 10"<< p << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 50:
                cout << "| J "<< p << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 51:
                cout << "| Q "<< p << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            case 52:
                cout << "| R "<< p << "|";
                j.setIndiceCarteGraphique(cpt, pos);
                pos++;
                cpt++;
                break;
            }
        }
    }
    cout << endl;
}

void plateau(joueur tab[], int nbreJoueur)
{
  cin.clear();
    string c, k, t, p;
    c="\xE2\x99\xA5";   // met les caracteres ascii afin d'avoir les petites images dans le terminal.
    k="\xE2\x99\xA6";
    t="\xE2\x99\xA3";
    p="\xE2\x99\xA0";
    int i=0;
    // c'est pas joli joli, mais c'est mieux dans le terminal ...
    cout<< " ________________________________________________     "<<endl;
    cout<< "|   _________                     _________      |     argent : "<<endl;
    cout<< "|  |         |                   |         |     |    "<<endl;
    cout<< "|  | "<<c<<"       |                   | "<<p<<"       |     |    ";if(i<nbreJoueur){cout << tab[i].getNom()<<" - "<<tab[i].getArgent();i++;}; cout<<endl;
    cout<< "|  |         |                   |         |     |    ";if(i<nbreJoueur){cout << tab[i].getNom()<<" - "<<tab[i].getArgent();i++;}; cout<<endl;
    cout<< "|  |    R    |                   |    Q    |     |    "<<endl;
    cout<< "|  |         |                   |         |     |    ";if(i<nbreJoueur){cout << tab[i].getNom()<<" - "<<tab[i].getArgent();i++;}; cout<<endl;
    cout<< "|  |         |                   |         |     |    "<<endl;
    cout<< "|  |       "<<c<<" |                   |       "<<p<<" |     |    ";if(i<nbreJoueur){cout << tab[i].getNom()<<" - "<<tab[i].getArgent();i++;}; cout<<endl;
    cout<< "|  |_________|                   |_________|     |    "<<endl;
    cout<< "|                                                |    ";if(i<nbreJoueur){cout << tab[i].getNom()<<" - "<<tab[i].getArgent();i++;}; cout<<endl;
    cout<< "|                  _________                     |    "<<endl;
    cout<< "|                 |         |                    |    ";if(i<nbreJoueur){cout << tab[i].getNom()<<" - "<<tab[i].getArgent();i++;}; cout<<endl;
    cout<< "|                 | "<<k<<"       |                    |"<<endl;
    cout<< "|                 |         |                    |    ";if(i<nbreJoueur){cout << tab[i].getNom()<<" - "<<tab[i].getArgent();i++;}; cout<<endl;
    cout<< "|                 |    7    |                    |    ";if(i<nbreJoueur){cout << tab[i].getNom()<<" - "<<tab[i].getArgent();i++;}; cout<<endl;
    cout<< "|                 |         |                    |"<<endl;i=0;
    cout<< "|                 |         |                    |    nombre de carte :"<<endl;
    cout<< "|                 |       "<<k<<" |                    |"<<endl;
    cout<< "|                 |_________|                    |   "; if(i<nbreJoueur){cout << tab[i].getNom()<<" - "<<tab[i].getNombre();i++;};cout<<endl;
    cout<< "|                                                |   "<<endl;
    cout<< "|                                                |   ";if(i<nbreJoueur){cout << tab[i].getNom()<<" - "<<tab[i].getNombre();i++;};cout<<endl;
    cout<< "|   _________                     _________      |   "<<endl;
    cout<< "|  |         |                   |         |     |   ";if(i<nbreJoueur){cout << tab[i].getNom()<<" - "<<tab[i].getNombre();i++;};cout<<endl;
    cout<< "|  | "<<k<<"       |                   | "<<t<<"       |     |"<<endl;
    cout<< "|  |         |                   |         |     |   ";if(i<nbreJoueur){cout << tab[i].getNom()<<" - "<<tab[i].getNombre();i++;};cout<<endl;
    cout<< "|  |         |                   |         |     | "<<endl;
    cout<< "|  |    10   |                   |    J    |     |   ";if(i<nbreJoueur){cout << tab[i].getNom()<<" - "<<tab[i].getNombre();i++;};cout<<endl;
    cout<< "|  |         |                   |         |     |   ";if(i<nbreJoueur){cout << tab[i].getNom()<<" - "<<tab[i].getNombre();i++;};cout<<endl;
    cout<< "|  |       "<<k<<" |                   |       "<<t<<" |     |"<<endl;
    cout<< "|  |_________|                   |_________|     |   ";if(i<nbreJoueur){cout << tab[i].getNom()<<" - "<<tab[i].getNombre();i++;};cout<<endl;
    cout<< "|________________________________________________|   ";if(i<nbreJoueur){cout << tab[i].getNom()<<" - "<<tab[i].getNombre();i++;};cout<<endl;
};


void affichActu(carte actuel)
{
    string c, k, t, p;
    c="\xE2\x99\xA5";   // met les caracteres utf-8 afin d'avoir les petites images dans le terminal.
    k="\xE2\x99\xA6";
    t="\xE2\x99\xA3";
    p="\xE2\x99\xA0";
    cout <<" ____"<<endl;          //affichage du haut de la carte
    cout <<"|    |"<< endl;
    cout <<"|    |"<< endl;
    switch(actuel.getValeurGraph()) //affichage du milieu de la carte
    {
    case 0:
        cout << "| 0  |";
        break;
    case 1:
        cout << "| As"<< c << "|";
        break;
    case 2:
        cout << "| 2 "<< c << "|";
        break;
    case 3:
        cout << "| 3 "<< c << "|";
        break;
    case 4:
        cout << "| 4 "<< c << "|";
        break;
    case 5:
        cout << "| 5 "<< c << "|";
        break;
    case 6:
        cout << "| 6 "<< c << "|";
        break;
    case 7:
        cout << "| 7 "<< c << "|";
        break;
    case 8:
        cout << "| 8 "<< c << "|";
        break;
    case 9:
        cout << "| 9 "<< c << "|";
        break;
    case 10:
        cout << "| 10"<< c << "|";
        break;
    case 11:
        cout << "| J "<< c << "|";
        break;
    case 12:
        cout << "| Q "<< c << "|";
        break;
    case 13:
        cout << "| R "<< c << "|";
        break;
    case 14:
        cout << "| As"<< k << "|";
        break;
    case 15:
        cout << "| 2 "<< k << "|";
        break;
    case 16:
        cout << "| 3 "<< k << "|";
        break;
    case 17:
        cout << "| 4 "<< k << "|";
        break;
    case 18:
        cout << "| 5 "<< k << "|";
        break;
    case 19:
        cout << "| 6 "<< k << "|";
        break;
    case 20:
        cout << "| 7 "<< k << "|";
        break;
    case 21:
        cout << "| 8 "<< k << "|";
        break;
    case 22:
        cout << "| 9 "<< k << "|";
        break;
    case 23:
        cout << "| 10"<< k << "|";
        break;
    case 24:
        cout << "| J "<< k << "|";
        break;
    case 25:
        cout << "| Q "<< k << "|";
        break;
    case 26:
        cout << "| R "<< k << "|";
        break;
    case 27:
        cout << "| As"<< t << "|";
        break;
    case 28:
        cout << "| 2 "<< t << "|";
        break;
    case 29:
        cout << "| 3 "<< t << "|";
        break;
    case 30:
        cout << "| 4 "<< t << "|";
        break;
    case 31:
        cout << "| 5 "<< t << "|";
        break;
    case 32:
        cout << "| 6 "<< t << "|";
        break;
    case 33:
        cout << "| 7 "<< t << "|";
        break;
    case 34:
        cout << "| 8 "<< t << "|";
        break;
    case 35:
        cout << "| 9 "<< t << "|";
        break;
    case 36:
        cout << "| 10"<< t << "|";
        break;
    case 37:
        cout << "| J "<< t << "|";
        break;
    case 38:
        cout << "| Q "<< t << "|";
        break;
    case 39:
        cout << "| R "<< t << "|";
        break;
    case 40:
        cout << "| As"<< p << "|";
        break;
    case 41:
        cout << "| 2 "<< p << "|";
        break;
    case 42:
        cout << "| 3 "<< p << "|";
        break;
    case 43:
        cout << "| 4 "<< p << "|";
        break;
    case 44:
        cout << "| 5 "<< p << "|";
        break;
    case 45:
        cout << "| 6 "<< p << "|";
        break;
    case 46:
        cout << "| 7 "<< p << "|";
        break;
    case 47:
        cout << "| 8 "<< p << "|";
        break;
    case 48:
        cout << "| 9 "<< p << "|";
        break;
    case 49:
        cout << "| 10"<< p << "|";
        break;
    case 50:
        cout << "| J "<< p << "|";
        break;
    case 51:
        cout << "| Q "<< p << "|";
        break;
    case 52:
        cout << "| R "<< p << "|";
        break;
    }
    cout <<endl;
    cout <<"|    |"<< endl; // affichage de la fin de la carte
    cout <<"|____|"<<endl;
};

void affichage(carte actuel, joueur tableauJou[], int nbreJoueur, int indice)
{
    plateau(tableauJou,nbreJoueur);  // affiche le plateau
    cout <<endl<<endl<< "la carte actuelle est : "<<endl ;
    affichActu(actuel); // affichage de la carte actuelle
    cout<< tableauJou[indice%nbreJoueur].getNom()<<endl; // affichage du nom du joueur à jouer
    hautCartes(tableauJou[indice%nbreJoueur].getNombre()); // affichage du haut, du milieu et de fin des cartes que possede le joueur
    milieuCarte(tableauJou[indice%nbreJoueur].getNombre(), tableauJou[indice%nbreJoueur]);
    finCarte(tableauJou[indice%nbreJoueur].getNombre());
}


