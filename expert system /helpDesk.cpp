#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Convert string to lowercase for case-insensitive matching
string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Keyword search utility
bool hasKeyword(const string& input, const string& keyword) {
    return input.find(keyword) != string::npos;
}

// Rule-based response logic
void analyzeIssue(const string& issue) {
    string input = toLowerCase(issue);

    if (hasKeyword(input, "password") || hasKeyword(input, "login")) {
        cout << "Suggestion: Contact IT Support for password or login issues.\n";
    }
    else if (hasKeyword(input, "salary") || hasKeyword(input, "payroll") || hasKeyword(input, "bonus")) {
        cout << "Suggestion: Forward your issue to the HR Department.\n";
    }
    else if (hasKeyword(input, "bill") || hasKeyword(input, "invoice") || hasKeyword(input, "payment")) {
        cout << "Suggestion: Connect with the Accounts/Billing Department.\n";
    }
    else if (hasKeyword(input, "bug") || hasKeyword(input, "crash") || hasKeyword(input, "error")) {
        cout << "Suggestion: Contact Technical Support to report a software issue.\n";
    }
    else if (hasKeyword(input, "email") || hasKeyword(input, "network") || hasKeyword(input, "internet")) {
        cout << "Suggestion: Contact Network/IT Department.\n";
    }
    else {
        cout << "Suggestion: Please provide more details or contact the General Help Desk.\n";
    }
}

int main() {
    string issue;
    cout << "=== Help Desk Management Expert System ===\n";
    cout << "Describe your issue: ";
    getline(cin, issue);

    analyzeIssue(issue);

    return 0;
}
