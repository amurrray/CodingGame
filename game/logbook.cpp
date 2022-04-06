#include "logbook.h"
using namespace std;

logbook::Logbook(){
    pageNumber = 0;
    size = 0;
    capacity = 0;
    alienAssessment = "None";
}
void logbook::setName(string name_){
    name = name_;
}
void logbook::setUser(string user_){
    user = user_;
}
void logbook::setpageNumber(int number){
    pageNumber = number;
}
void logbook::setSize(int size_){
    size = size_;
}
void logbook::setCapacity(int capacity_){
    capacity = capacity_;
}
void logbook::addGoodTrait(string trait){
    goodTraits.push_back(trait);
}
void logbook::addBadTrait(string trait){
    badTraits.push_back(trait);
}
void logbook::setalienAssessment(string assessment_){
    alienAssessment = assessment_;
}
void logbook::printPage(){
    cout << user << "'s Log Book page #" << pageNumber << ": Planet " << name << endl;
    cout << "Planet size (in diameter of 1000 kms): " << size << endl;
    cout << "Planet's carrying capacity (in millions): " << capacity << endl;
    cout << "Habitable traits discovered: ";
    if (goodTraits.size() < 1){
        cout << "None" << endl;
    }
    else{
        for (int i = 0; i < goodTraits.size(); i++){
        cout << goodTraits[i];
        }
        cout << endl;
    } 
    
    cout << "Non-habitable traits discovered: ";
    if (badTraits.size() < 1){
        cout << "None" << endl;
    }
    else{
        for (int i = 0; i < badTraits.size(); i++){
            cout << badTraits[i];
        }
        cout << endl;
    }
    cout << "Friends=ly alien assessment: " << alienAssessment << endl;
}