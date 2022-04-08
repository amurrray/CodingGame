#ifndef PLANET_H
#define PLANET_H

#include <iostream>
#include <vector>
using namespace std;

class Planet
{
private:
    double size;
    int capacity;
    string name;
    vector<string> habitableTraits;
    vector<string> nonHabitableTraits;
    bool isHabitable;
    bool alienAssessment;

public:
    Planet();
    double getSize();
    int getCapacity();
    string getName();
    vector<string> getHabitableTraits();
    vector<string> getNonHabitableTraits();
    bool getAssessment();
    bool getHabitable();
};
#endif