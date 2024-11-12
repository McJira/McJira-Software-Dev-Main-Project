#pragma once

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

//Setter for ItemDamage
void Item::SetItemDamage(int itemDamage){
    ItemDamage = itemDamage;
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

int Item::GetItemDamage() const {
    return ItemDamage;
}

char Item::GetItemIdentifier() const {

    return ItemIdentifier;

}
Item::Item(int id = -1, const string& name = "", int count = 0, const string& description = "", int itemDamage = 0)
    : ItemID(id), ItemName(name), UseCount(count), ItemDescription(description), ItemDamage(itemDamage) {};

Item::Item()
{

}
