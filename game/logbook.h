#ifndef LOGBOOK_H
#define LOGBOOK_H

#include <iostream>
#include <vector>
using namespace std;

class Logbook
{
private:
    string user;
    string name;
    int pageNumber;
    int size;
    int capacity;
    vector<string> goodTraits;
    vector<string> badTraits;
    string alienAssessment;

public:
    Logbook();
    void setName(string name_);
    void setUser(string user_);
    void setpageNumber(int number);
    void setSize(int size_);
    void setCapacity(int capacity_);
    void addGoodTrait(string trait);
    void addBadTrait(string trait);
    void setalienAssessment(string assessment_);
    void printPage();
};
#endif