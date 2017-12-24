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

void Person::sayHello(){
  cout << "\nHello" << endl;
}
