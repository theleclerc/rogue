#ifndef labyrinthe_H
#define labyrinthe_H
#include <vector>
 
// COMPILER avec la commande: g++ labyrinthe.cpp -lncurses -std=c++11
 
class Labyrinthe {
public:
char * A; //position désignée par A+30*b
 
Labyrinthe (int l, int h);
 
void create_salle (int x, int y, int lon, int haut);
//void afficher () {
//    for (int i= 0, i<30, i+=1) {
//    }
 
void create_couloir (int x, int y, std::vector<int> B);
 
};
#endif