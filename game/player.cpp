#include "player.h"
#include "weapons.h"
using namespace std;
Player::Player()
{
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
int Player::getmoney()
{
    return money;
}
int Player::gethealthPercent()
{
    return healthPercent;
}
int Player::getsuitPercent()
{
    return suitPercent;
}
int Player::getfuel()
{
    return fuel;
}
int Player::getsuitGrade()
{
    return suitGrade;
}
int Player::getmedKits()
{
    return medKits;
}
int Player::getcurrentWeapon()
{
    return currentWeapon;
}
// health
void Player::takeDamage(int health, int suit)
{
    healthPercent = healthPercent - health;
    suitPercent = suitPercent - suit;
    usemedKit();
    if ((healthPercent <= 0) || (suitPercent <= 0))
    {
        playerDied();
    }
}
void Player::playerDied()
{
    alive = false;
}
// battle
int Player::loseFight()
{
    takeDamage(30, (100 - (20 * suitGrade)));
    guns[currentWeapon] = none;
}
int Player::winFight()
{
    money = money + 200;
    takeDamage(0, 10);
}
void Player::forfeit()
{
    guns[currentWeapon] = none;
}
// misfortune
void Player::weatherStorm()
{
    takeDamage(10, 50 - (10 * suitGrade));
}
void Player::crater()
{
    takeDamage(50, 50 - (10 * suitGrade));
}
void Player::spaceSickness()
{
    takeDamage(30, 0);
}
// misc
void Player::changePlanet()
{
}
void Player::usemedKit()
{
    if ((healthPercent <= 60) && (medKits >= 1))
    {
        medKits = medKits - 1;
        healthPercent = healthPercent + 40;
    }
}
