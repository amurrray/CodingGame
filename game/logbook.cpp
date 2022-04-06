#include "logbook.h"
using namespace std;

Logbook::Logbook()
{
    pageNumber = 0;
    size = 0;
    capacity = 0;
    alienAssessment = "None";
}
void Logbook::setName(string name_)
{
    name = name_;
}
void Logbook::setUser(string user_)
{
    user = user_;
}
void Logbook::setpageNumber(int number)
{
    pageNumber = number;
}
void Logbook::setSize(int size_)
{
    size = size_;
}
void Logbook::setCapacity(int capacity_)
{
    capacity = capacity_;
}
void Logbook::addGoodTrait(string trait)
{
    goodTraits.push_back(trait);
}
void Logbook::addBadTrait(string trait)
{
    badTraits.push_back(trait);
}
void Logbook::setalienAssessment(string assessment_)
{
    alienAssessment = assessment_;
}
void Logbook::printPage()
{
    cout << user << "'s Log Book page #" << pageNumber << ": Planet " << name << endl;
    cout << "Planet size (in diameter of 1000 kms): " << size << endl;
    cout << "Planet's carrying capacity (in millions): " << capacity << endl;
    cout << "Habitable traits discovered: ";
    if (goodTraits.size() < 1)
    {
        cout << "None" << endl;
    }
    else
    {
        for (int i = 0; i < goodTraits.size(); i++)
        {
            cout << goodTraits[i];
        }
        cout << endl;
    }

    cout << "Non-habitable traits discovered: ";
    if (badTraits.size() < 1)
    {
        cout << "None" << endl;
    }
    else
    {
        for (int i = 0; i < badTraits.size(); i++)
        {
            cout << badTraits[i];
        }
        cout << endl;
    }
    cout << "Friends=ly alien assessment: " << alienAssessment << endl;
}