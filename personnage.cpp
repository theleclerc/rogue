#include "personnage.h"
 
#include "sac_a_dos.h"

 
Personnage::Personnage (int max, int x, int y, int strength , Sac sad) {max_vie = max; vie = max_vie; posx = x; posy =y; force = strength; sac = sad;};

    void Personnage::down() {posy++;};
    void Personnage::up() {posy--;};
    void Personnage::left() {posx--;};
    void Personnage::right() {posx++;};
    int Personnage::posix() {return posx;};
    int Personnage::posiy() {return posy;};
    bool Personnage::hit(int coup) { vie -= coup; if (vie <= 0) {return true;} else {return false;}};
    void Personnage::upgrade(int plus_vie, int plus_force, bool heal) {
        max_vie += plus_vie;
        force += plus_force;
        if (heal) {vie = max_vie;};
    };
    bool Personnage::wicked(int moins_vie, int moins_force, int coup) {
        max_vie -= moins_vie;
        force -= moins_force;
        bool mort = hit(coup);
        if (vie > max_vie) {vie = max_vie;};
        return mort;
    };
    void Personnage::cure(int guerison) {
        vie += guerison;
        if (vie > max_vie) {vie = max_vie;};
    };
    void Personnage::heal() {vie = max_vie;};
    /*int Personnage::attack() {
        int r;
        r = rand() % 100;
        if (r*0.01<precision) {
            int c;
            c = rand() % 100;
            if (c<criticals) {return critic * force;}
            else {return force;};
        };
        return 0;
    };*/
 
