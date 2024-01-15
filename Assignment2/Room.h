#pragma once
#include <string>
using namespace std;

class Room{
public:
    string roomName;
    string roomType;
    bool status;

    void checkStatus(string room);
    void addRoom(string room, string type,string roomStatus, string roomPATH);
    void removeRoom(string roomPATH);
    void editRoom(string roomPATH);
    void viewRoom(string roomPATH);
    void setStatus(string roomPATH);
    void viewLog(string roomLog);
    void simEntry(string roomPATH, string peoplePATH, string roomLog, string time);
};