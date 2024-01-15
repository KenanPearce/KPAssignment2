#include "Cleaner.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <windows.h>

using namespace std;

Cleaner::Cleaner() {
    role = "cleaner";
}

void Cleaner::addPerson(int personID, string fullname, string role, string path) {
    ifstream addPersonFile(path); // open file as read only to see if it exists
    if (addPersonFile.is_open()) {
        ofstream addPersonDB(path, ios::app); // append file to add a new person 
        addPersonDB << personID << "," << fullname << "," << role << "\n";
        addPersonDB.close();
    }
    else {
        cout << "file doesn't exist... Try again.\n";
        ofstream addPersonFile(path); // Creates file if it doesn't exist
    }
}

void Cleaner::removePerson() {
    // Main code in Person.cpp
}

void Cleaner::editPerson(int personID, string fullname, string role) {
    // edit person code
    // To be implemented in the future
}

void Cleaner::viewPeople() {
    // Main code in Person.cpp
}
