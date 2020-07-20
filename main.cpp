// main.cpp
//

#include <iostream>

using namespace std;

// Function Prototypes
void displayOptions(char *);

int main() {
    char choice = 'a';
    char * choicePtr;
    choicePtr = &choice;
    int i = 0;
    
    cout << "Welcome to our SCC Childcare Facility!" << endl;
    
    // Loop to verify correct choice
    do {
        displayOptions(choicePtr);
        
        switch (choice) {
            case 'R':
            case 'r':
            case 'C':
            case 'c':
            case 'S':
            case 's':
            case 'E':
            case 'e':
                i = -1;
                break;
                
            default:
                i = 0;
                break;
        }
        
    } while (i != -1);
    
    // Menu
    switch (choice) {
        case 'R':
        case 'r':
            cout << "Chose R" << endl;
            break;
        case 'C':
        case 'c':
            cout << "Chose C" << endl;
            break;
        case 'S':
        case 's':
            cout << "Chose S" << endl;
            break;
            
        default:
            cout << "Chose E" << endl;
            break;
    }
    
    return 0;
}

void displayOptions(char * c) {
    char choice;
    
    cout << endl;
    
    cout << "R - Register/Update Client Information" << endl
    << "C - Check In Client" << endl
    << "S - Search Client" << endl << endl;
    
    cout << "Type R, C, S, or E to exit -> ";
    cin >> choice;
    
    *c = choice;
}
