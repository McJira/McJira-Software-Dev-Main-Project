#pragma once
#include <iostream>
#include <string>
#include "Item.h"
using namespace std;

// Area class definition
class Area {
private:
    string AreaName;        // Name of the area (e.g., "Kitchen", "Bedroom")
    string AreaDescription; // A description of the area
    int Size;               // Size of the area in square meters (or any unit)
    Item Items[10];         // Array to hold Item objects (max 10 items)
    int ItemCount;          // Tracks the current number of items in the area
    string rooms[5];

public:

    // Default constructor
    Area() : AreaName("Unnamed"), AreaDescription("No description available"), Size(0), ItemCount(0) {}

    // Constructor to initialize the area with specific values
    Area(const string& name, const string& description, int size)
        : AreaName(name), AreaDescription(description), Size(size), ItemCount(0) {}


// Setter for rooms
    void SetRooms(const string rooms[], int size) {
        // Ensure that size does not exceed the maximum capacity of the rooms array
        int limit = (size < 5) ? size : 5;
        for (int i = 0; i < limit; i++) {
            this->rooms[i] = rooms[i]; // Copy each room individually
        }
    }
    // Getter for AreaName
    string GetAreaName() const {
        return AreaName;
    }

    // Setter for AreaName
    void SetAreaName(const string& name) {
        AreaName = name;
    }

    // Getter for AreaDescription
    string GetAreaDescription() const {
        return AreaDescription;
    }

    // Setter for AreaDescription
    void SetAreaDescription(const string& description) {
        AreaDescription = description;
    }

    // Getter for Size
    int GetSize() const {
        return Size;
    }

    // Setter for Size
    void SetSize(int size) {
        Size = size;
    }

    // Method to add an Item to the area
    /*
    bool AddItem(const Item& item) {
        if (ItemCount < 10) {               // Check if there is space for more items
            Items[ItemCount++] = item;      // Add the item and increment ItemCount
            return true;
        }
        else {
            cout << "No more space in the area to add items!" << endl;
            return false;
        }
    }
    */
    // Method to display the items in the area
    void DisplayItems() const {
        cout << "Items in " << AreaName << ":" << endl;
        if (ItemCount == 0) {
            cout << "No items found in this area." << endl;
        }
        else {
            for (int i = 0; i < ItemCount; i++) {
                cout << "Item " << (i + 1) << ":" << endl;
                Items[i].DisplayItem();
                cout << endl;
            }
        }
    }

    // Method to display area information
    void DisplayAreaInfo() const {
        cout << "Area Name: " << AreaName << endl;
        cout << "Description: " << AreaDescription << endl;
        cout << "Size: " << Size << " square meters" << endl;
        DisplayItems();
    }
};

int main() {
    // Create an Area object using the default constructor
    Area defaultArea;

    // Display default area information
    defaultArea.DisplayAreaInfo();

    // Create an Area object using the parameterized constructor
    Area kitchen("Kitchen", "A modern kitchen with stainless steel appliances", 20);

    // Create some Item objects
    //Item sword(101, "Magic Sword", 10, "A mystical sword with incredible power.");
    //Item potion(102, "Health Potion", 5, "Restores health when consumed.");

    // Add items to the area
   // kitchen.AddItem(sword);
    //kitchen.AddItem(potion);

    // Display area information and its items
   // kitchen.DisplayAreaInfo();

    return 0;
}
