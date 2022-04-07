#include "weapons.h"
using namespace std;

Weapons::Weapons()
{
    damage = 0;
    range = 0;
    owned = false;
}
int Weapons::getDamage()
{
    return damage;
}
int Weapons::getRange()
{
    return range;
}
void Weapons::loseWeapon(){
    owned = false;
}
void Weapons::getWeapon(){
    owned = true;
}
void Weapons::useWeapon()
{
    // idk how combat works XD we can move this to a dif class in that makes more sense.
}
bool Weapons::getStatus(){
    return owned;
}