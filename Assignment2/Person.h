#pragma once
#include <string>

class Person
{
public:
    int id;
    std::string name;
    std::string role;

    void addPerson(int personID, std::string fullname, std::string role);
    void removePerson(std::string path);
    void editPerson(int personID, std::string fullname, std::string role, std::string path);
    void viewPeople(std::string path);
};
