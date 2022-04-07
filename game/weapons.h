#ifndef WEAPONS_H
#define WEAPONS_H

#include <iostream>
using namespace std;

class Weapons
{
private:
    int damage;
    int range;
    bool owned;
public:
    Weapons();
    int getDamage();
    int getRange();
    bool getStatus();
    void loseWeapon();
    void useWeapon();
    void getWeapon();
};
#endif