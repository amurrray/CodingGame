#include <iostream>
#include <vector>
#include "player.h"
#include "map.h"
#include "planet.h"
#include "logbook.h"
#include "weapons.h"

using namespace std;

void createCharacter(Player steve)
{
    cout << "Enter your name:" << endl;
    string name;
    cin >> name;
    steve.setName(name);
}
void storeExplanation(){
    cout << "WEAPONS. If your weapon breaks or if you lose your weapon during an event, you may need additional weapons to defend yourself!" << endl
         << "TRANSLATOR. Allows you to communicate with friendly aliens to get their assessment of the planet and increases odds of winning against a hostile alien." << endl
         << "SPACE SUIT. The better the spacesuit, the more durable and protective you will be during the mission and an alien attack." << endl
         << "MEDICAL KITS. The more kits you have, the more times you can revive your health by 40%." << endl
         << "FUEL. Fuel is an essential element for the spacecraft to travel to more planets." << endl
         << "You can spend all of your money here before you start your journey, or you can save some to spend on different resources along the way. You will also gain money for each turn as you move through the game." << endl
         << endl;
    return;
}
void goToStore(Player steve)
{
    cout << "Your current balance is " << steve.getMoney() << endl;
    cout << "Which item do you wish to buy?" << endl;
    cout << "1. Weapon" << endl
         << "2. Translator" << endl
         << "3. Space suit" << endl
         << "4. Medical Kits" << endl
         << "5. Fuel" << endl
         << "6. Purchase and Leave" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Which weapon type do you wish to buy?" << endl;
        cout << "1. Light Saber" << endl;
        cout << "2. Blaster" << endl;
        cout << "3. Beam Gun" << endl;
        cout << "4. Go back to menu" << endl;
        int weaponChoice;
        cin >> weaponChoice;
        switch (weaponChoice)
        {
        case 1:
            if ((steve.getWeaponstatus(0) == false) && (steve.getMoney() >= 1000))
            {
                steve.buyWeapon(0);
                steve.chargeMoney(1000);
                cout << "you bought lightsaber your balance is now" << steve.getMoney() << endl;
                goToStore(steve);
            }
            else
            {
                cout << "you already have that weapon or you don't have enough money" << endl;
                goToStore(steve);
            }
            break;
        case 2:
            if ((steve.getWeaponstatus(1) == false) && (steve.getMoney() >= 2000))
            {
                steve.buyWeapon(1);
                steve.chargeMoney(2000);
                cout << "you bought Blaster your balance is now " << steve.getMoney() << endl;
                goToStore(steve);
            }
            else
            {
                cout << "you already have that weapon or you don't have enough money" << endl;
                goToStore(steve);
            }
            break;
        case 3:
            if ((steve.getWeaponstatus(2) == false) && (steve.getMoney() >= 5000))
            {
                steve.buyWeapon(2);
                steve.chargeMoney(5000);
                cout << "you bought Beam Gun your balance is now " << steve.getMoney() << endl;
                goToStore(steve);
            }
            else
            {
                cout << "you already have that weapon or you don't have enough money" << endl;
                goToStore(steve);
            }
            break;
        case 4:
            cout << "going to main shop" << endl;
            goToStore(steve);
            break;
        default:
            cout << "invalid input" << endl;
            goToStore(steve);
        }
        break;
    case 2:
        cout << "Would you like to purchase a translator device ($5,000)? 1 for yes, 0 for no." << endl;
        int input;
        cin >> input;
        if ((input == 1) && (steve.getMoney() >= 5000)){
            steve.acquireTranslator();
            steve.chargeMoney(5000);
            cout << "You purchased a translator" << endl;
            goToStore(steve);
        }
        else {
            cout << "you either already have a translator or don't have enough money" << endl;
            goToStore(steve);
        }
        break;
    case 3:
        cout << "Would you like to purchase a new suit? Purchasing any suit will fully repair the suit." << endl;
        cout << "1. Space suit grade 2 is $5,000" << endl;
        cout << "2. Space suit grade 3 is $10,000" << endl;
        cout << "3. Space suit grade 4 is $15,000" << endl;
        cout << "4. Space suit grade 5 is $20,000" << endl;
        int choice;
        cin >> choice;
        switch (choice){
            case 1:
                if (steve.getMoney() >= 5000){
                    cout << "Your suit is now a grade 2" << endl;
                    steve.upgradeSuit(2);
                    steve.repairSuit();
                    steve.chargeMoney(5000);
                    goToStore(steve);
                }
                else {
                    cout << "You don't have enough money"<< endl;
                    goToStore(steve);
                }
                break;
            case 2:
                if (steve.getMoney() >= 10000){
                    cout << "Your suit is now grade 3" << endl;
                    steve.upgradeSuit(3);
                    steve.repairSuit();
                    steve.chargeMoney(10000);
                    goToStore(steve);
                }
                else{
                    cout << "You don't have enough money" << endl;
                    goToStore(steve);
                }
                break;
            case 3:
                if (steve.getMoney() >= 15000){
                    cout << "Your suit is now a grade 4" << endl;
                    steve.upgradeSuit(4);
                    steve.repairSuit();
                    steve.chargeMoney(15000);
                    goToStore(steve);
                }
                else{
                    cout << "You don't have enough money" << endl;
                    goToStore(steve);
                }
                break;
            case 4:
                if (steve.getMoney() >= 20000){
                    cout << "Your suit is now a grade 5" << endl;
                    steve.upgradeSuit(5);
                    steve.repairSuit();
                    steve.chargeMoney(20000);
                    goToStore(steve);
                }
                else{
                    cout << "You don't have enough money" << endl;
                    goToStore(steve);
                }
                break;
            default:
                cout << "Invalid input" << endl;
                goToStore(steve);
        }
        break;
        case 4:
            cout << "How many medical kits would you like to purchase ($2,000 each)?" << "you currently have " << steve.getmedKits() << endl;
            int number;
            cin >> number;
            if (steve.getMoney() >= (number * 2000)){
                steve.addmedKit(number);
                steve.chargeMoney(number * 2000);
                goToStore(steve);
            }
            else {
                cout << "You don't have enough money" << endl;
                goToStore(steve);
            }
        break;
        case 5:
            cout << "You have " << steve.getfuel() << " gallons of fuel. How many gallons would you like to purchase ($1,000 per 1,000 gallons)" << endl;
            int amount;
            cin >> amount;
            if (steve.getMoney() >= amount){
                steve.addFuel(amount);
                steve.chargeMoney(amount);
                cout << "You now have " << steve.getfuel() << " gallons of fuel." << endl;
                goToStore(steve);
            }
            else {
                cout << "You don't have enough money" << endl;
                goToStore(steve);
            }
        break;
        case 6:
            cout << "Thank you for shopping" << endl;
        break;
        default:
            cout << "Invalid input" << endl;
            goToStore(steve);

    }
}

