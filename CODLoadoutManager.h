#pragma once
#include <string>
#include <ostream>  // for std::ostream

// declaring the weapon class
class Weapon {
public:
    std::string name;
    std::string type;
    int power;
    int accuracy;
    int speed;

    Weapon(std::string n, std::string t, int p, int a, int s);

    // Overloaded equality operator
    bool operator==(const Weapon& other) const;
};

// declaring the loadout class
class Loadout {
public:
    std::string name;
    Weapon primary;
    Weapon secondary;
    std::string perk;
    Loadout* next;

    Loadout(std::string n, Weapon p, Weapon s, std::string perk);
};

// declaring the loadout list 
class LoadoutList {
private:
    Loadout* head;

    // this helps the recursive display 
    void displayReverseHelper(Loadout* node);

public:
    LoadoutList();

    void addLoadout(std::string name, Weapon primary, Weapon secondary, std::string perk);
    void displayLoadouts();

    void sortByPrimaryPower();
    void sortByPrimaryAccuracy();
    void sortByPrimarySpeed();

    
    void displayReverse();

    ~LoadoutList();
};

// Abstract base class for sorting loadouts
class LoadoutSorter {
public:
    virtual void sort(LoadoutList* list) = 0;
    virtual ~LoadoutSorter() {}
};

class PowerSorter : public LoadoutSorter {
public:
    void sort(LoadoutList* list) override;
};

class AccuracySorter : public LoadoutSorter {
public:
    void sort(LoadoutList* list) override;
};

class SpeedSorter : public LoadoutSorter {
public:
    void sort(LoadoutList* list) override;
};

// Overloaded stream insertion operators
std::ostream& operator<<(std::ostream& os, const Weapon& w);
std::ostream& operator<<(std::ostream& os, const Loadout& l);