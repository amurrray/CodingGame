#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
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

public:
    int getmoney();
    int gethealthPercent();
    int getsuitPercent();
    int getfuel();
    int getsuitGrade();
    int getmedKits();
};
#endif