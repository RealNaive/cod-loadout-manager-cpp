#include "CODLoadoutManager.h"
#include <iostream>
#include <vector>
#include <algorithm>

// Initializes the weapons
Weapon::Weapon(std::string n, std::string t, int p, int a, int s)
    : name(n), type(t), power(p), accuracy(a), speed(s) {
}

// Loadout constructor
Loadout::Loadout(std::string n, Weapon p, Weapon s, std::string perk)
    : name(n), primary(p), secondary(s), perk(perk), next(nullptr) {
}

// LoadoutList constructor
LoadoutList::LoadoutList() : head(nullptr) {}

// Add a new loadout to the front of the linked list
void LoadoutList::addLoadout(std::string name, Weapon primary, Weapon secondary, std::string perk) {
    Loadout* newNode = new Loadout(name, primary, secondary, perk);
    newNode->next = head;
    head = newNode;
}

// Display all loadouts in the list (iterative)
void LoadoutList::displayLoadouts() {
    if (!head) {
        std::cout << "No loadouts created yet.\n";
        return;
    }

    Loadout* curr = head;
    while (curr != nullptr) {
        std::cout << "\nLoadout: " << curr->name << "\n";
        std::cout << "Primary: " << curr->primary.name << " (" << curr->primary.type << ")"
            << " | Power: " << curr->primary.power
            << ", Accuracy: " << curr->primary.accuracy
            << ", Speed: " << curr->primary.speed << "\n";
        std::cout << "Secondary: " << curr->secondary.name << " (" << curr->secondary.type << ")\n";
        std::cout << "Perk: " << curr->perk << "\n";
        std::cout << "-------------------------------\n";
        curr = curr->next;
    }
}

// Recursive helper for displaying loadouts in reverse order

void LoadoutList::displayReverseHelper(Loadout* node) {
    if (node == nullptr) return;
    displayReverseHelper(node->next);
    std::cout << "\nLoadout: " << node->name << "\n";
    std::cout << "Primary: " << node->primary.name << " (" << node->primary.type << ")"
        << " | Power: " << node->primary.power
        << ", Accuracy: " << node->primary.accuracy
        << ", Speed: " << node->primary.speed << "\n";
    std::cout << "Secondary: " << node->secondary.name << " (" << node->secondary.type << ")\n";
    std::cout << "Perk: " << node->perk << "\n";
    std::cout << " Yesssirrrrrrrrr \n";
}

// Public method to start recursive reverse display
void LoadoutList::displayReverse() {
    displayReverseHelper(head);
}

// Helper function template to sort linked list nodes based on a comparison
template <typename Compare>
void sortLoadouts(Loadout*& head, Compare comp) {
    std::vector<Loadout*> nodes;
    Loadout* curr = head;
    while (curr) {
        nodes.push_back(curr);
        curr = curr->next;
    }

    std::sort(nodes.begin(), nodes.end(), comp);

    head = nullptr;
    for (int i = static_cast<int>(nodes.size()) - 1; i >= 0; --i) {
        nodes[i]->next = head;
        head = nodes[i];
    }
}

// Sort loadouts by primary weapon power (descending)
void LoadoutList::sortByPrimaryPower() {
    sortLoadouts(head, [](Loadout* a, Loadout* b) {
        return a->primary.power > b->primary.power;
        });
    std::cout << "✅ Sorted by Primary Weapon Power.\n";
}

// Sort loadouts by primary weapon accuracy (descending)
void LoadoutList::sortByPrimaryAccuracy() {
    sortLoadouts(head, [](Loadout* a, Loadout* b) {
        return a->primary.accuracy > b->primary.accuracy;
        });
    std::cout << "✅ Sorted by Primary Weapon Accuracy.\n";
}

// Sort loadouts by primary weapon speed (descending)


void LoadoutList::sortByPrimarySpeed() {
    sortLoadouts(head, [](Loadout* a, Loadout* b) {
        return a->primary.speed > b->primary.speed;
        });
    std::cout << "✅ Sorted by Primary Weapon Speed.\n";
}

// Destructor to free all nodes
LoadoutList::~LoadoutList() {
    while (head) {
        Loadout* temp = head;
        head = head->next;
        delete temp;
    }
}

// ====== Implementations of the sorter classes ======

void PowerSorter::sort(LoadoutList* list) {
    list->sortByPrimaryPower();
}

void AccuracySorter::sort(LoadoutList* list) {
    list->sortByPrimaryAccuracy();
}

void SpeedSorter::sort(LoadoutList* list) {
    list->sortByPrimarySpeed();
}