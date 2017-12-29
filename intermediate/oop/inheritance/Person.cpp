
#include <string>
#include <iostream>
#include "Person.h"
using namespace std;


Person::Person(){
  firstName = "[not provided]";
  lastName = "[not provided]";
  age = -1;
  cout << "  Person::Person() => (" << firstName << "," << lastName<< "," << age << ")" << endl;
}

Person::Person(string firstName, string lastName){
  this->firstName = firstName;
  this->lastName = lastName;
  this->age = -1;
  cout << "  Person::Person(string firstName, string lastName) => (" << firstName << "," << lastName<< "," << age << ")" << endl;
}

Person::Person(string firstName, string lastName, int age){
  this->firstName = firstName;
  this->lastName = lastName;
  this->age = age;
  cout << "  Person::Person(string firstName, string lastName, int age) => (" << firstName << "," << lastName<< "," << age << ")" << endl;
}

Person::~Person(){
  cout << "Destructor called as a result of the delete keyword being used" << endl;
  cout << "  Person::~Person() =>(" << firstName << "," << lastName<< "," << age << ")" <<  endl;

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

void Person::sayHello(){
  cout << "  " << firstName << " says Hello!!" <<  endl;

}
      
      