#pragma once
#include "Person.h"
#include <string>
class Staff : 
	public Person
{
public:
    Staff();
    void addPerson(int personID, std::string fullname, std::string role, std::string path);
    void removePerson();
    void editPerson(int personID, std::string fullname, std::string role);
    void viewPeople();
};

