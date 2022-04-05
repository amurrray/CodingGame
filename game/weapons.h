#ifndef WEAPONS_H
#define WEAPONS_H

#include <iostream>
using namespace std;

class Weapons
{
private:
    int damage;
    int range;

public:
    Weapons();
    int getDamage();
    int getRange();

};
#endif