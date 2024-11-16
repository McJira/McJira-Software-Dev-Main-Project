#ifndef ITEM_H
#define ITEM_H


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
    int ItemUse;         //An integer to store the integer use of an item(heal amount, damage, etc)
    char ItemIdentifier = 'P';

public:
    // Constructor for Item
    Item(int,const string&,int,const string&,int);

    Item();


    // Setter for ItemName
    void SetItemName(const string& name);

    //Setter for ItemDamage
    void SetItemUseAmount(int);

    // Getter for UseCount
    int GetUseCount() const;

    // Setter for UseCount
    void SetUseCount(int count);

    // Setter for ItemDescription
    void SetItemDescription(const string& description);

    // Display item details
    void DisplayItem() const;
    
    // Getter for ItemID
    int GetItemID() const;

    //Getter for ItemDamage
    int GetItemUse () const;

    //Getter for item Identifier
    char GetItemIdentifier() const;

    // Getter for ItemName
    string GetItemName() const;

    // Getter for ItemDescription
    string GetItemDescription() const;

    // Setter for ItemID
    void SetItemID(int id);

    
};

#endif //ITEM_H

