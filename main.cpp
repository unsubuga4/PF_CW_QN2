#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find and return divisors of a number in decreasing order
vector<int> findDivisors(int num) {
    vector<int> divisors;
    for (int i = 1; i <= num; ++i) {
        if (num % i == 0) {
            divisors.push_back(i);
        }
    }
    // Sort divisors in decreasing order
    sort(divisors.rbegin(), divisors.rend());
    return divisors;
}

int main() {
    cout << "This program is designed to exhibit the positive divisors of positive integers supplied by you." << endl;
    cout << "The program will repeatedly prompt you to enter a positive integer." << endl;
    cout << "Each time you enter a positive integer, the program will print all the divisors of your integer in a column and in decreasing order." << endl;

    while (true) {
        int number;
        cout << "Please enter a positive integer: "<<endl;
        cin >> number;

        // Check if the input is a positive integer
        while (number <= 0) {
            cout << number << " is not a positive integer." << endl;
            cout << "Please enter a positive integer: ";
            cin >> number;
        }

        // Find and print the divisors
        vector<int> divisors = findDivisors(number);
        for (int divisor : divisors) {
            cout << divisor << endl;
        }

        // Ask the user if they want to continue
        char choice;
        cout << "Would you like to see the divisors of another integer (Y/N)? ";
        cin >> choice;

        while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
            cout << "Please respond with Y (or y) for yes and N (or n) for no." << endl;
            cout << "Would you like to see the divisors of another integer (Y/N)? ";
            cin >> choice;
        }

        // Exit if the user chooses 'N' or 'n'
        if (choice == 'N' || choice == 'n') {
            break;
        }
    }

    return 0;
}

