#include "planet.h"
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>

using namespace std;

Planet::Planet()
{
    srand(time(NULL));
    int rand_ = rand() % 100;
    if (rand_ >= 75)
    {
        isHabitable = true;
    }
    else
    {
        isHabitable = false;
    }
    srand(time(NULL));
    double size_ = rand() % 15 + 2;
    size_ = size_ / 2.0;
    size = size_;
    capacity = size * 615;

    string name_ = "";
    for (int i = 0; i < 6; i++)
    {
        int rando = rand() % 10;
        if (rando % 2 == 0)
        {
            name_ = name_ + to_string(rando);
        }
        else
        {
            rando = rand() % 26 + 65;
            char letter = rando;
            name_ = name_ + letter;
        }
    }
    string line = "";
    ifstream fin;
    fin.open("four_letter_words.txt");
    if (fin.is_open())
    {
        int nameNum = rand() % 3125 + 1;
        for (int i = 0; i < nameNum; i++)
        {
            getline(fin, line);
        }

        line[0] = line[0] - 32;
        name_ = name_ + "-" + line;
    }
    name = name_;
    int assessmentNum = rand() % 10 + 1;
    if (assessmentNum >= 7)
    {
        alienAssessment = isHabitable;
    }
    else
    {
        alienAssessment = !isHabitable;
    }
}

double Planet::getSize()
{
    return size;
}

int Planet::getCapacity()
{
    return capacity;
}

string Planet::getName()
{
    return name;
}

vector<string> Planet::getHabitableTraits()
{
}

vector<string> Planet::getNonHabitableTraits()
{
}

bool Planet::getAssessment()
{
    return alienAssessment;
}

bool Planet::getHabitable()
{
    return isHabitable;
}