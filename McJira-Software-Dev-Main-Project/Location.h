#include <iostream>
#include <string>
#include "Item.h"
using namespace std;

class Location {
private:
    int LocationID;        // Unique identifier for the location
    string Name;           // Name of the location
    int Latitude;          // Latitude coordinate (as int)
    int Longitude;         // Longitude coordinate (as int)
    string Address;        // Physical address of the location
    string Description;    // Brief description of the location
    string Terrain;        // Type of terrain (e.g., mountain, desert, forest)
    string Climate;        // General climate (e.g., tropical, dry)



public:
    // Constructor
    Location(int id, const string& name, int lat, int lon, const string& address,
        const string& desc, const string& terrain, const string& timeZone,
        const string& climate, const string& info)
        : LocationID(id), Name(name), Latitude(lat), Longitude(lon), Address(address),
        Description(desc), Terrain(terrain), Climate(climate) {}

    // Default constructor
    Location() : LocationID(0), Latitude(0), Longitude(0) {}

    // Getter and setter for LocationID
    int GetLocationID() const {
        return LocationID;
    }

    void SetLocationID(int id) {
        LocationID = id;
    }

    // Getter and setter for Name
    string GetName() const {
        return Name;
    }
    void SetName(const string& name) {
        Name = name;
    }

    // Getter and setter for Latitude
    int GetLatitude() const {
        return Latitude;
    }
    void SetLatitude(int lat) {
        Latitude = lat;
    }

    // Getter and setter for Longitude
    int GetLongitude() const {
        return Longitude;
    }
    void SetLongitude(int lon) {
        Longitude = lon;
    }

    // Getter and setter for Address
    string GetAddress() const {
        return Address;
    }
    void SetAddress(const string& address) {
        Address = address;
    }

    // Getter and setter for Description
    string GetDescription() const {
        return Description;
    }
    void SetDescription(const string& desc) {
        Description = desc;
    }

    // Getter and setter for Terrain
    string GetTerrain() const {
        return Terrain;
    }
    void SetTerrain(const string& terrain) {
        Terrain = terrain;
    }

    // Getter and setter for Climate
    string GetClimate() const {
        return Climate;
    }
};