#include "player.h"
#include <iostream>
#include "weapons.h"
using namespace std;
Player::Player()
{
    Weapons lightsaber;
    money = 100000;
    healthPercent = 100;
    suitPercent = 100;
    fuel = 200000;
    suitGrade = 1;
    medKits = 0;
    translator = false;
    guns[0] = lightsaber;
    guns[0].getWeapon();
    currentWeapon = 0;
    alive = true;
    name = "";
}
int Player::getMoney()
{
    return money;
}
void Player::chargeMoney(int price)
{
    money = money - price;
}
void Player::travel(){
    fuel = fuel - 5000;
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
void Player::changecurrentWeapon(int pos)
{
    currentWeapon = pos;
}
void Player::acquireTranslator()
{
    translator = true;
}
bool Player::hasTranslator()
{
    return translator;
}
void Player::addFuel(int amount)
{
    fuel = fuel + amount;
}
// health
void Player::takeDamage(int health, int suit)
{
    cout << "Youve take damage" << endl;
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
bool Player::isAlive()
{
    return alive;
}
void Player::repairSuit()
{
    suitPercent = 100;
}
void Player::upgradeSuit(int grade)
{
    suitGrade = grade;
}
string Player::getName()
{
    return name;
}
void Player::setName(string name_)
{
    name = name_;
}
// battle
void Player::loseFight()
{
    takeDamage(30, (100 - (20 * suitGrade)));
    guns[currentWeapon].loseWeapon();
}
void Player::winFight()
{
    money = money + 200;
    takeDamage(0, 10);
}
void Player::forfeit()
{
    guns[currentWeapon].loseWeapon();
}
bool Player::getWeaponstatus(int pos)
{
    bool status = guns[pos].getStatus();
    return status;
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
void Player::addmedKit(int number)
{
    medKits = medKits + number;
}
void Player::buyWeapon(int pos)
{
    guns[pos].getWeapon();
}
