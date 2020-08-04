// main.cpp
//

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Client.hpp"

using namespace std;

// Function Prototypes
void displayOptions(char *);
void UV();
void viewClients();
void patientCheck();

Child child[4];
Parent parent[4];

int main() {
    
    // Input Clients into classes from file
    fstream clientFile;
    clientFile.open("Client.txt", ios::in);
    
    string ID; string bill;
    string name1; string aid;
    string name2; string medication; string allergy;
    string blank;
    
    for (int index = 0; index <= 3; index++) {
        
        getline(clientFile, ID);
        getline(clientFile, bill);
        getline(clientFile, name1);
        getline(clientFile, aid);
        getline(clientFile, name2);
        getline(clientFile, medication);
        getline(clientFile, allergy);
        getline(clientFile, blank);
        
        parent[index].setID(ID); parent[index].setBill(stod(bill));
        parent[index].setName(name1); parent[index].setFinAid(stoi(aid));
        child[index].setName(name2);
        child[index].setMedications(medication); child[index].setAllergies(allergy);
        
    }
    
    clientFile.close();
    
    // Menu
    char choice = 'a';
    char * choicePtr;
    choicePtr = &choice;
    int i = 0;
    
    cout << "Welcome to our SCC Childcare Facility!" << endl;
    
    do {
        displayOptions(choicePtr);

        switch (toupper(choice)) {
            case '1':
                UV();
                break;
            case '2':
                cout << parent[0].getName() << endl << child[0].getName() << endl;
                break;
            case '3':
                cout << "Chose S" << endl;
                break;
            case '4':
                patientBilling();
                break;
            case 'E':
                cout << "Have a good day!" << endl;
                i = -1;
                break;
                
            default:
                cout << "Invalid choice, try again" << endl;
                break;
        }
    
        } while (i != -1);
        
    return 0;
}

void displayOptions(char * c) {
    char choice;
    
    cout << endl;
    
    
    cout << "1 - Update/View Client Information" << endl;
    cout << "2 - Check In Client" << endl;
    cout << "3 - Search Client" << endl;
    cout << "4 - Base Bill Calculation" <<endl << endl;
    
    cout << "Type choice # or E to exit -> ";
    cin >> choice;
    
    *c = choice;
}

void UV() {
    char choice;
    int i = 0;
    
    do {
    
    cout << endl << "U - Update" << endl
    << "V - View" << endl
    << "E - Go back" << endl << endl
    << "Would you like to update or view a clients information? -> ";
    cin >> choice;
    
    switch (toupper(choice)) {
            case 'U':
                cout << "chose " << choice;
                i = -1;
                break;
            
            case 'V':
            viewClients();
                i = -1;
                break;
            
            case 'E':
                cout << "Chose " << choice;
                i = -1;
                break;
            
            default:
                cout << "Invalid Choice" << endl;
            
        }
    } while (i != -1);
}

void viewClients() {
    string id;
    int i = 0;
    cout << "Please type the identification # of the client you wish to view -> ";
    cin >> id;
    cout << endl;
    
    do {
        if (id == "a1") {
            parent[0].displayInfo();
            child[0].displayInfo();
            i = -1;
        } else if (id == "a2") {
            parent[1].displayInfo();
            child[1].displayInfo();
            i = -1;
        } else if (id == "a3") {
            parent[2].displayInfo();
            child[2].displayInfo();
            i = -1;
        } else if (id == "a4") {
            parent[3].displayInfo();
            child[3].displayInfo();
            i = -1;
        } else if (id == "E" || id == "e") {
            i = -1;
        } else {
            cout << "Invalid choice, IDs are case sensitive" << endl;
        }
        
    } while (i != -1);
    
 void patientBilling() {
	
	double checkIn, checkOut, totalTime;
	double timeHold;
	double wage = 12;
	double bill;
	
	cout << "Enter patient check in time: (24 hour clock, no semicolon; 0000)" << endl;
	cin >> checkIn;
	cout << "Enter patient check out time: (24 hour clock, no semicolon; 0000)" << endl;
	cin >> checkOut;
	
	totalTime = checkOut - checkIn;
	
	cout << "The total time for this session is: " << totalTime << endl;
	
	timeHold = totalTime/100;
	bill = timeHold * wage;
	
	cout << "Your base bill is $" << bill << endl<<"Please consult the front desk for medication prices"<< endl;
}
    
}
