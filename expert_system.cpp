#include <iostream>
using namespace std;

// Function to evaluate performance
string evaluatePerformance(int punctuality, int taskCompletion, int teamwork, int innovation) {
    int score = 0;

    if (punctuality >= 8) score++;
    if (taskCompletion >= 8) score++;
    if (teamwork >= 8) score++;
    if (innovation >= 8) score++;

    if (score == 4)
        return "Excellent";
    else if (score == 3)
        return "Good";
    else if (score == 2)
        return "Average";
    else
        return "Needs Improvement";
}

int main() {
    int punctuality, taskCompletion, teamwork, innovation;

    cout << "Rate the employee on a scale of 1 to 10:\n";
    cout << "Punctuality: ";
    cin >> punctuality;

    cout << "Task Completion: ";
    cin >> taskCompletion;

    cout << "Teamwork: ";
    cin >> teamwork;

    cout << "Innovation: ";
    cin >> innovation;

    string result = evaluatePerformance(punctuality, taskCompletion, teamwork, innovation);
    cout << "\nPerformance Evaluation Result: " << result << endl;

    return 0;
}
