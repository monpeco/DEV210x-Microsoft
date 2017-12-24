#include <string>
#include <iostream>
#include "Dog.h"

Dog::Dog(){
  cout << "\nThis is the default constructor" << endl;
  cout << "fistName: " << firstName << ", lastName: " << lastName<< ", age: " << age << endl;
}

Dog::Dog(string fName, string lName){
  cout << "\nThis is the second constructor" << endl;
  firstName = fName;
  lastName = lName;
  cout << "fistName: " << firstName << ", lastName: " << lastName<< ", age: " << age << endl;
}

Dog::Dog(string fName, string lName, int age){
  cout << "\nThis is the third constructor" << endl;
  firstName = fName;
  lastName = lName;
  age = age;
  cout << "fistName: " << firstName << ", lastName: " << lastName<< ", age: " << age << endl;
}

Dog::~Dog(){
  
}

void Dog::sayHello(){
  cout << "\nWoof" << endl;
}
