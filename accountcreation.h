#include <iostream>
#include <fstream>
#include <string>
#include "studentsection.h"
#include "teachersection.h"

using namespace std;

//if there is no account, they can create one 
void createAccount() {
    ofstream file("loginInfo.txt", ios::app); // Open file in append mode to add new account
    
    string username, password;
    cout << "Create a new account" << endl;
    cout << "Enter username: ";
    // we are taking in the input the user has entered and setting it as their username (getline is used to read a string)
    getline(cin, username);
    cout << "Enter password: ";
    // we are taking in the input the user has entered and setting it as their username 
    getline(cin, password);
        if (username == "" || password == "") {
        cout << "Username or password cannot be left blank.\n";
        createAccount();
        //return 0;
    }
    else {
    file << username << ":" << password << endl; // Add new account to file
    file.close(); // Close the file
    cout << "Account created successfully!" << endl;
    }
}

void information() {
    // teacher or student section  
    string selection;
    cout << "Are you a Teacher or Student? ";
    cin >> selection;
    cin.ignore(); // Ignore the newline character left in the input buffer

    if (selection == "student" || selection == "Student") {
        int id;
        cout << "please enter your 3 digit ID: ";
        cin >> id;
        while (id < 100 || id > 999)  {
        cout << "ID should be 3 characters.\n Please enter a valid ID number" << endl;
        cin >> id;
        }
        // checking to see if ID was used before 
        string filename = "./subjects/english.txt";
        // reading the file
        ifstream infile(filename);
        if (infile.is_open()) {
            int firstItem;
            //reading first word in the file and storing it
            infile >> firstItem;
            infile.close();
            //checking to see if ID was used before
            if (firstItem == id) {
                cout << "The ID is either entered incorrectly or it belongs to another student." << endl;
                cout << "Please enter correct ID: ";
                cin >> id;
                //checking to see if id is valid 
                while (id < 100 || id > 999)  {
                cout << "ID should be 3 characters. Please enter a valid ID number: " << endl;
                cin >> id;
            }
            }
        }else {
                cout << "Error: file not found." << endl;
                return;
                // handle error
        }

        //INPUTTING THEIR ID
        int ID;
        cout << "please re-enter your 3 digit ID for confirmation: " << endl; 
        cin >> ID;
        if (ID != id) {
            cout << "The IDs entered do not match. Please try again." << endl;
            information();
            return;
        }

        cout << "ID's are a Match Thank you!\n";

        ofstream file("./subjects/english.txt", ios::app);
        string english, maths, science, history, spanish;
        cout << "Please enter your grades for English (From Grades A-F): ";
        cin >> english;
        // opening the english file
        file << id << " " << english << endl;
        // Add a string to the file BASED UPON USER INPUT and adding a blank line and space in between 
        
        // new subject
        ofstream file2("./subjects/maths.txt", ios::app);
        cout << "Please enter your grades for Maths (From Grades A-F): ";
        cin >> maths;
        // opening the maths file
        file2 << id << " " << maths << endl;
        // Add a string to the file BASED UPON USER INPUT and adding a blank line and space in between 
        
        // new subject
        ofstream file3("./subjects/science.txt", ios::app);
        cout << "Please enter your grades for Science (From Grades A-F): ";
        cin >> science;
        // opening the science file
        file3 << id << " " << science << endl;
        // Add a string to the file BASED UPON USER INPUT and adding a blank line and space in between 
        
        // new subject
        ofstream file4("./subjects/history.txt", ios::app);
        cout << "Please enter your grades for History (From Grades A-F): ";
        cin >> history;
        // opening the history file
        file4 << id << " " << history << endl;
        // Add a string to the file BASED UPON USER INPUT and adding a blank line and space in between 
        
        // new subject
        ofstream file5("./subjects/spanish.txt", ios::app);
        cout << "Please enter your grades for Spanish (From Grades A-F): ";
        cin >> spanish;
        // opening the spanish file
        file5 << id << " " << spanish << endl;
        // Add a string to the file BASED UPON USER INPUT and adding a blank line and space in between 
        
        // once details added we give them their options
        cout << "Successfully added." << endl;
        studentView(); 
    }
    else if (selection == "teacher" || selection == "Teacher") {
        string accessCode = "12345";
        string userCode;
        int numTries = 3;
    
    for (int i = 0; i < numTries; i++) {
        cout << "Enter access code: ";
        cin >> userCode;

        if (userCode == accessCode) {
            teacherView(); // from teacher section file
        } else {
            cout << "Access denied. You have " << numTries - i - 1 << " tries left." << endl;
        }
    }
        //return 0;
    cout << "You have exceeded the maximum number of tries. Access denied!" << endl;
    } 
    else {
        cout << "Invalid role entered. Please enter either 'teacher' or 'student'." << endl;
        information();
    }
}