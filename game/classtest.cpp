#include <iostream>
#include "player.h"
#include "weapons.h"
#include "logbook.h"
#include "planet.h"
#include <cassert>
using namespace std;

int main()
{
    Player carter;
    assert(carter.getmoney() == 100000);
    assert(carter.gethealthPercent() == 100);
    assert(carter.getsuitPercent() == 100);
    assert(carter.getfuel() == 200000);
    assert(carter.getsuitGrade() == 1);
    assert(carter.getmedKits() == 0);
    assert(carter.getcurrentWeapon() == 0);
    carter.takeDamage(10, 10);
    assert(carter.gethealthPercent() == 90);
    assert(carter.getsuitPercent() == 90);
    assert(carter.addmedKit(6) == -1);
    assert(carter.getWeaponstatus() == true);
    carter.addmedKit(5);
    carter.loseFight();
    assert(carter.getWeaponstatus() == false);
    assert(carter.gethealthPercent() == 100);
    Weapons sword;
    assert(sword.getStatus() == false);
    sword.getWeapon();
    assert(sword.getStatus() == true);
    carter.repairSuit();
    assert(carter.getsuitPercent() == 50);
    carter.weatherStorm();
    assert(carter.gethealthPercent() == 90);
    assert(carter.getsuitPercent() == 10);
    carter.repairSuit();
    carter.repairSuit();
    assert(carter.getsuitPercent() == 90);
    carter.crater();
    assert(carter.gethealthPercent() == 80);
    assert(carter.getsuitPercent() == 50);
    carter.spaceSickness();
    assert(carter.gethealthPercent() == 90);
    Planet earth;
    cout << earth.getSize() << endl;
    cout << earth.getCapacity() << endl;
    cout << earth.getName() << endl;
    cout << earth.getHabitable() << endl;
    cout << earth.getAssessment() << endl;
}