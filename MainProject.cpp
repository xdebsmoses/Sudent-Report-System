#include <iostream>
#include <fstream>
#include <string>
#include "surveyFile.h"
#include "loginDetails.h"

using namespace std;


int main() {
//main system
    cout << "Hello! Welcome to the Student report Management System :) \n";
    string username, password;
    cout << "Do you have an account? (y/n) ";
    char choice;
    cin >> choice;
    cin.ignore(); // Ignore newline character left in buffer, allows a fresh start with next read operation (user & pass)

    if (choice == 'y' || choice == 'Y') {
    loginDetails();
    }else if (choice == 'n' || choice == 'N') {
    createAccount();
    information();
    } else {
    cout << "Invalid choice. \nEnter a correct option between 'n'/'y' please" << endl;
    main();
    //loginDetails();
    return 0;}
    // end survey option
    survey();

}