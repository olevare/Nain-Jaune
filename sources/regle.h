#ifndef regle_h
#define regle_h

using namespace std;


void prendreMise(joueur*,int); // prend les mises de d�part � tous les joueurs
void gainPartie(joueur*,  int,int); // articule la fonction � la fin d'une manche afin de faire payer la somme d� au gagnant, par les perdnats
void gainCarte(joueur&, carte&, int); // donne la mise d'une carte pos� par un joueur humain
void help(); // message d'aide

#endif
