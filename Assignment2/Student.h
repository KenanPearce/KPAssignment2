#pragma once
#include "Person.h"
#include <string>
class Student :
    public Person
{
public:
    void addPerson(int personID, std::string fullname, std::string role, std::string path);
    void editPerson(int personID, std::string fullname, std::string role);
};

