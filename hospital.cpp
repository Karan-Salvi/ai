#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// Utility function to convert string to lowercase
string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Function to check if a keyword exists in the input
bool hasKeyword(const string& input, const string& keyword) {
    return input.find(keyword) != string::npos;
}

// Expert system rules for hospital/medical advice
void processSymptoms(string symptoms) {
    symptoms = toLowerCase(symptoms);

    if (hasKeyword(symptoms, "chest pain")) {
        cout << "Advice: Consult a Cardiologist (Heart Specialist).\n";
    }
    else if ((hasKeyword(symptoms, "fever") && hasKeyword(symptoms, "cough")) ||
             hasKeyword(symptoms, "flu") || hasKeyword(symptoms, "cold")) {
        cout << "Advice: Visit General Medicine or Infectious Disease department.\n";
    }
    else if (hasKeyword(symptoms, "accident") || hasKeyword(symptoms, "bleeding") ||
             hasKeyword(symptoms, "fracture")) {
        cout << "Advice: Go to Emergency Department immediately.\n";
    }
    else if (hasKeyword(symptoms, "headache") && hasKeyword(symptoms, "nausea")) {
        cout << "Advice: Neurology consultation is recommended.\n";
    }
    else if (hasKeyword(symptoms, "stress") || hasKeyword(symptoms, "depression") ||
             hasKeyword(symptoms, "anxiety")) {
        cout << "Advice: Consult a Psychiatrist.\n";
    }
    else {
        cout << "Advice: Please consult a General Physician for further diagnosis.\n";
    }
}

int main() {
    string userInput;
    cout << "=== Hospital Expert System ===\n";
    cout << "Describe your symptoms: ";
    getline(cin, userInput);

    processSymptoms(userInput);

    return 0;
}
