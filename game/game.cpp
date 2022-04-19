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

void goToStore(Player steve)
{
    cout << "WEAPONS. If your weapon breaks or if you lose your weapon during an event, you may need additional weapons to defend yourself!" << endl
         << "TRANSLATOR. Allows you to communicate with friendly aliens to get their assessment of the planet and increases odds of winning against a hostile alien." << endl
         << "SPACE SUIT. The better the spacesuit, the more durable and protective you will be during the mission and an alien attack." << endl
         << "MEDICAL KITS. The more kits you have, the more times you can revive your health by 40%." << endl
         << "FUEL. Fuel is an essential element for the spacecraft to travel to more planets." << endl
         << "You can spend all of your money here before you start your journey, or you can save some to spend on different resources along the way. You will also gain money for each turn as you move through the game." << endl
         << "Hit enter when you have understood." << endl;
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
            }
            else
            {
                cout << "you already have that weapon or you don't have enough money" << endl;
            }
            break;
        case 2:
            if ((steve.getWeaponstatus(1) == false) && (steve.getMoney() >= 2000))
            {
                steve.buyWeapon(1);
                steve.chargeMoney(2000);
                cout << "you bought Blaster your balance is now " << steve.getMoney() << endl;
            }
            else
            {
                cout << "you already have that weapon or you don't have enough money" << endl;
            }
            break;
        case 3:
            if ((steve.getWeaponstatus(2) == false) && (steve.getMoney() >= 3000))
            {
                steve.buyWeapon(2);
                steve.chargeMoney(3000);
                cout << "you bought Beam Gun your balance is now " << steve.getMoney() << endl;
            }
            else
            {
                cout << "you already have that weapon or you don't have enough money" << endl;
            }
            break;
        case 4:
            goToStore(steve);
            break;
        default:
            cout << "invalid input" << endl;
            goToStore(steve);
        }
        break;
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

int main()
{
    // Phase One
    Player steve;
    createCharacter(steve);
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
    cout << "Select one:" << endl
         << "1. Move" << endl
         << "2. View status" << endl
         << "3. View log book"
         << "4. Resource center " << endl
         << "5. Report planet as habitable" << endl
         << "6. Enter wormhole to next planet" << endl
         << "7. Give up" << endl;

    return 0;
}
