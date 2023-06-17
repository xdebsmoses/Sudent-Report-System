#include <iostream>
#include <fstream>
#include <string>
#include "accountcreation.h"

    int teacherOrStudent () {    
    string role;
    cout << "Are you a Teacher or Student? ";
    cin >> role;

    if (role == "teacher" || role == "Teacher") {
            // using a for loop
        string accessCode = "12345";
        string userCode; 
        int numTries = 3;
    
    for (int i = 0; i < numTries; i++) {
        cout << "Enter access code: ";
        cin >> userCode;

        if (userCode == accessCode) {
            teacherView(); // from teacher section file
            return 0;
        } else {
            cout << "Access denied. You have " << numTries - i - 1 << " tries left." << endl;
        }
    }
        //return 0;
    cout << "You have exceeded the maximum number of tries. Access denied!" << endl;
    return 0;
    }else if (role == "student" || role == "Student") {
            studentView();
            return 0;
    } 
    else {
            cout << "Invalid role entered.\nPlease enter either 'Teacher' or 'Student'.\n"; 
            teacherOrStudent ();
            return 0;
}
    return 0;
}