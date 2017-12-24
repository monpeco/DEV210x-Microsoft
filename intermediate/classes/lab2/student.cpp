#include <string>
#include <iostream>
#include "student.h"

using namespace std;
Student::Student(){
  
}

Student::Student(string fistName, string lastName, int age, string address, string phone){
  setFirstName(fistName);
  setLastName(lastName);
  setAge(age);
  setAddress(address);
  setPhone(phone);
  cout << "Student created: " << getFirstName() << endl;
}

Student::~Student(){
  
}

void Student::setFirstName(string name){
  this->firstName = name;
}
string Student::getFirstName(){
  return this->firstName;
}

void Student::setLastName(string name){
  this->lastName = name;

}
string Student::getLastName(){
  return this->lastName;
}

void Student::setAge(int age){
  this->age = age;
}

int Student::getAge(){
  return this->age;
}

void Student::setAddress(string address){
  this->address = address;
}

string Student::getAddress(){
  return this->address;
}

void Student::setPhone(string phone){
  this->phone = phone;
}

string Student::getPhone(){
  return this->phone;
}

void SitInClass(){
  cout << "Sitting in main theater" << endl;
}