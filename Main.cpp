// Tyjon linzy
// 08/3/2025
// M5 Capstone Final
// CSC1061x41 Computer science 2:: 



#include <iostream>
#include <string>
#include "CODLoadoutManager.h"

// the weapon and perks array 
const int NUM_PRIMARY = 4;
const int NUM_SECONDARY = 2;
const int NUM_PERKS = 3;

Weapon primaryWeapons[NUM_PRIMARY] = {
    Weapon("M16", "Assault Rifle", 80, 70, 60),
    Weapon("FAMAS", "Assault Rifle", 75, 75, 65),
    Weapon("SPAS-12", "Shotgun", 90, 50, 40),
    Weapon("MP5", "SMG", 70, 65, 85)
};

Weapon secondaryWeapons[NUM_SECONDARY] = {
    Weapon("Glock", "Handgun", 50, 60, 80),
    Weapon("Desert Eagle", "Handgun", 75, 65, 70)
};

std::string perks[NUM_PERKS] = {
    "Marathon",
    "Sleight of Hand",
    "Steady Aim"
};

int main() {
    LoadoutList loadouts;
    int choice;

    do {
        std::cout << "\n==== Modern Warfare Loadout Builder ====\n";
        std::cout << "1. Create Loadout\n";
        std::cout << "2. View Loadouts\n";
        std::cout << "3. Exit\n";
        std::cout << "4. Sort by Power\n";
        std::cout << "5. Sort by Accuracy\n";
        std::cout << "6. Sort by Speed\n";
        std::cout << "7. Display Loadouts in Reverse\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string name;
            int primChoice, secChoice, perkChoice;

            std::cin.ignore();                      // this is to clear the newline remember!!!
            std::cout << "Enter Loadout Name: ";
            std::getline(std::cin, name);

            std::cout << "\n-- Primary Weapons --\n";
            for (int i = 0; i < NUM_PRIMARY; ++i) {
                std::cout << i + 1 << ". " << primaryWeapons[i].name << " (" << primaryWeapons[i].type << ")\n";
            }
            std::cout << "Choose Primary (1-" << NUM_PRIMARY << "): ";
            std::cin >> primChoice;

            std::cout << "\n-- Secondary Weapons --\n";
            for (int i = 0; i < NUM_SECONDARY; ++i) {
                std::cout << i + 1 << ". " << secondaryWeapons[i].name << " (" << secondaryWeapons[i].type << ")\n";
            }
            std::cout << "Choose Secondary (1-" << NUM_SECONDARY << "): ";
            std::cin >> secChoice;

            std::cout << "\n-- Perks --\n";
            for (int i = 0; i < NUM_PERKS; ++i) {
                std::cout << i + 1 << ". " << perks[i] << "\n";
            }
            std::cout << "Choose Perk (1-" << NUM_PERKS << "): ";
            std::cin >> perkChoice;

            if (primChoice >= 1 && primChoice <= NUM_PRIMARY &&
                secChoice >= 1 && secChoice <= NUM_SECONDARY &&
                perkChoice >= 1 && perkChoice <= NUM_PERKS) {
                loadouts.addLoadout(
                    name,
                    primaryWeapons[primChoice - 1],
                    secondaryWeapons[secChoice - 1],
                    perks[perkChoice - 1]
                );
                std::cout << "✅ Loadout added!\n";
            }
            else {
                std::cout << "❌ Invalid selection.\n";
            }
        }
        else if (choice == 2) {
            loadouts.displayLoadouts();
        }
        else if (choice >= 4 && choice <= 6) {
            LoadoutSorter* sorter = nullptr;
            if (choice == 4) sorter = new PowerSorter();
            else if (choice == 5) sorter = new AccuracySorter();
            else if (choice == 6) sorter = new SpeedSorter();

            if (sorter) {
                sorter->sort(&loadouts);
                delete sorter;
            }
        }
        else if (choice == 7) {
            loadouts.displayReverse();
        }

    } while (choice != 3);

    std::cout << "Goodbye, soldier!\n";
    return 0;
}