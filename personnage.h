#ifndef personnage_H
#define personnage_H
 
class Personnage {
private:
    int max_vie;
    int vie;
    int posx;
    int posy;
    //int posz;
    int force;
    //float precision;
    //float criticals;
    //int critic;
    //Sac sac;
public:
 
    Personnage (int max, int x, int y, int strength /*, Sac sad*/);
 
    void down() ;
    void up() ;
    void left() ;
    void right() ;
    int posix();
    int posiy();
    bool hit(int coup);
    void upgrade(int plus_vie, int plus_force, bool heal);
    bool wicked(int moins_vie, int moins_force, int coup);
    void cure(int guerison);
    void heal();
 
    /*int attack();*/
 
};
 
 
#endif
 
