#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // only used to tidy up the console output here

using namespace std;

// Base class
class studentAttendance {
  public:
  // This function is used to output the attendance rates phrase for the 5 subjects 
    void percentages() {
      cout << "The attendance rate for class selected is\n"; 
    }
};

// Derived class
class English : public studentAttendance {
  public:
  // This function is used to output the attendance rate for english.
    // We are inheriting the base class function to this class
    void percentages() {
      //- POLYMORPHISM - overridden version is called instead of base class version(added info to base based upon the class)
      cout << "84%\n";
    }
};

// Derived class
class Maths : public studentAttendance {
  public:
  // This function is used to output the attendance rate for maths.
    void percentages() {
      cout << "93% \n";
    }
};

// Derived class
class Science : public studentAttendance {
  public:
  // This function is used to output the attendance rate for science.
    void percentages() {
      cout << "23% \n";
    }
};

// Derived class
class History : public studentAttendance {
  public:
  // This function is used to output the attendance rate for history.
    void percentages() {
      cout << "98% \n";
    }
};

// Derived class
class Spanish : public studentAttendance {
  public:
  // This function is used to output the attendance rate for spanish.
    void percentages() {
      cout << "56% \n";
    }
};


// Step 3 - teacher oprions 
void teacherView() {
    string details;
    cout << "What details would you like to view?" << endl;
    cout << "1. View Student Log for a class" << endl;
    cout << "2. Set assignments for a class" << endl;
    cout << "3. Monitor Student Attendance" << endl;
    cout << "Enter 1, 2, or 3: ";
    cin >> details;

    if (details == "1") {
        // Ask the user for the filename
            cout << "What Class would you like to view the Student log for? \n";
            string filename;
            cin >> filename;
            // Open the input file
            ifstream inputFile("./subjects/" + filename + ".txt");
            // Check if the file is open
            if (!inputFile.is_open())
            {
                // Output an error message if the file could didn't open.
                cerr << "Error opening input file.\n";
            }
            // Read the contents of the file and output them
            string line;
            while (getline(inputFile, line))
            {
                // adds a line between each grade
                cout << line << '\n';
            }
            // Close the input file
            inputFile.close();
            } 

    else if (details == "2") {
            // open the file for appending
            ofstream outputFile("assignments .txt", ios::app); 

            if (!outputFile.is_open()) {
                cerr << "Error opening output file.\n";
            }
            // write a line to the file
            string assignment;
            cin.ignore(); // ignore the newline character from previous input
            cout << "Write new assignemnt here.. \n";
            getline(cin, assignment);// adds line to file including spaces 
            outputFile << assignment + "\n\n"; // add a newline to create a blank line between entries
            // close the file
            outputFile.close();
            cout << "assignment has successfully been added! "<< endl;


    }else if (details == "3") {
            // Using arrays as a data collection to check the teacher for each subject 
            string attendance;
            studentAttendance theAttendance; // creating an object for the class
            string lesson[5] = {"English", "Maths", "Science", "History", "Spanish"};
            string lesson1[5] = {"english", "maths", "science", "history", "spanish"};
            cout << "What subject would you like to know for your attendance?\n";
            cin >> attendance;

            //ENGLISH ATTENDANCE
            if (attendance == lesson[0] || attendance == lesson1[0]) {
                //creating an object of the class
                English theEnglish;
                //english
                //calling the 2 functions
                  theAttendance.percentages();
                  theEnglish.percentages();
            }

            // MATHS ATTENDANCE
            else if (attendance == lesson[1] || attendance == lesson1[1]) {
                Maths theMaths;
                  theAttendance.percentages();
                  theMaths.percentages();
            }

            //SCIENCE ATTENDANCE 
            else if (attendance == lesson[2] || attendance == lesson1[2]) {
                Science theScience;
                  theAttendance.percentages();
                  theScience.percentages();
            }

            //HISTORY ATTENDANCE
            else if (attendance == lesson[3] || attendance == lesson1[3]) {
                History theHistory;
                  theAttendance.percentages();
                  theHistory.percentages();
            }

            //SPANISH ATTENDANCE
            else if (attendance == lesson[4] || attendance == lesson1[4]) {
                Spanish theSpanish;
                  theAttendance.percentages();
                  theSpanish.percentages();
            }else {
                cout << "Invalid subject entered or the school does not do the subject.\n";
            }

    }else { 
      cout << "Invalid option entered. Please enter either 1, 2, or 3." << endl;
    }
            //once the task has been preformed, they are asked if they would like to go back to the menu
            int option;
            cout << "Would you like to continue to a different option (1) or end here (2)? ";
            cin >> option; 
            if (option == 1) {
                teacherView();
            }else if (option ==2) {
                cout << "Thank you for using our system" ;
            } 
            else {
            cout << "invalid entry!" ;
}
}