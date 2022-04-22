#include <iostream>
#include <vector>
#include <time.h>
#include "player.h"
#include "map.h"
#include "planet.h"
#include "logbook.h"
#include "weapons.h"

using namespace std;

void createCharacter(Player &steve)
{
    cout << "Enter your name:" << endl;
    string name;
    cin >> name;
    steve.setName(name);
}
void storeExplanation()
{
    cout << "WEAPONS. If your weapon breaks or if you lose your weapon during an event, you may need additional weapons to defend yourself!" << endl
         << "TRANSLATOR. Allows you to communicate with friendly aliens to get their assessment of the planet and increases odds of winning against a hostile alien." << endl
         << "SPACE SUIT. The better the spacesuit, the more durable and protective you will be during the mission and an alien attack." << endl
         << "MEDICAL KITS. The more kits you have, the more times you can revive your health by 40%." << endl
         << "FUEL. Fuel is an essential element for the spacecraft to travel to more planets." << endl
         << "You can spend all of your money here before you start your journey, or you can save some to spend on different resources along the way. You will also gain money for each turn as you move through the game." << endl
         << endl;
    return;
}

int randNum(int low, int high)
{
    srand(time(NULL));
    int num = rand() % (high - low) + low;
    return num;
}

void generateMap(Player &steve, Map &map, Logbook &logbook)
{
    steve.travel();
    logbook.newPage();
    cout << "You have landed on " << logbook.getName() << "..." << endl;
    map.resetMap();
    // spawn alien
    int x = randNum(1, 11);
    int y = randNum(1, 11);

    // cout << map.spawnNPC(x, y) << endl;
    // cout << x << "," << y << endl;
    map.spawnNPC(randNum(1, 11), randNum(1, 11));
    // spawn sites
    for (int i = 0; i < 10; i++)
    {
        int x = 0;
        int y = 0;
        bool notFree = true;
        while (notFree)
        {
            x = randNum(1, 11);
            y = randNum(1, 11);
            if (map.isFreeSpace(x, y) == true)
            {
                notFree = false;
            }
        }
        map.spawnSite(x, y, randNum(1, 5));
    }
    // spawn misfortunes
    for (int i = 0; i < 5; i++)
    {
        int x = 0;
        int y = 0;
        bool notFree = true;
        while (notFree)
        {
            x = randNum(1, 11);
            y = randNum(1, 11);
            if (map.isFreeSpace(x, y) == true)
            {
                notFree = false;
            }
        }
        map.spawnMisfortune(x, y, randNum(1, 3));
    }
    map.setMisfortuneCount(5);
    map.displayMap();
}

