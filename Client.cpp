#include "Client.hpp"
#include <string>
#include <iostream>

using namespace std;

//Client Base Class
void Client::setID(int ident) {
    ID = ident;
}

int Client::getID() {
    
    return ID;
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


//Hours of Child Class
HoursofChild::HoursofChild() {
       shift = 0;
       hourlyPay = 0.0;
   }
HoursofChild::HoursofChild(int s, double p) {
    shift = s;
    hourlyPay = p;
}

void HoursofChild::setShift (int s) {
    shift = s;
}

void HoursofChild::setPay(double p) {
    hourlyPay = p;
}

int HoursofChild::getShiftNum() {
    return shift;
}

string HoursofChild::getShiftName() {
    if (shift == 1) //shift1: 8am-12pm
        return "Morning";
    else if (shift == 2) //shift2: 12pm-4om
        return "Afternoon";
    else 
        return "Invalid";
}

double HoursofChild::getPay() {
    return hourlyPay;
}

      
