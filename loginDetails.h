#include <iostream>
#include <fstream>
#include <string>
#include "differentSections.h"

using namespace std;

//SOFTWARE USED IN PARTS OF THIS SECTION
//Step 1 - login system created for both student and teachers (general)
// boolean as if the file is successfully opened it will return true then run code, else it will end the code 
bool login(string username, string password) {
    ifstream file("loginInfo.txt"); // Open file containing usernames and passwords
    if (!file.is_open()) { // Check if file was successfully opened
        cout << "Error opening file." << endl;
        return false;
    }
    
    //the lines within the files are a sum of characters, therefore its a string 
    string line;
    while (getline(file, line)) { // Read each line in the file
        size_t pos = line.find(':'); // Find the position of the colon delimiter
        if (pos != string::npos) { // Check if the delimiter was found
            string name = line.substr(0, pos); // Get the username from the line
            string pass = line.substr(pos+1); // Get the password from the line
            if (username == name && password == pass) { // Check if the given username and password match
                return true;
            }
        }
    }
    //we are checking to see if a match was made with the entered name by the user 
    return false; // If no match was found, return false
}

int loginDetails() {
    string username, password;
        cout << "Enter username: ";
        getline(cin, username);
        cout << "Enter password: ";
        getline(cin, password);
        if (login(username, password)) {
            cout << "Login successful!, Welcome " << username << endl;
            teacherOrStudent();
            return 0;
        } else {
            cout << "Invalid username or password." << endl;
            loginDetails();
            return 0;
    }
}