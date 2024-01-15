// Date Created: 14/12/23
// By: Kenan-James Pearce

#include <conio.h>       
#include <iostream>
#include <fstream> // used for file handling
#include <string>
#include <sstream> // used for stringstream
#include <ctime> // used to get the time
#include <iomanip>
#include <windows.h>

// include classes
#include "Room.h" 
#include "Person.h"
#include "Student.h"
#include "Staff.h"
#include "Manager.h"
#include "Cleaner.h"
#include "Security.h"
#include "Emergancy.h"


using namespace std;

// Function to get current date
string date() {
    tm dateTime;
    time_t now = time(0);
    localtime_s(&dateTime, &now);

    stringstream ss;
    ss << put_time(&dateTime, "%d_%m_%Y"); // gets the day, month, year when the function is called 

    string formattedDate = ss.str(); // Main code in Person.cpp
    return formattedDate;
}

// Function to get current time
string time() {
    tm cTime;
    time_t now = time(0);
    localtime_s(&cTime, &now);

    stringstream ss;
    ss << put_time(&cTime, "%H:%M:%S"); // gets the hour, minute, second when the function is called

    string formattedTime = ss.str(); // convert stringstream to str
    return formattedTime;
}

// Function to create a daily file
void createDailyFile(string directory, string date) {
    ifstream dailyFile(directory);
    string text;

    if (dailyFile.is_open()) {
        ofstream addLog(directory, ios::app); 
        addLog.close();
    }
    else {
        ofstream cDailyFile(directory); // creates the daily file in specific directory
    }

}

int main()
{
    bool loop = true;
    string userInput;
    string currentDate = date();
    string roomName, roomStatus, roomType;
    string firstname, lastname, fullname, personRole;
    int personID;

    // Change path directory to where you want the log file to be stored
    string peopleDB = "logs/ID_CARD_LIST.txt";
    string roomDB = "logs/ROOM_LIST.txt";
    string roomLog = "logs/room_access_log_" + currentDate + ".txt";
    createDailyFile(roomLog, currentDate);

    while (loop = true) {
        cout << "Welcome to the college locking system" << endl;
        cout << "Enter '1' to add a Person" << endl;
        cout << "Enter '2' to remove a Person" << endl;
        cout << "Enter '3' to edit a Person" << endl;
        cout << "Enter '4' to add a Room" << endl;
        cout << "Enter '5' to remove a Room" << endl;
        cout << "Enter '6' to edit a Room" << endl;
        cout << "Enter '7' to view Person list"<< endl;
        cout << "Enter '8' to view Room list" << endl;
        cout << "Enter '9' to view log file" << endl;
        cout << "Enter '10' to change the status of a room" << endl;
        cout << "Enter '11' to simulate entry of a room" << endl;

        cout << "Enter '12' to exit." << endl;

        cin >> userInput;

        // initializing objects
        Room aRoom;
        Cleaner aCleaner;
        Manager aManager;
        Security aSecurity;
        Staff aStaff;
        Student aStudent;
        Person people;
        Emergancy emergancyResponder;

        // Add a person
        if (userInput == "1") {
            cout << "Please enter their firstname: ";
            cin >> firstname;
            cout << "\nPlease enter their lastname: ";
            cin >> lastname;
            fullname = firstname + " " + lastname;

            cout << "\nPlease enter their role: ";
            cin >> personRole;
            cout << "\nPlease enter their ID number: ";
            cin >> personID;

            // Add Cleaner
            if (personRole == "cleaner") {
                aCleaner.addPerson(personID, fullname, personRole, peopleDB);
            }
            else if (personRole == "manager") {
                aManager.addPerson(personID, fullname, personRole, peopleDB);
            }
            else if (personRole == "security") {
                aSecurity.addPerson(personID, fullname, personRole, peopleDB);
            }
            else if (personRole == "staff") {
                aStaff.addPerson(personID, fullname, personRole, peopleDB);
            }
            else if (personRole == "student") {
                aStudent.addPerson(personID, fullname, personRole, peopleDB);
            }
            else if (personRole == "emergancy") {
                emergancyResponder.addPerson(personID, fullname, personRole, peopleDB);
            }
            else {
                cout << "\n Cannot find role." << endl;
            }
        }

        // remove a person
        else if (userInput == "2") {
            people.viewPeople(peopleDB);
            people.removePerson(peopleDB);
        }

        // edit person
        else if (userInput == "3") {
            // TO BE ADDED IN THE FUTURE
        }

        // Add a room
        else if (userInput == "4") {
            cout << "Please enter the room name: ";
            cin >> roomName;
            cout << "\nPlease enter the room type: ";
            cin >> roomType;
            if (roomType == "lecture" || roomType == "teaching" || roomType == "staff" || roomType == "secure") {
                cout << "\nPlease enter the status of the room: ";
                cin >> roomStatus;

                aRoom.addRoom(roomName, roomType, roomStatus, roomDB);
            }
            else {
                cout << "\nInvalid room type. \n";
            }
        }

        // remove a room
        else if (userInput == "5") {
            aRoom.viewRoom(roomDB);
            aRoom.removeRoom(roomDB);
        
        }

        // edit a room
        else if (userInput == "6") {
            // TO BE ADDED IN THE FUTURE
        }

        // view person list
        else if (userInput == "7") {
            people.viewPeople(peopleDB);
        }

        // view Room list
        else if (userInput == "8") {
            aRoom.viewRoom(roomDB);
        }

        // view daily access log
        else if (userInput == "9") {
            aRoom.viewLog(roomLog);
        }

        // change room status
        else if (userInput == "10") {
            aRoom.viewRoom(roomDB);
            aRoom.setStatus(roomDB);
        }

        // Simulate entry
        else if (userInput == "11") {
            aRoom.viewRoom(roomDB);
            people.viewPeople(peopleDB);
            aRoom.simEntry(roomDB, peopleDB, roomLog, time());
        }

        else if (userInput == "12") {
            loop = false;
            break;
        }

        else {
            // any other input is counted as an error
            cout << "Input invalid.\n";
        }
    }

}
