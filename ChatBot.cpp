#include <iostream>
using namespace std;

int main() {
    int choice;

    cout << "Welcome to Customer Support Chatbot!\n";

    while (true) {
        cout << "\nPlease select an option:\n";
        cout << "1. Book a table\n";
        cout << "2. Show menu\n";
        cout << "3. Opening hours\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice == 1) {
            cout << "You chose to book a table. Please call 123-456-7890 for reservations.\n";
        } else if (choice == 2) {
            cout << "Our menu: Pizza, Pasta, Burger, Salad, Dessert\n";
        } else if (choice == 3) {
            cout << "We are open daily from 10 AM to 11 PM.\n";
        } else if (choice == 4) {
            cout << "Thank you! Have a nice day.\n";
            break;
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }

    return 0;
}
