#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>
#include <set>

using namespace std;

// Function to generate a random password
string generatePassword(int length) {
    const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*_=+";
    string password;
    srand(time(0)); // Seed the random number generator

    for (int i = 0; i < length; ++i) {
        password.push_back(charset[rand() % charset.length()]);
    }

    return password;
}

// Function to generate a random username
string generateUsername(int length, const string& password) {
    const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+";
    string username;
    srand(time(0)); // Seed the random number generator

    // Create a set of characters already used in the password
    set<char> usedChars;
    for (char c : password) {
        usedChars.insert(c);
    }

    // Generate username excluding characters already used in password
    for (int i = 0; i < length; ++i) {
        char randomChar;
        do {
            randomChar = charset[rand() % charset.length()];
        } while (usedChars.count(randomChar) > 0);
        username.push_back(randomChar);
    }

    return username;
}

// Function to check if a string contains only digits
bool isNumeric(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    string passwordLengthInput, usernameLengthInput;
    int passwordLength, usernameLength;

    // Input length of password from the user
    cout << "Enter the length of the password: ";
    cin >> passwordLengthInput;

    // Validate password length input format
    while (!isNumeric(passwordLengthInput) || passwordLengthInput.length() == 0) {
        cout << "Please enter a valid length (positive integer): ";
        cin >> passwordLengthInput;
    }

    // Convert password length input to integer
    passwordLength = stoi(passwordLengthInput);

    // Input length of username from the user
    cout << "Enter the length of the username: ";
    cin >> usernameLengthInput;

    // Validate username length input format
    while (!isNumeric(usernameLengthInput) || usernameLengthInput.length() == 0) {
        cout << "Please enter a valid length (positive integer): ";
        cin >> usernameLengthInput;
    }

    // Convert username length input to integer
    usernameLength = stoi(usernameLengthInput);

    // Generate and display the password
    string password = generatePassword(passwordLength);
    cout << "Generated Password: " << password << endl;

    // Generate and display the username
    string username = generateUsername(usernameLength, password);
    cout << "Generated Username: " << username << endl;

    return 0;
}
