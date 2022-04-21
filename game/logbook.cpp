#include "logbook.h"
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Logbook::Logbook()
{
    numPages = -1;
    correctHabitable = 0;
    incorrectHabitable = 0;
}
void Logbook::setName(string name_)
{
    name[numPages] = name_;
}
void Logbook::newPage()
{
    numPages = numPages + 1;
    size[numPages] = rand() % 15 + 2;
    // cout << size[numPages] << endl;
    size[numPages] = size[numPages] / 2;
    capacity[numPages] = size[numPages] * 615;
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
    name[numPages] = name_;
}
string Logbook::getName()
{
    return name[numPages];
}
void Logbook::setUser(string user_)
{
    user = user_;
}
void Logbook::setnumPages(int number)
{
    numPages = number;
}
void Logbook::addPage()
{
    numPages = numPages + 1;
}
int Logbook::getnumPages()
{
    return numPages;
}
int Logbook::getcorrectHabitable()
{
    return correctHabitable;
}
int Logbook::getincorrectHabitable()
{
    return incorrectHabitable;
}
void Logbook::setSize(int size_)
{
    size[numPages] = size_;
}
int Logbook::getSize()
{
    return size[numPages];
}
void Logbook::setCapacity(int capacity_)
{
    capacity[numPages] = capacity_;
}
int Logbook::getCapacity()
{
    return capacity[numPages];
}
void Logbook::addGoodTrait(string trait)
{
    goodTraits[numPages].push_back(trait);
}
void Logbook::addBadTrait(string trait)
{
    badTraits[numPages].push_back(trait);
}
void Logbook::setalienAssessment(string assessment_)
{
    alienAssessment[numPages] = assessment_;
}
void Logbook::printPage(int pageIndex)
{
    cout << user << "'s Log Book page #" << pageIndex + 1 << ": Planet " << name[pageIndex] << endl;
    cout << "Planet size (in diameter of 1000 kms): " << size[pageIndex] << endl;
    cout << "Planet's carrying capacity (in millions): " << capacity[pageIndex] << endl;
    cout << "Habitable traits discovered: ";
    if (goodTraits[pageIndex].size() < 1)
    {
        cout << "None" << endl;
    }
    else
    {
        for (int i = 0; i < goodTraits[pageIndex].size(); i++)
        {
            cout << goodTraits[pageIndex][i];
        }
        cout << endl;
    }

    cout << "Non-habitable traits discovered: ";
    if (badTraits[pageIndex].size() < 1)
    {
        cout << "None" << endl;
    }
    else
    {
        for (int i = 0; i < badTraits[pageIndex].size(); i++)
        {
            cout << badTraits[pageIndex][i];
        }
        cout << endl;
    }
    cout << "Friendly alien assessment: " << alienAssessment[pageIndex] << endl;
}