void chooseCrewmates()
{
    cout << "Pick a crewmate to help you with your journey!" << endl;
    cout << endl;
    cout << "1. Lola - Doctor" << endl;
    cout << "Ability: Lola is a very successful healer and doctor and will make you gain 5 % health each time you lose health after a battle." << endl;
    cout << endl;
    cout << "2. Nerys - Fighter" << endl;
    cout << "Ability : Nerys is a world - class warrior and weapons operator, increase your odds of winning a battle with hostile aliens by 10 %." << endl;
    cout << endl;
    cout << "3. Millie - Tycoon" << endl;
    cout << "Ability : Millie is an fuel tycoon and will allow you to start with double the fuel." << endl;
    cout << endl;
    cout << "4. Chuck - Intimidator" << endl;
    cout << "Ability: Chuck was once part of the CIA and is very charismatic and intimidating, the friendly alien will be 10 % more likely to tell the truth." << endl;
    int choice = 0;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "You have signed Lola (Doctor) onto your team!" << endl;
        break;

    case 2:
        cout << "You have signed Nerys (Fighter) onto your team!" << endl;
        break;
    case 3:
        cout << "You have signed Millie (Tycoon) onto your team!" << endl;
        break;
    case 4:
        cout << "You have signed Chuck (Intimidator) onto your team!" << endl;
        break;

    default:
        cout << "You have decided to work alone, way to go bud." << endl;
    }
}
bool mainMenu(Player steve, Map map, bool phase2){
    cout << "Select one:" << endl
         << "1. Move" << endl
         << "2. View status" << endl
         << "3. View log book"
         << "4. Resource center " << endl
         << "5. Report planet as habitable" << endl
         << "6. Enter wormhole to next planet" << endl
         << "7. Give up" << endl;
    int choice;
    cin >> choice;
    switch(choice){
        case 1:{
            bool move = true;
            while (move == true){
                map.displayMap();
                cout << "Select one: w. up s. down d. right a. left m. menu" << endl;
                char direction;
                cin >> direction;
                switch(direction){
                    case 'w':
                        if ((map.getPlayerRowPosition() - 1) >= 0){
                            map.movePlayerUp();
                        }
                        else {
                            cout << "Out of range of map" << endl;
                        }
                        break;
                    case 's':
                        if ((map.getPlayerRowPosition() + 1) <= 11){
                            map.movePlayerDown();
                        }
                        else {
                            cout << "Out of range of map" << endl;
                        }
                        break;
                    case 'd':
                        if ((map.getPlayerColPosition() + 1) <= 11){
                            map.movePlayerRight();
                        }
                        else{
                            cout << "Out of range of map" << endl;
                        }
                        break;
                    case 'a':
                        if ((map.getPlayerColPosition() -1) >= 0){
                            map.movePlayerLeft();
                        }
                        else{
                            cout << "Out of range of map" << endl;
                        }
                        break;
                    case 'm':
                        move = false;
                        break;
                    default:
                        cout << "Invalid input"<< endl;
                        break;
                }
            }
            break;
        }
        case 2:
            cout << "Health:" << endl;
            for (int i = 0; i < (steve.gethealthPercent() / 5); i++){
                cout << "_";
            }
            cout << steve.gethealthPercent() << "%" << endl;
            cout << "Space Suit Health: " << endl;
            for (int i = 0; i < (steve.getsuitPercent() / 5); i++){
                cout << "_";
            }
            cout << steve.getsuitPercent() << "%" << endl;
            cout << "Fuel tank:" << endl;
            for (int i = 0; i < (steve.getfuel() / 10000); i++){
                cout << "_";
            }
            cout << steve.getfuel() << endl;
            break;

    }
}
int main()
{
    // Phase One
    Player steve;
    createCharacter(steve);
    storeExplanation();
    goToStore(steve);
    chooseCrewmates();
    cout << "[Preparing For Lift Off]" << endl
         << "10...9...8...7...6...5...4...3...2...1...And...Lift-Off!" << endl;

    // Phase Two
    Planet planet;
    Map map;
    cout << "You have landed on " << planet.getName() << endl;
    // generate map
    map.setPlayerColPosition(0);
    map.setPlayerRowPosition(0);

    // main menu
    map.displayMap();
    bool phase2 = true;
    while (phase2 == true){
        phase2 == mainMenu(steve, map, phase2);
    }
    return 0;
}
