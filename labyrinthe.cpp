#include <vector>
#include "labyrinthe.h"
 
// COMPILER avec la commande: g++ Gasp.cpp -lncurses -std=c++11
 
 
Labyrinthe::Labyrinthe (int l, int h) { 
    A = new char[l*h];
    for (int i=0; i<30; i++) { 
        for (int j=0; j<30; j++) { 
            A[i+j*30]=' ';}
        ;} 
    ;};
 
void Labyrinthe::create_salle (int x, int y, int lon, int haut) {
   for (int i = 0; i <= lon-1; i+=1) {
       A[x+i+(y)*30]='_';
   };
   for (int i = 1; i <= lon-2; i+=1) {
       A[x+i+30*(y+haut-1)]='_';
   };
   for (int i=1; i<= haut-1; i+=1) {
       A[x+(y+i)*30]='|';
       A[(y+i)*30+(x+lon-1)]='|';
   }
   for (int i =1; i<lon-1;i+=1) {
       for (int j=1; j<haut-1; j+=1) {
           A[x+i+(y+j)*30]='.';
       }
   }};
//void afficher () {
//    for (int i= 0, i<30, i+=1) {
//    }
 
void Labyrinthe :: create_couloir (int x, int y, std::vector<int> B) {
    A[x+y*30]='+';
    //std::vector<int>::iterator it;
    //for (it::B) {
   for (auto it = B.cbegin(); it != B.cend(); it++) {
        if (*it==0) {
            x-=1;}
        if (*it==1) {y+=1;}
        if (*it==2) {y-=1;}
        if (*it==3) {x+=1;};
        A[x+30*y]='#';
    }; };