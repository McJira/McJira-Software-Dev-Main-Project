#include <iostream>
#include <string>
using namespace std;

// Item class definition

class Item {
private:
    int ItemID;            // The item's ID which can be used to reference the item in the catalog
    string ItemName;       // Item's name
    int UseCount;          // How many times the item can be used until it breaks or is depleted
    string ItemDescription; // A description of the item

public:
    // Constructor for Item
    Item(int id = -1, const string& name = "", int count = 0, const string& description = "")
        : ItemID(id), ItemName(name), UseCount(count), ItemDescription(description) {}

    // Getter for ItemID
    int GetItemID() const {
        return ItemID;
    }

    // Setter for ItemID
    void SetItemID(int id) {
        ItemID = id;
    }

    // Getter for ItemName
    string GetItemName() const {
        return ItemName;
    }

    // Setter for ItemName
    void SetItemName(const string& name) {
        ItemName = name;
    }

    // Getter for UseCount
    int GetUseCount() const {
        return UseCount;
    }

    // Setter for UseCount
    void SetUseCount(int count) {
        UseCount = count;
    }

    // Getter for ItemDescription
    string GetItemDescription() const {
        return ItemDescription;
    }

    // Setter for ItemDescription
    void SetItemDescription(const string& description) {
        ItemDescription = description;
    }

    // Display item details
    void DisplayItem() const {
        cout << "Item ID: " << ItemID << endl;
        cout << "Item Name: " << ItemName << endl;
        cout << "Use Count: " << UseCount << endl;
        cout << "Description: " << ItemDescription << endl;
    }
};
