#include <iostream>

using namespace std;

void survey() {
    //SOFTWARE USED IN PARTS OF THIS SECTION
  try {
  	string response;
    cout << "\nWould you like to take part in a short survey? (y/n) \n";
    cin >> response;
    if (response == "y" || response == "Y" ) {
      int answer;
      string response;
      cout << "What would you rate the system from 1-5?: ";
      cin >> answer;
      if (answer < 2) {
            // open the file for appending
            ofstream outputFile("improvements.txt", ios::app); 

            if (!outputFile.is_open()) {
                cerr << "Error opening output file.\n";
            }
            // write a line to the file
            string improvements;
            cin.ignore(); // ignore the newline character from previous input
            cout << "What could we impove on? : \n";
            getline(cin, improvements);// adds line to file including spaces 
            outputFile << improvements + "\n\n"; // add a newline to create a blank line between entries
            // close the file
            outputFile.close();
            cout << "Improvement suggestion has successfully been added! "<< endl;
      }
    } 
    else if (response == "n" || response == "N" ) { 
            cout << "Thanks for your time, have a good day!";
    } else { 
      throw string(response);
    }
  }
  catch (string myInput) {
    cout << "Error character: " << myInput;
    cout << "\nPlease enter y or n.";
    survey();
  }
  }

