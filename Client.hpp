#ifndef Client_hpp
#define Client_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Client {
protected:
    string ID;
    double bill;

public:
    void setID(string);
    void setBill(double);
    string getID();
    double getBill();
    
};

class Parent : public Client {
private:
    string name;
    bool finAid;

public:
    void setFinAid(bool);
    bool getFinAid();
    
    void setName(string);
    string getName();
    
    void displayInfo();
    
};

class Child : public Parent {
private:
    string name;
    string ID;
    string medications;
    string allergies;

public:
    void setMedications(string);
    string getMedications();
    void setAllergies(string);
    string getAllergies();
    
    void setName(string);
    string getName();
    
    void displayInfo();
    
};

class HoursofChild : public Child {
private:
    int shift;
    double hourlyPay;

public:
    HoursofChild();
    HoursofChild(int, double);
    void setShift(int);
    void setPay(double);
    int getShiftNum();
    string getShiftName();
    double getPay();
    
};
#endif
