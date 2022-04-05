#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "weapons.h"
using namespace std;

class player
{
private:
    int money;
    int healthPercent;
    int suitPercent;
    int fuel;
    int suitGrade;
    int medKits;
    bool translator;
    weapons guns[3];
    int currentWeapon;
    bool alive;
public:
    player();
    int getmoney();
    int gethealthPercent();
    int getsuitPercent();
    int getfuel();
    int getsuitGrade();
    int getmedKits();
    int getcurrentWeapon();
    //health
    void takeDamage(int health, int suit);
    void playerDied();
    //battle
    int loseFight();
    int winFight();
    void forfeit();
    //misfortune
    void weatherStorm();
    void crater();
    void spaceSickness();
    //misc
    void changePlanet();
    void usemedKit();
};
#endif