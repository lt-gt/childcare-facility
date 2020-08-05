// main.cpp
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Client.hpp"

using namespace std;

// Function Prototypes
void displayOptions(char *);
void UV();
void updateClients();
void viewClients();
void patientBilling();

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
        getline(clientFile, name1);
        getline(clientFile, aid);
        getline(clientFile, name2);
        getline(clientFile, medication);
        getline(clientFile, allergy);
        getline(clientFile, blank);
        
        parent[index].setID(stoi(ID));
        parent[index].setName(name1);
        parent[index].setFinAid(stoi(aid));
        child[index].setName(name2);
        child[index].setMedications(medication);
        child[index].setAllergies(allergy);
        
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
                cout << "Chose 2";
                break;
            case '3':
                cout << "Chose 3" << endl;
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
            updateClients();
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
    int id;
    int i = 0;
    
    do {
        cout << "Please type the identification # -> ";
        cin >> id;
        cout << endl;
        
        switch (id) {
            case 1:
            case 2:
            case 3:
            case 4:
                i = 1;
                break;
                
            default:
                cout << "Invalid Choice\n";
                i = 0;
                break;
        }
        
    } while (i != 1);
    
    parent[id - 1].displayInfo();
    child[id - 1].displayInfo();
    
}

void updateClients() {
    int id;
    int i = 0;
    
    do {
        cout << "Please type the identification # -> ";
        cin >> id;
        cout << endl;
        
        switch (id) {
            case 1:
            case 2:
            case 3:
            case 4:
                i = 1;
                break;
                
            default:
                cout << "Invalid Choice\n";
                i = 0;
                break;
        }
        
    } while (i != 1);
    
    id -= 1;
    
    parent[id].displayInfo();
    child[id].displayInfo();
    
    int c = 0;
    i = 0;
    string update;
    
    do {
        cout << endl;
        
        cout << "1. Name" << endl
        << "2. Child Name" << endl
        << "3. Allergies" << endl
        << "4. Medications" << endl;
        
        cout << endl << "What would you like to update -> ";
        cin >> c;
        cout << "Type new info -> ";
        cin >> update;
        
        switch (c) {
            case 1:
                parent[id].setName(update);
                i = 1;
                break;
                
                case 2:
                child[id].setName(update);
                i = 1;
                break;
                
                case 3:
                child[id].setAllergies(update);
                i = 1;
                break;
                
                case 4:
                child[id].setMedications(update);
                i = 1;
                break;
                
            default:
                cout << "Invalid Choice";
                i = 0;
                break;
                
        }
        
    } while (i != 1);
    
    
    
}

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
    
    cout << "Your base bill is $" << bill << endl << "Please consult the front desk for medication prices" << endl;
}
