#include "Room.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <windows.h>
#include <vector>

using namespace std;


// Implementation of Room class member functions
void Room::checkStatus(string room) {
    // check room status
    // TO BE IMPLEMENTED IN THE FUTURE
}

// Add a room into the locally stored txt file
// TODO: PREVENT THE SAME ROOM BEING STORED MULTIPLE TIMES
void Room::addRoom(string room, string type, string status, string roomPATH) {
    // w3school. cpp files. Available at: https://www.w3schools.com/cpp/cpp_files.asp (Accessed: 10.1.24)
    ifstream addRoomFile(roomPATH);
    if (addRoomFile.is_open()) {
        ofstream addLog(roomPATH, ios::app);
        addLog << room << "," << type << "," << status << "\n";
        addLog.close();
    }
    else {
        cout << "file doesn't exist... Try again.";
        ofstream addRoomFile(roomPATH);
        addRoomFile.close();
    }
}

void Room::removeRoom(string roomPATH) {
    // Portfolio Courses. Available at: https://www.youtube.com/watch?v=Ka5Rgfxw9JM (Accessed: 11.1.24)
    int lineNum;
    cout << "\n What room would you like to remove? ";
    cin >> lineNum;
    vector<string> lines;
    string line;

    fstream readRoomFile;
    readRoomFile.open(roomPATH);
    if (readRoomFile.fail()) {
        cout << "An error occurred.";
    }
    while (getline(readRoomFile, line)) {
        lines.push_back(line);
    }
    readRoomFile.close();
    
    ofstream removeRoomFromFile(roomPATH);
    if (removeRoomFromFile.fail()) {
        cout << "An error occurred.";
    }
    lineNum--;
    for (int i = 0; i < lines.size(); i++) {
        if (i != lineNum) {
            removeRoomFromFile << lines[i] << endl;
        }
    }
    removeRoomFromFile.close();

}

void Room::editRoom(string roomPATH) {
    int lineNum;
    cout << "\n What room would you like to edit? ";
    cin >> lineNum;
    // TO BE COMPLETED IN THE FUTURE
    
}

void Room::viewRoom(string roomPATH) {
    cout << "\n";

    ifstream readRoomDB(roomPATH);
    if (readRoomDB.is_open()) {
        cout << readRoomDB.rdbuf();
        readRoomDB.close();
    }
    else {
        cout << "An error occurred.";
    }
    cout << "\n";
}

void Room::setStatus(string roomPATH) {
    // Chatgpt. Available: https://chat.openai.com/ (Accessed: 12/1/24)
    int lineNum;
    cout << "\nWhich room's status would you like to change? ";
    cin >> lineNum;

    vector<string> lines;
    string line, newStatus;

    ifstream readRoomFile(roomPATH);
    if (readRoomFile.fail()) {
        cout << "An error occurred while opening the file.";
        return;
    }

    while (getline(readRoomFile, line)) {
        lines.push_back(line);
    }
    readRoomFile.close();

    lineNum--;  // Adjust for zero-based indexing
    if (lineNum < 0 || lineNum >= lines.size()) {
        cout << "Invalid room number. Please try again.";
        return;
    }

    // Extract room information
    stringstream ss(lines[lineNum]);
    string roomName, roomType, roomStatus;
    getline(ss, roomName, ',');
    getline(ss, roomType, ',');
    getline(ss, roomStatus);

    // Display current room information
    cout << "Current status of room " << roomName << ": " << roomStatus << endl;

    // Update room status
    cout << "Enter the new status for the room: ";
    cin >> newStatus;

    // Modify the status in the vector
    lines[lineNum] = roomName + "," + roomType + "," + newStatus;

    // Save the updated information back to the file
    ofstream updateRoomFile(roomPATH);
    if (updateRoomFile.fail()) {
        cout << "An error occurred while opening the file for writing.";
        return;
    }

    for (int i = 0; i < lines.size(); i++) {
        updateRoomFile << lines[i] << endl;
    }
    updateRoomFile.close();

    cout << "Room status updated successfully." << endl;
}

// Implementation for viewing access/denied access log
// TODO: Allow to view different days logs
void Room::viewLog(string roomLog) {
    cout << "\n";

    ifstream readLog(roomLog);
    if (readLog.is_open()) {
        cout << readLog.rdbuf();
        readLog.close();
    }
    else {
        cout << "An error occurred.";
    }
    cout << "\n";
}

