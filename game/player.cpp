#include "player.h"
#include "weapons.h"
using namespace std;
player::player(){
    money = 100000;
    healthPercent = 100;
    suitPercent = 100;
    fuel = 200000;
    suitGrade = 1;
    medKits = 0;
    translator = false;
    guns[0] = lightsaber;
    currentWeapon = 0;
    alive = true;
}
int player::getmoney(){
    return money;
}
int player::gethealthPercent(){
    return healthPercent;
}
int player::getsuitPercent(){
    return suitPercent;
}
int player::getfuel(){
    return fuel;
}
int player::getsuitGrade(){
    return suitGrade;
}
int player::getmedKits(){
    return medKits;
}
int player::getcurrentWeapon(){
    return currentWeapon;
}
//health
void player::takeDamage(int health, int suit){
    healthPercent = healthPercent - health;
    suitPercent = suitPercent - suit;
    usemedKit():
    if ((healthPercent <= 0) || (suitPercent <= 0)){
        playerDied();
    }
}
void player::playerDied(){
    alive = false;
}
//battle
int player::loseFight(){
    takeDamage(30, (100 - (20 * suitGrade)));
    guns[currentWeapon] = none;
}
int player::winFight(){
    money = money + 200;
    takeDamage(0, 10);
}
void player::forfeit(){
    guns[currentWeapon] = none;
}
//misfortune
void player::weatherStorm(){
    takeDamage(10, 50 -(10 * suitGrade));
}
void player::crater(){
    takeDamage(50, 50 - (10 * suitGrade));
}
void player::spaceSickness(){
    takeDamage(30, 0);
}
//misc
void player::changePlanet(){

}
void player::usemedKit(){
    if ((healthPercent <= 60) && (medKits >= 1)){
        medKits = medKits - 1;
        healthPercent = healthPercent + 40;
    }
}
