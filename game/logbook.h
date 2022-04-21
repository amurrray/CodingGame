#ifndef LOGBOOK_H
#define LOGBOOK_H

#include <iostream>
#include <vector>
using namespace std;

class Logbook
{
private:
    string user;
    string name[50];
    int numPages;
    int size[50];
    int capacity[50];
    vector<string> goodTraits[50];
    vector<string> badTraits[50];
    string alienAssessment[50];
    int correctHabitable;
    int incorrectHabitable;

public:
    Logbook();
    void setName(string name_);
    void newPage();
    string getName();
    void setUser(string user_);
    void setnumPages(int number);
    void addPage();
    int getnumPages();
    int getcorrectHabitable();
    int getincorrectHabitable();
    void setSize(int size_);
    void setCapacity(int capacity_);
    int getCapacity();
    int getSize();
    void addGoodTrait(string trait);
    void addBadTrait(string trait);
    void setalienAssessment(string assessment_);
    void printPage(int pageIndex);
};
#endif