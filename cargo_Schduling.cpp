#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Convert input to lowercase for easier matching
string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Function to check if a flight is domestic or international
void evaluateFlightSchedule(string flightType, string flightTime) {
    if (flightType == "domestic" && flightTime == "early") {
        cout << "Flight Schedule: Domestic flight, early morning.\n";
    } 
    else if (flightType == "international" && flightTime == "late") {
        cout << "Flight Schedule: International flight, afternoon/evening.\n";
    } 
    else if (flightType == "domestic" && flightTime == "delayed") {
        cout << "Flight Schedule: Domestic flight, later in the day.\n";
    } 
    else {
        cout << "Flight Schedule: Please check available flight slots.\n";
    }
}

// Function to evaluate cargo scheduling based on urgency
void evaluateCargoSchedule(string cargoType) {
    if (cargoType == "urgent") {
        cout << "Cargo Scheduling: Prioritize in the next available flight.\n";
    } 
    else if (cargoType == "regular") {
        cout << "Cargo Scheduling: Schedule in available cargo slots.\n";
    } 
    else if (cargoType == "perishable") {
        cout << "Cargo Scheduling: Immediate scheduling for fastest delivery.\n";
    } 
    else {
        cout << "Cargo Scheduling: Please check cargo details.\n";
    }
}

int main() {
    string flightType, flightTime, cargoType;

    // Input for flight scheduling
    cout << "=== Airline Scheduling Expert System ===\n";
    cout << "Enter flight type (domestic/international): ";
    getline(cin, flightType);
    flightType = toLowerCase(flightType);

    cout << "Enter flight time (early/late/delayed): ";
    getline(cin, flightTime);
    flightTime = toLowerCase(flightTime);

    evaluateFlightSchedule(flightType, flightTime);

    // Input for cargo scheduling
    cout << "\n=== Cargo Scheduling Expert System ===\n";
    cout << "Enter cargo type (urgent/regular/perishable): ";
    getline(cin, cargoType);
    cargoType = toLowerCase(cargoType);

    evaluateCargoSchedule(cargoType);

    return 0;
}