void Room::simEntry(string roomPATH,string peoplePATH, string roomLog, string time) {
    // |----- Collect data from ROOM_LIST -----|
    int roomNum;
    cout << "\nWhat room do you want the person to enter: ";
    cin >> roomNum;

    vector<string> roomLines; // stores all the file lines into a vector
    string roomLine; // 

    ifstream readRoomFile(roomPATH);
    if (readRoomFile.fail()) {
        cout << "An error occurred while opening the file.";
        return;
    }

    while (getline(readRoomFile, roomLine)) {
        roomLines.push_back(roomLine);
    }
    readRoomFile.close();

    roomNum--;
    if (roomNum < 0 || roomNum >= roomLines.size()) {
        cout << "Invalid room number. Please try again.";
        return;
    }

    // Extract room information
    stringstream roomSS(roomLines[roomNum]);
    string roomName, roomType, roomStatus;
    getline(roomSS, roomName, ',');
    getline(roomSS, roomType, ',');
    getline(roomSS, roomStatus);


    // |----- Collect data from ID_CARD_LIST -----|

    int personNum;
    cout << "\nWho would you like to enter the room: ";
    cin >> personNum;

    vector<string> peopleLines;
    string peopleLine;

    ifstream readPeopleFile(peoplePATH);
    if (readPeopleFile.fail()) {
        cout << "An error occurred while opening the file.";
        return;
    }

    while (getline(readPeopleFile, peopleLine)) {
        peopleLines.push_back(peopleLine);
    }
    readPeopleFile.close();

    personNum--; 
    if (personNum < 0 || personNum >= peopleLines.size()) {
        cout << "Invalid room number. Please try again.";
        return;
    }

    // Extract people information
    stringstream peopleSS(peopleLines[personNum]);
    string uID, fullname, role;
    getline(peopleSS, uID, ',');
    getline(peopleSS, fullname, ',');
    getline(peopleSS, role);

    ifstream readLogFile(roomLog);
    if (readLogFile.is_open()) {
        ofstream updateLogFile(roomLog, ios::app);
        // |------ Staff Permissions ------|

        if (role == "staff") {
            // Lecture Hall
            if (roomType == "lecture" && roomStatus == "normal") {
                cout << "Access Granted! \n";
                updateLogFile << "Access Granted - " << uID << " - " << fullname << " - " << roomName << " - " << time << "\n"; // store data in log file
            }

            // Teaching Room
            else if (roomType == "teaching" && roomStatus == "normal") {
                cout << "Access Granted \n";
                updateLogFile << "Access Granted - " << uID << " - " << fullname << " - " << roomName << " - " << time << "\n";
            }

            // Staff Room
            else if (roomType == "staff" && roomStatus == "normal") {
                cout << "Access Granted \n";
                updateLogFile << "Access Granted - " << uID << " - " << fullname << " - " << roomName << " - " << time << "\n";
            }

            // Other Outcomes
            else {
                cout << "Access Denied \n";
                updateLogFile << "Access Denied - " << uID << " - " << fullname << " - " << roomName << " - " << time << "\n";
            }
        }
        // |------ Student Permissions ------|
        else if (role == "student") {
            // Lecture Hall
            if (roomType == "lecture" && roomStatus == "normal") {
                cout << "Access Granted \n";
                updateLogFile << "Access Granted - " << uID << " - " << fullname << " - " << roomName << " - " << time << "\n";
            }

            // Teaching Room
            else if (roomType == "teaching" && roomStatus == "normal") {
                cout << "Access Granted \n";
                updateLogFile << "Access Granted - " << uID << " - " << fullname << " - " << roomName << " - " << time << "\n";
            }

            // Other Outcomes
            else {
                cout << "Access Denied \n";
                updateLogFile << "Access Denied - " << uID << " - " << fullname << " - " << roomName << " - " << time << "\n";
            }
        }
        // |------ Cleaner Permissions ------|

        else if (role == "cleaner") {
            // Lecture Hall
            if (roomType == "lecture" && roomStatus == "normal") {
                cout << "Access Granted \n";
                updateLogFile << "Access Granted - " << uID << " - " << fullname << " - " << roomName << " - " << time << "\n";
            }

            // Teaching Room
            else if (roomType == "teaching" && roomStatus == "normal") {
                cout << "Access Granted \n";
                updateLogFile << "Access Granted - " << uID << " - " << fullname << " - " << roomName << " - " << time << "\n";
            }

            // Staff Room
            else if (roomType == "staff" && roomStatus == "normal") {
                cout << "Access Granted \n";
                updateLogFile << "Access Granted - " << uID << " - " << fullname << " - " << roomName << " - " << time << "\n";
            }

            // Other Outcomes
            else {
                cout << "Access Denied \n";
                updateLogFile << "Access Denied - " << uID << " - " << fullname << " - " << roomName << " - " << time << "\n";
            }
        }

        // |------ Manager Permissions ------|

        else if (role == "manager") {
            // All rooms but only in NORMAL mode
            if (roomStatus == "normal") {
                cout << "Access Granted \n";
                updateLogFile << "Access Granted - " << uID << " - " << fullname << " - " << roomName << " - " << time << "\n";
            }

            // Rooms are set to emergancy mode
            else {
                cout << "Access Denied \n";
                updateLogFile << "Access Denied - " << uID << " - " << fullname << " - " << roomName << " - " << time << "\n";
            }
        }

        // |------ Security Permissions ------|

        // All rooms but only in NORMAL mode
        else if (role == "security") {
            cout << "Access Granted \n";
            updateLogFile << "Access Granted - " << uID << " - " << fullname << " - " << roomName << " - " << time << "\n";
        }

        // |------ Emergancy Responder Permissions ------|
        else if (role == "emergancy") {
            if (roomStatus == "emergancy") {
                cout << "Access Granted \n";
                updateLogFile << "Access Granted - " << uID << " - " << fullname << " - " << roomName << " - " << time << "\n";
            }

            // Rooms are set to normal mode
            else {
                cout << "Access Denied \n";
                updateLogFile << "Access Denied - " << uID << " - " << fullname << " - " << roomName << " - " << time << "\n";
            }
        }

        // Error with permissions management
        else {
            cout << "An error occurred.\n";
        }

        updateLogFile.close();
    }
    else {
        cout << "file doesn't exist... Try again.\n";
    }
}
