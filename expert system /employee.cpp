#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Convert input to lowercase
string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Function to get yes/no input and validate
bool getYesNo(string prompt) {
    string response;
    cout << prompt << " (yes/no): ";
    getline(cin, response);
    response = toLowerCase(response);
    return (response == "yes");
}

// Function to evaluate performance based on rules
void evaluatePerformance(bool punctual, bool taskCompletion, bool teamwork,
                         bool communication, bool problemSolving) {
    int score = 0;
    score += punctual ? 1 : 0;
    score += taskCompletion ? 1 : 0;
    score += teamwork ? 1 : 0;
    score += communication ? 1 : 0;
    score += problemSolving ? 1 : 0;

    cout << "\nPerformance Evaluation Result:\n";
    if (score == 5) {
        cout << "Remark: Excellent Employee\n";
    } else if (score >= 3) {
        cout << "Remark: Good Performance\n";
    } else if (score == 2) {
        cout << "Remark: Average Performance\n";
    } else {
        cout << "Remark: Needs Improvement\n";
    }
}

int main() {
    cout << "=== Employee Performance Evaluation Expert System ===\n";

    bool punctual = getYesNo("Is the employee punctual?");
    bool taskCompletion = getYesNo("Does the employee complete tasks on time?");
    bool teamwork = getYesNo("Does the employee work well in a team?");
    bool communication = getYesNo("Is the employee a good communicator?");
    bool problemSolving = getYesNo("Can the employee solve problems independently?");

    evaluatePerformance(punctual, taskCompletion, teamwork, communication, problemSolving);

    return 0;
}
