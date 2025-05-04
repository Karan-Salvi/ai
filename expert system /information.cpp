#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to convert string to lowercase
string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Expert system rules
void processQuery(string queryType) {
    queryType = toLowerCase(queryType);

    if (queryType == "store") {
        cout << "Suggestion: Store documents in categorized folders with clear names.\n";
        cout << "Tip: Use cloud backups for safety.\n";
    } else if (queryType == "retrieve") {
        cout << "Suggestion: Use indexing or search metadata to quickly find documents.\n";
        cout << "Tip: Maintain proper naming conventions.\n";
    } else if (queryType == "delete") {
        cout << "Suggestion: Ensure documents are backed up or not needed before deletion.\n";
        cout << "Tip: Use recycle bin or soft-delete method.\n";
    } else if (queryType == "categorize") {
        cout << "Suggestion: Classify documents by type, date, and importance.\n";
        cout << "Tip: Use tags or folders for better organization.\n";
    } else {
        cout << "Error: Unknown query type. Try one of: store, retrieve, delete, categorize.\n";
    }
}

int main() {
    string userInput;
    cout << "=== Expert System for Information Management ===\n";
    cout << "Enter your query type (store / retrieve / delete / categorize): ";
    getline(cin, userInput);

    processQuery(userInput);

    return 0;
}
