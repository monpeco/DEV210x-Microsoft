  /*private:
    string firstName;
    string lastName;
    int age;
    string address;
    string phone;*/
    
#include <string>
#include <iostream>
#include "teacher.h"
using namespace std;

Teacher::Teacher(){
  
}

Teacher::Teacher(string fistName, string lastName, int age, string address, string phone){
  setFirstName(fistName);
  setLastName(lastName);
  setAge(age);
  setAddress(address);
  setPhone(phone);
}

Teacher::~Teacher(){
  
}

void Teacher::setFirstName(string name){
  this->firstName = name;
}
string Teacher::getFirstName(){
  return this->firstName;
}

void Teacher::setLastName(string name){
  this->lastName = name;

}
string Teacher::getLastName(){
  return this->lastName;
}

void Teacher::setAge(int age){
  this->age = age;
}

int Teacher::getAge(){
  return this->age;
}

void Teacher::setAddress(string address){
  this->address = address;
}

string Teacher::getAddress(){
  return this->address;
}

void Teacher::setPhone(string phone){
  this->phone = phone;
}

string Teacher::getPhone(){
  return this->phone;
}

void Teacher::GradeStudent(){
  cout << "Student graduated!" << endl;
}

void Teacher::SitInClass(){
  cout << "Sitting at front of class" << endl;
}