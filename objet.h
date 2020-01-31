#ifndef OBJET_H
#define OBJET_H

#include <iostream>
#include <string>

class Objet {
protected:
    std::string nom;
    Objet () : nom("objet non défini") {};
    Objet (std::string name) : nom(name) {};
};

class Gold : public Objet{
private:
    int valeur;
public:
    Gold() : Objet("or") {valeur = 0;};
    Gold(int n) : Objet ("or") {valeur = n;};
    friend Gold operator+ (Gold self, Gold other) {
        Gold somme = Gold(self.valeur + other.valeur);
        return somme;
    };
};

class Potion : public Objet {
private:
    int guerison;
    int renforcement;
    float etourdissement;
public:
    Potion(std::string couleur, int guerit, int renforce, float etourdit) : Objet("potion " + couleur) {
        guerison = guerit;
        renforcement = renforce;
        etourdissement = etourdit;
    };

    Potion(std::string couleur) {
        if (couleur == "orange") {
                Potion("orange", 0, 2, 1);
                }
        else if (couleur == "blue") {
                Potion("blue", -1, 5, 1.2);
                }
        else if (couleur == "green") {
                Potion("green", 5, 0, 1);
                }
        else if (couleur == "brown")
        {
            Potion("brown", 3, 3, 0.5);
        }
        
    };
};

class Food : public Objet {
private:
    int rations;
public:
    Food() : Objet("Nourriture") {rations = 0;};
    
    Food(int n) : Objet("Nourriture") {rations = n;};
    
    friend Food operator+ (Food self, Food other) {
        return Food(self.rations + other.rations);
    };

    bool consommer() {if (rations >0) {rations--; return true;} else {return false;};};
};


#endif