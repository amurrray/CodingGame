#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "weapons.h"
#include "logbook.h"
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
    string name;

public:
    Player();
    int getMoney();
    void chargeMoney(int price);
    int gethealthPercent();
    int getsuitPercent();
    int getfuel();
    int getsuitGrade();
    int getmedKits();
    int getcurrentWeapon();
    void changecurrentWeapon(int pos);
    string getName();
    void setName(string name_);
    void acquireTranslator();
    bool hasTranslator();
    void addFuel(int amount);
    // health
    void takeDamage(int health, int suit);
    void playerDied();
    bool isAlive();
    void repairSuit();
    void upgradeSuit(int grade);
    // battle
    void loseFight();
    void winFight();
    void forfeit();
    bool getWeaponstatus(int pos);
    // misfortune
    void weatherStorm();
    void crater();
    void spaceSickness();
    // misc
    void changePlanet();
    void usemedKit();
    int addmedKit(int number);
    void buyWeapon(int pos);
};
#endif