#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip> // only used to tidy up the console output here
#include <string>

using namespace std;

class Teachers {
  // encapsulation to make sure that the ID data from individuals are hidden
  private:
    int ID;// Attribute (property) for teacher class
  public:// Access specifier
    string lesson;// Attribute
    string name;// Attribute
    //setter - adding these methods so that users can read the ID
    void setID(int i) { 
        ID = i;} //setting the ID to the parameter i 
    int getID() { // Getter - returns the value of the private id attribute 
      return ID;
    };
    Teachers(string x, string y, int z) {  // Constructor with parameters
      lesson = x;
      name = y;
      ID = z;
    }
};

// Step 3 - teacher oprions 
void studentView() {
    string userChoice;
    cout << "What details would you like to view?" << endl;
    cout << "1. View grades for Subjects" << endl;
    cout << "2. View Teachers for subjects" << endl;
    cout << "3. View assignments" << endl;
    cout << "Enter 1, 2, or 3: ";
    cin >> userChoice;

    if (userChoice == "1") {
        int ID;
        string subject;
        cout << "Please Enter Student ID" << endl;
        cin >> ID;
        cout << "What subject grades would you like to view? " << endl;
        cin >> subject;

        ifstream gradesFile("./subjects/" + subject + ".txt"); 
        // open file based on user input and my folder
        if (!gradesFile.is_open()) { // check if file was opened successfully
            cout << "Error opening file Or file doesnt exist" << endl;
            //return;
        }
        // ONLINE SOFTWARE USED TO HELP WITH THIS SECTION
        string line;
        bool found = false; // flag to check if ID was found
        while (getline(gradesFile, line)) { // read each line of the file
            stringstream ff(line); // create a stringstream from the line, used to get specific values from a string
            int studentID;
            ff >> studentID; // read the first word as an integer and assigns it to the student id
            if (studentID == ID) { // check if the ID matches the user input
                string word;
                while (ff >> word) { // output the remaining words in the line
                    cout << word << " ";
                    found = true; // set flag to true
                    }
                cout << endl;
            }
        }
        if (!found) {
            cout << "id not found "<< endl;
            gradesFile.close();
        }
    }
    else if (userChoice == "2") {
    string lessons;
    // Creating Teacher objects and calling the constructor with different values
    cout << "What subject would you like to know the teacher of?\n";
    cin >> lessons;
    Teachers teachersObj1("English: ", "Mrs.Black", 489);
    Teachers teachersObj2("Maths: ", "Mr.Rajendran", 702);
    Teachers teachersObj3("Science: ", "Mr.Haliday", 123);
    Teachers teachersObj4("History: ", "Mr.Russell", 119);
    Teachers teachersObj5("Spanish: ", "Mr.Mcbeth", 324);

    if (lessons == "English" || lessons == "english" ){
            cout << teachersObj1.lesson << teachersObj1.name << "\n& their ID is: " << teachersObj1.getID() << "\n"; // using get to return the value from encapsulation
    }
    else if (lessons == "Maths" || lessons == "maths" || lessons == "Mathematics") {
            cout << teachersObj2.lesson << teachersObj2.name << "\n& their ID is: " << teachersObj2.getID() << "\n";
    }
    else if (lessons == "Science" || lessons == "science"){
            cout << teachersObj3.lesson << teachersObj3.name << "\n& their ID is: " << teachersObj3.getID() << "\n";
    }
    else if (lessons == "History" || lessons == "history") {
            cout << teachersObj4.lesson << teachersObj4.name << "\n& their ID is: " << teachersObj4.getID() << "\n";
    }
    else if (lessons == "Spanish" || lessons == "spanish"){
            cout << teachersObj5.lesson << teachersObj5.name << "\n& their ID is: " << teachersObj5.getID() << "\n";
    } else {
        cout << "invalid lesson entered \n"; 
    }
  
    }else if (userChoice == "3") {
    // Open the input file
    ifstream inputFile("assignments .txt");
    // Check if the file is not open
    if (!inputFile.is_open())
        {
            cerr << "Error opening input file.\n";
        }
    // Read the contents of the file and output them
    string line;
    while (getline(inputFile, line))
        {
            cout << line << '\n';
        }
    // Close the input file
    inputFile.close();
    }else {
        cout << "Invalid option entered. Please enter either 1, 2, or 3." << endl;
    }
        //once the task has been preformed, they are asked if they would like to go back to the menu
        int option;
        cout << "Would you like to continue to a different option (1) or end here (2)? ";
        cin >> option; 
        if (option == 1) {
            studentView();
        }else if (option ==2) {
            cout << "Thank you for using our system \n" ;
        } else {
            cout << "invalid entry!" ;
        }
}