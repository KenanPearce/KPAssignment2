#pragma once
#include "Person.h"
#include <string>

class Cleaner :
	public Person
{
public:
    Cleaner();
    void addPerson(int personID, std::string fullname, std::string role, std::string path);
    void removePerson();
    void editPerson(int personID, std::string fullname, std::string role);
    void viewPeople();
};

