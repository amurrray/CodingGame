#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "weapons.h"
using namespace std;


class Player
{
private:
    int money;
    int healthPercent;
    int suitPercent;
    int fuel;
    int suitGrade;
    int medKits;
    bool translator;
    Weapons guns[3];
    int currentWeapon;
    bool alive;

public:
    Player();
    int getmoney();
    int gethealthPercent();
    int getsuitPercent();
    int getfuel();
    int getsuitGrade();
    int getmedKits();
    int getcurrentWeapon();
    // health
    void takeDamage(int health, int suit);
    void playerDied();
    void repairSuit();
    // battle
    void loseFight();
    void winFight();
    void forfeit();
    bool getWeaponstatus();
    // misfortune
    void weatherStorm();
    void crater();
    void spaceSickness();
    // misc
    void changePlanet();
    void usemedKit();
    int addmedKit(int number);
};
#endif