#ifndef SAC_A_DOS_H
#define SAC_A_DOS_H

#include <iostream>
#include <vector>
#include "objet.h"
#include<ncurses.h>

class Sac {
private:
    Food nourriture;
    Gold argent;
    std::vector<Potion> potions;
public:
    Sac () : nourriture(Food()), argent(Gold()) {};

    void rajouter(Food manger) {
        nourriture = nourriture + manger;
    };

    void rajouter(Gold bijoux) {
        argent = argent + bijoux;
    };

    void rajouter(Potion potion) {
        potions.push_back(potion);
    };

    bool manger() {
        bool nourri = nourriture.consommer();
        return nourri;
    };

    void affiche() {};

};


#endif