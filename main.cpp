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
    
    // Loop Menu
    do {
        displayOptions(choicePtr);

        switch (toupper(choice)) {
            case 'R':
                cout << "Chose R" << endl;
                break;
            case 'C':
                cout << "Chose C" << endl;
                break;
            case 'S':
                cout << "Chose S" << endl;
                break;
            case 'E':
                cout << "Chose E" << endl;
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
    
    cout << "R - Register/Update Client Information" << endl
    << "C - Check In Client" << endl
    << "S - Search Client" << endl << endl;
    
    cout << "Type R, C, S, or E to exit -> ";
    cin >> choice;
    
    *c = choice;
}
