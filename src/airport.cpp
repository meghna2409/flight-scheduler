# include "airport.h"

# include <sstream>

// Default constructor
Airport::Airport() {
    id_ = 0;
    name_ = "";
    city_ = "";
    country_ = "";
    latitude_ = 0.0;
    longitude_ = 0.0;
}

// Constructor
Airport::Airport(int id, std::string name, std::string city, std::string country, double latitude, double longitude) {
    id_ = id;
    name_ = name;
    city_ = city;
    country_ = country;
    latitude_ = latitude;
    longitude_ = longitude;
}

Airport::Airport(std::string airport) {
    vector<string> result;
    stringstream s_stream(airport);
    while(s_stream.good()) {
        string substr;
        getline(s_stream, substr, ','); // get first string delimited by comma
        result.push_back(substr);
    }
    // add checks to make sure airport is valid?
    id_ = std::stoi(result[0]);
    name_ = result[1];
    city_ = result[2];
    country_ = result[3];
    // What should we do when lat/long is invalid?
    // How will we be able to calculate the distance?
    try {
        latitude_ = std::stoi(result[6]);
        longitude_ = std::stoi(result[7]);
    } catch(...) {
        cout << "invalid latitude or longitude" << endl;
    }
}

int Airport::getID() {
    return id_;
}

std::string Airport::getName() {
    return name_;
}

std::string Airport::getCity() {
    return city_;
}   

std::string Airport::getCountry() {
    return country_;
}

double Airport::getLatitude() {
    return latitude_;
}

double Airport::getLongitude() {
    return longitude_;
}