void goToStore(Player &steve)
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
        if ((input == 1) && (steve.getMoney() >= 5000))
        {
            steve.acquireTranslator();
            steve.chargeMoney(5000);
            cout << "You purchased a translator" << endl;
            goToStore(steve);
        }
        else
        {
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
        switch (choice)
        {
        case 1:
            if (steve.getMoney() >= 5000)
            {
                cout << "Your suit is now a grade 2" << endl;
                steve.upgradeSuit(2);
                steve.repairSuit();
                steve.chargeMoney(5000);
                goToStore(steve);
            }
            else
            {
                cout << "You don't have enough money" << endl;
                goToStore(steve);
            }
            break;
        case 2:
            if (steve.getMoney() >= 10000)
            {
                cout << "Your suit is now grade 3" << endl;
                steve.upgradeSuit(3);
                steve.repairSuit();
                steve.chargeMoney(10000);
                goToStore(steve);
            }
            else
            {
                cout << "You don't have enough money" << endl;
                goToStore(steve);
            }
            break;
        case 3:
            if (steve.getMoney() >= 15000)
            {
                cout << "Your suit is now a grade 4" << endl;
                steve.upgradeSuit(4);
                steve.repairSuit();
                steve.chargeMoney(15000);
                goToStore(steve);
            }
            else
            {
                cout << "You don't have enough money" << endl;
                goToStore(steve);
            }
            break;
        case 4:
            if (steve.getMoney() >= 20000)
            {
                cout << "Your suit is now a grade 5" << endl;
                steve.upgradeSuit(5);
                steve.repairSuit();
                steve.chargeMoney(20000);
                goToStore(steve);
            }
            else
            {
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
        cout << "How many medical kits would you like to purchase ($2,000 each)?"
             << "you currently have " << steve.getmedKits() << endl;
        int number;
        cin >> number;
        if (steve.getMoney() >= (number * 2000))
        {
            steve.addmedKit(number);
            steve.chargeMoney(number * 2000);
            goToStore(steve);
        }
        else
        {
            cout << "You don't have enough money" << endl;
            goToStore(steve);
        }
        break;
    case 5:
        cout << "You have " << steve.getfuel() << " gallons of fuel. How many gallons would you like to purchase ($1,000 per 1,000 gallons)" << endl;
        int amount;
        cin >> amount;
        if (steve.getMoney() >= amount)
        {
            steve.addFuel(amount);
            steve.chargeMoney(amount);
            cout << "You now have " << steve.getfuel() << " gallons of fuel." << endl;
            goToStore(steve);
        }
        else
        {
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

bool mainMenu(Player &steve, Map &map, Logbook &logbook, bool phase2)
{
    cout << "Select one:" << endl
         << "1. Move" << endl
         << "2. View status" << endl
         << "3. View log book" << endl
         << "4. Resource center " << endl
         << "5. Report planet as habitable" << endl
         << "6. Enter wormhole to next planet" << endl
         << "7. Give up" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        // move 'round
        bool move = true;
        while (move == true)
        {
            map.displayMap();
            cout << "Select one: w. up s. down d. right a. left m. menu" << endl;
            char direction;
            cin >> direction;
            switch (direction)
            {
            case 'w':
                if ((map.getPlayerRowPosition() - 1) >= 0)
                {
                    map.movePlayerUp();
                }
                else
                {
                    cout << "Out of range of map" << endl;
                }
                break;
            case 's':
                if ((map.getPlayerRowPosition() + 1) <= 11)
                {
                    map.movePlayerDown();
                }
                else
                {
                    cout << "Out of range of map" << endl;
                }
                break;
            case 'd':
                if ((map.getPlayerColPosition() + 1) <= 11)
                {
                    map.movePlayerRight();
                }
                else
                {
                    cout << "Out of range of map" << endl;
                }
                break;
            case 'a':
                if ((map.getPlayerColPosition() - 1) >= 0)
                {
                    map.movePlayerLeft();
                }
                else
                {
                    cout << "Out of range of map" << endl;
                }
                break;
            case 'm':
                move = false;
                break;
            default:
                cout << "Invalid input" << endl;
                break;
            }
            if (map.isNPCLocation() == true)
            {
                cout << "You have run into a friendly alien!" << endl;
                if (steve.hasTranslator() == false)
                {
                    continue;
                }
                bool habitable;
                habitable = map.isHabitable();
                int rand = randNum(0, 100);
                if ((habitable == true) && (rand >= 30))
                {
                    cout << "Hello human! I have looked around this planet and think this would make a great home for you." << endl;
                    logbook.setalienAssessment("Hello human! I have looked around this planet and think this would make a great home for you.");
                }
                else if ((habitable == true) && (rand < 30))
                {
                    cout << "Hello human! I have looked around this planet and think this would be a terrible choice for a home. Your fragile species could not handle these conditions, I would suggest finding somplace else." << endl;
                    logbook.setalienAssessment("Hello human! I have looked around this planet and think this would be a terrible choice for a home. Your fragile species could not handle these conditions, I would suggest finding somplace else.");
                }
                else if ((habitable == false) && (rand >= 30))
                {
                    cout << "Hello human! I have looked around this planet and think this would be a terrible choice for a home. Your fragile species could not handle these conditions, I would suggest finding somplace else." << endl;
                    logbook.setalienAssessment("Hello human! I have looked around this planet and think this would be a terrible choice for a home. Your fragile species could not handle these conditions, I would suggest finding somplace else.");
                }
                else
                {
                    cout << "Hello human! I have looked around this planet and think this would be a terrible choice for a home. Your fragile species could not handle these conditions, I would suggest finding somplace else." << endl;
                    logbook.setalienAssessment("Hello human! I have looked around this planet and think this would be a terrible choice for a home. Your fragile species could not handle these conditions, I would suggest finding somplace else.");
                }
            }
            if (map.isMisfortuneLocaton() == true)
            {
                int misfortune = map.getMisfortuneType();
                if (misfortune == 1)
                {
                    steve.weatherStorm();
                    cout << "Oh no! You're caught in a storm. Your health is now " << steve.gethealthPercent() << "%. Your suit is at" << steve.getsuitPercent() << "%" << endl;
                    
                }
                else if (misfortune == 2)
                {
                    steve.crater();
                    cout << "Oh no! You fell into a crater. Your health is now " << steve.gethealthPercent() << "%. Your suit is at" << steve.getsuitPercent() << "%" << endl;
                    
                }
                else
                {
                    steve.spaceSickness();
                    cout << "Oh no! You have space sickness. Your health is now " << steve.gethealthPercent() << "%. Your suit is at" << steve.getsuitPercent() << "%" << endl;
                    
                }
            }
            if (map.isSiteLocation() == true)
            {
                int trait = map.getSiteTrait();
                switch (trait)
                {
                case 1:
                    cout << "You just discovered that this planet has water. This is a great sign. This discovery has been added to your log book." << endl;
                    logbook.addGoodTrait("Water");
                    break;
                case 2:
                    cout << "You just discovered that this planet has oxygen. This is a great sign. This discovery has been added to your log book." << endl;
                    logbook.addGoodTrait("Oxygen");
                    break;
                case 3:
                    cout << "You just discovered that this planet has fertile soil. This is a great sign. This discovery has been added to your log book." << endl;
                    logbook.addGoodTrait("Fertile Soil");
                    break;
                case 4:
                    cout << "You just discovered that this planet has toxic gas. This is a bad sign. This discovery has been added to your log book." << endl;
                    logbook.addBadTrait("Toxic Gas");
                    break;
                case 5:
                    cout << "You just discovered that this planet has bad atmosphere. This is a bad sign. This discovery has been added to your log book." << endl;
                    logbook.addBadTrait("Bad Atmosphere");
                    break;
                case 6:
                    cout << "You just discovered that this planet has extreme temperature. This is a bad sign. This discovery has been added to your log book." << endl;
                    logbook.addBadTrait("Extreme Temeperature");
                    break;
                }
                if ((steve.gethealthPercent() <= 0) || (steve.getsuitPercent() <= 0))
                {
                    cout << "You have died due to health loss. Had you planned better with more sophisticated materials, you may have been able to prevent this. You can no longer explore more of space." << endl;
                    return false;
                }
            }
        }
        return true;
        break;
    }
    case 2:
        // stats
        cout << "Health:" << endl;
        for (int i = 0; i < (steve.gethealthPercent() / 5); i++)
        {
            cout << "_";
        }
        cout << steve.gethealthPercent() << "%" << endl;
        cout << "Space Suit Health: " << endl;
        for (int i = 0; i < (steve.getsuitPercent() / 5); i++)
        {
            cout << "_";
        }
        cout << steve.getsuitPercent() << "%" << endl;
        cout << "Fuel tank:" << endl;
        for (int i = 0; i < (steve.getfuel() / 10000); i++)
        {
            cout << "_";
        }
        cout << steve.getfuel() << endl;
        cout << "Planets explored: " << logbook.getnumPages() + 1 << endl;
        cout << "Planets accurately reported habitable: " << logbook.getcorrectHabitable() << endl;
        cout << "Planets inaccurately reported habitable: " << logbook.getincorrectHabitable() << endl;
        cout << "- Money - $" << steve.getMoney() << endl;
        cout << "- WEAPONS" << endl;
        cout << "  1. Light Saber - " << steve.getWeaponstatus(0) << endl;
        cout << "  2. Blaster - " << steve.getWeaponstatus(1) << endl;
        cout << "  3. Beam gun - " << steve.getWeaponstatus(2) << endl;
        cout << "- TRANSLATOR - " << steve.hasTranslator() << endl;
        cout << "- SPACE SUIT GRADE #" << steve.getsuitGrade() << endl;
        cout << "- MEDICAL KITS - " << steve.getmedKits() << endl;
        cout << "- FUEL - " << steve.getfuel() << endl;
        return true;
        break;
    case 3:
        // log book
        logbook.printPage(logbook.getnumPages());
        return true;
        break;
    case 4:
        // resource center
        goToStore(steve);
        return true;
        break;
    case 5:{
        // report habitable
        cout << "Are you sure you want to report back to mission control that this planet is habitable? As a reminder, here is your log book:" << endl;
        logbook.printPage(logbook.getnumPages());
        cout << endl;
        cout << "Reporting this planet is irreversible. If this planet is in fact habitable, you will save millions of lives! If it's not the people sent to this planet will die." << endl;
        cout << endl;
        cout << "Ready to report? [y/n]" << endl;
        string inputReport;
        cin >> inputReport;
        if (inputReport == "y")
        {
            if (map.isHabitable() == true)
            {
                cout << endl;
                cout << "Congratulations! You have saved " << endl;
                cout << logbook.getCapacity() << endl;
                cout << "million people! Planet " << endl;
                cout << logbook.getName() << endl;
                cout << "is their new home." << endl;
                logbook.addCorrect();
                generateMap(steve, map, logbook);
            }
            else
            {
                cout << endl;
                cout << "Your choice has led to tragedy. " << endl;
                cout << logbook.getCapacity() << endl;
                cout << "million people were sent to " << endl;
                cout << logbook.getName() << endl;
                cout << "and died due to its in-hospitable conditions." << endl;
                logbook.addIncorrect();
                generateMap(steve, map, logbook);
            }
        }
        return true;
        break;
    }
    case 6:
        // enter next wormhole
        cout << "Entering Wormhole..." << endl;
        generateMap(steve, map, logbook);
        return true;
        break;

    case 7:
        // give up
        cout << "[" << steve.getName() << "]: \"I give up...\"" << endl
             << endl
             << "  G A M E  O V E R" << endl
             << endl
             << "It is disappointing to hear that you have quit, humanity was depending on you..." << endl
             << endl;
        return false;
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
    Logbook logbook;
    logbook.setUser(steve.getName());
    // generate map
    map.setPlayerColPosition(0);
    map.setPlayerRowPosition(0);

    // main menu
    bool phase2 = true;
    generateMap(steve, map, logbook);
    while (phase2 == true)
    {
        phase2 = mainMenu(steve, map, logbook, phase2);
    }
    return 0;
}
