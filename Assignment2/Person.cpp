#include "Person.h"
#include <conio.h>       
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <windows.h>
#include <vector>

using namespace std;

// Function definitions
void Person::addPerson(int personID, string fullname, string role) {
    // Implementation for adding a person
    // Main implenetation are in the child classes
}

// Portfolio Courses. Available at: https://www.youtube.com/watch?v=Ka5Rgfxw9JM (Accessed: 11.1.24)
void Person::removePerson(string path) {
    // Implementation for removing a person
    int lineNum;
    cout << "\n What person would you like to remove? ";
    cin >> lineNum;
    vector<string> lines; // store each line into a vector
    string line;

    fstream readPersonFile; // reads the person file
    readPersonFile.open(path);
    if (readPersonFile.fail()) {
        cout << "An error occurred."; // failing to open file
    }
    while (getline(readPersonFile, line)) {
        lines.push_back(line); // each line is added to vector
    }
    readPersonFile.close();

    ofstream removePersonFromFile(path); // edit file
    if (removePersonFromFile.fail()) {
        cout << "An error occurred."; // fail to open file
    }
    lineNum--; // move the users index back to back the counting accurate
    for (int i = 0; i < lines.size(); i++) {
        if (i != lineNum) {
            removePersonFromFile << lines[i] << endl; // grabs every line except the one you want to remove
        }
    }
    removePersonFromFile.close();

}

void Person::editPerson(int personID, string fullname, string role, string path) {
    // Implementation for editing a person

    int lineNum;
    cout << "\n What person would you like to edit? ";
    cin >> lineNum;

    // TO BE ADDED IN THE FUTURE
}

void Person::viewPeople(string path) {
    // Implementation for viewing people
    cout << "\n";

    ifstream readPeopleDB(path); // open file to read
    if (readPeopleDB.is_open()) {
        cout << readPeopleDB.rdbuf(); // read every line in the file
        readPeopleDB.close();
    }
    cout << "\n";
}
