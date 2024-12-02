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
    // default constructor creates empty instances
    Instance() : instanceName(""), instanceDescription(""), isCompleted(false) {}

    // other constructor that initializes the instances using the descriptons and names from source
    Instance(const string& name, const string& description)
        : instanceName(name), instanceDescription(description), isCompleted(false) {}

    // getters
    string GetInstanceName() const { return instanceName; }
    string GetInstanceDescription() const { return instanceDescription; }
    bool IsCompleted() const { return isCompleted; }

    // sets instance to completed or not once the user talks to them
    void CompleteInstance() { isCompleted = true; }
};

#endif