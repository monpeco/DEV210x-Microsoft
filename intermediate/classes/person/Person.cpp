#include <string>
#include <iostream>
#include "Person.h"

Person::Person(){
  cout << "\nThis is the default constructor" << endl;
  cout << "fistName: " << firstName << ", lastName: " << lastName<< ", age: " << age << endl;
}

Person::Person(string fName, string lName){
  cout << "\nThis is the second constructor" << endl;
  firstName = fName;
  lastName = lName;
  cout << "fistName: " << firstName << ", lastName: " << lastName<< ", age: " << age << endl;
}

Person::Person(string fName, string lName, int age){
  cout << "\nThis is the third constructor" << endl;
  firstName = fName;
  lastName = lName;
  age = age;
  cout << "fistName: " << firstName << ", lastName: " << lastName<< ", age: " << age << endl;
}

Person::~Person(){
  
}

void Person::SetFirstName(string fName)
{
    this->firstName = fName;
}

string Person::GetFirstName()
{
    return this->firstName;
}

void Person::SetLastName(string lName)
{
    this->lastName = lName;
}

string Person::GetLastName()
{
    return this->lastName;
}

void Person::SetAge(int age)
{
    if (age > 0)
    {
        this->age = age;
    }
    else
    {
        std::cout << "Please enter a valid age" << std::endl;
    }
}

int Person::GetAge()
{
    return this->age;
}


void Person::sayHello(){
  cout << "\nHello" << endl;
}
