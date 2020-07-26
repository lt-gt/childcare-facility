#include "Client.hpp"
#include <string>
#include <iostream>

using namespace std;

//Client Base Class
void Client::setID(string ident) {
    ID = ident;
}

void Client::setBill(double b) {
    bill = b;
}

string Client::getID() {
    
    return ID;
}

double Client::getBill() {
    
    return bill;
}

//Parent Derived Class
void Parent::setName(string n) {
    name = n;
}

void Parent::setFinAid(bool fin) {
    finAid = fin;
}

string Parent::getName() {
    
    return name;
}

bool Parent::getFinAid() {
    
    return finAid;
}

void Parent::displayInfo() {
    
    string f;
    if (finAid == 1) {
        f = "Provided";
    } else {
        f = "Not Provided";
    }
    
    cout << "ID: " << ID << endl
    << "Name: " << name << endl
    << "Financial Aid: " << f << endl;
    
}

//Child Derived Class
void Child::setName(string n) {
    name = n;
}

void Child::setAllergies(string a) {
    allergies = a;
}

void Child::setMedications(string m) {
    medications = m;
}

string Child::getName() {
    
    return name;
}

string Child::getAllergies() {
    
    return allergies;
}

string Child::getMedications() {
    
    return medications;
}

void Child::displayInfo() {
    cout << "Child Name: " << name << endl
    << "Allergies: " << allergies << endl
    << "Medications: " << medications << endl;
    
}
