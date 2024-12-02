#ifndef INSTANCES_H
#define INSTANCES_H

#include<string>
#include<iostream>
using namespace std;

class Instance {
private:
    string instanceName;
    string instanceDescription;
    bool isCompleted;

public:
    // redundant whoopsie
    Instance() : instanceName(""), instanceDescription(""), isCompleted(false) {}

    // umm im trying this again even tho I already made one but it isnt working so I'll try again here
    Instance(const string& name, const string& description)
        : instanceName(name), instanceDescription(description), isCompleted(false) {}

    string GetInstanceName() const { return instanceName; }
    string GetInstanceDescription() const { return instanceDescription; }
    bool IsCompleted() const { return isCompleted; }
    void CompleteInstance() { isCompleted = true; }
};

#endif