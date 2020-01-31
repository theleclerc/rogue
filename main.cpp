#include <iostream>
// #include "touslesh.h"
#include "personnage.h"
#include <ncurses.h>
#include "labyrinthe.h"
#include <cstdlib>
#include <vector>


void imprime(Labyrinthe carte) {
   wmove(stdscr,0, 0);
    for (int i=0; i<30; i++) {
        for (int b=0; b<30; b++){
            waddch(stdscr, carte.A[b+30*i]);
        }
        wmove(stdscr,i+1,0);
    }
    wrefresh(stdscr);
};

int main() {
   initscr();
    Labyrinthe carte (30,30);
   std::vector<int> couloir1 = {3,3,3,3,3,3,2,2,3,3,1,1,1};
   std::vector<int> couloir2 = {3,1,1,1,1,1,0};
   std::vector<int> couloir3 = {1,1,1,3,3,3,1,1,1,0,0,0,2,2,2,0,0,1,1,1,1,1,1,1,3,3,3,3,3,3,3};
   std::vector<int> couloir4 = {1,1,1,1,0,0,0,1,3,1,3,1};
   std::vector<int> couloir5 = {0,0,0,0,1,3,0,1,1,0,1,1,3,3,1,1,0,0,0,0};
   std::vector<int> couloir6 = {0,1,1,1,1,1,1};
 
 
 
   carte.create_salle(1,1, 10, 5);
   carte.create_salle(15,5,10,7);
   carte.create_salle(23,20,6,7);
   carte.create_salle(4,12,5,8);
   carte.create_salle(1,25,5,4);
 
   carte.create_couloir(10, 4, couloir1);
   carte.create_couloir(24, 6, couloir2);
   carte.create_couloir(19, 11, couloir3);
   carte.create_couloir(8, 5, couloir4);
   carte.create_couloir(15, 10, couloir5);
   carte.create_couloir(5, 19, couloir6);
    noecho();
    imprime(carte);
    int ch;
    Sac sac;
    keypad(stdscr, TRUE);
    Personnage P = Personnage(30,2,2,10,sac);
    wmove(stdscr,2,2);
    waddch(stdscr,'@');
    wmove(stdscr,2,2);
    wrefresh(stdscr);
    while(true) {
        ch=getch();
        switch (ch) {
          case 'q': 
             return 0;
             break;
          case '?':
             //Affiche l'aide
             break;
          case KEY_UP: if ((carte.A[P.posix() + 30*(P.posiy()-1)] == '.') or (carte.A[P.posix() + 30*(P.posiy()-1)] == '+') or ((carte.A[P.posix() + 30*(P.posiy()-1)] == '#'))) {P.up();}
             //Le perso va en haut
             break;
          case KEY_DOWN:  if ((carte.A[P.posix() + 30*(P.posiy()+1)] == '.')or(carte.A[P.posix() + 30*(P.posiy()+1)] == '+') or(carte.A[P.posix() + 30*(P.posiy()+1)] == '#')) {P.down();}
             //Le perso va en bas
             break;
          case KEY_LEFT:  if ((carte.A[P.posix()-1 + 30*(P.posiy())] == '.')or(carte.A[P.posix()-1 + 30*(P.posiy())] == '+')or (carte.A[P.posix()-1 + 30*(P.posiy())] == '#')) {P.left();}
             //Le perso va à gauche
             break;
          case KEY_RIGHT:   if ((carte.A[P.posix()+1 + 30*(P.posiy())] == '.')or (carte.A[P.posix()+1 + 30*(P.posiy())] == '+')or(carte.A[P.posix()+1 + 30*(P.posiy())] == '#')) {P.right();}
             //Le perso va à droite
             break;
          case KEY_BACKSPACE: endwin(); return 0;
             //Le perso tape
             break;
          case '>':
             //Le perso monte un escalier
             break;
          case '<':
             //Le perso descend un escalier
             break;
          case 'j':
             //Le perso boit une potion
             break;
          case 'e':
             //Le perso mange
             break;
          case 'f':
             //Le perso équipe quelque chose
             break;
          default: 
             mvprintw(0,0,"Commande inconnue");
             break;
    }
    imprime(carte);
    wmove(stdscr,P.posiy(),P.posix()); 
    waddch(stdscr,'@');
    wmove(stdscr,P.posiy(),P.posix());
    wrefresh(stdscr);
 
    }
    endwin();
    }
 
 
 
 

