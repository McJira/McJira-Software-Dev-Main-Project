#include "Item.h"

void Item::DisplayItem() const{
    cout << "Item ID: " << ItemID << endl;
    cout << "Item Name: " << ItemName << endl;
    cout << "Use Count: " << UseCount << endl;
    cout << "Description: " << ItemDescription << endl;
}

void Item::SetItemDescription(const string& description) {
    ItemDescription = description;
}

// Setter for ItemID
void Item::SetItemID(int id) {
    ItemID = id;
}

// Setter for UseCount
void Item::SetUseCount(int count) {
    UseCount = count;
}

// Setter for ItemName
void Item::SetItemName(const string& name) {
    ItemName = name;
}
// Getter for ItemName
string Item::GetItemName() const {
    return ItemName;
}

// Getter for UseCount
int Item::GetUseCount() const {
    return UseCount;
}

// Getter for ItemDescription
string Item::GetItemDescription() const {
    return ItemDescription;
}

int Item::GetItemID() const {
    return ItemID;
}

Item::Item(int id = -1, const string& name = "", int count = 0, const string& description = "")
    : ItemID(id), ItemName(name), UseCount(count), ItemDescription(description) {};