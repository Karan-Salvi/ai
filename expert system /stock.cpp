#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Utility function to convert to lowercase
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Get validated input from user
string getInput(string prompt, string option1, string option2, string option3 = "") {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        input = toLower(input);
        if (input == option1 || input == option2 || (!option3.empty() && input == option3)) {
            return input;
        }
        cout << "Invalid input. Please try again.\n";
    }
}

// Rule-based expert decision
void evaluateMarket(string trend, string news, string volume) {
    cout << "\n--- Expert System Decision ---\n";
    if (trend == "rising" && news == "positive" && volume == "high") {
        cout << "Recommendation: Strong Buy 📈\n";
    } else if (trend == "falling" && news == "negative" && volume == "low") {
        cout << "Recommendation: Strong Sell 📉\n";
    } else if (trend == "rising" && news == "positive") {
        cout << "Recommendation: Buy 📈\n";
    } else if (trend == "falling" && news == "negative") {
        cout << "Recommendation: Sell 📉\n";
    } else {
        cout << "Recommendation: Hold 🤝\n";
    }
}

int main() {
    cout << "=== Stock Market Trading Expert System ===\n";

    string trend = getInput("Enter price trend (rising/stable/falling): ", "rising", "stable", "falling");
    string news = getInput("Enter market news (positive/neutral/negative): ", "positive", "neutral", "negative");
    string volume = getInput("Enter trading volume (high/medium/low): ", "high", "medium", "low");

    evaluateMarket(trend, news, volume);

    return 0;
}
