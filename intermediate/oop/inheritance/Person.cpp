
#include <string>
#include <iostream>
#include "Person.h"
using namespace std;


Person::Person(){
  firstName = "not provided";
  lastName = "not provided";
  age = -1;
  cout << "  Person::Person() => (" << firstName << "," << lastName<< "," << age << ")" << endl;
}

Person::Person(string firstName, string lastName){
  firstName = firstName;
  lastName = lastName;
  age = -1;
  cout << "  Person::Person(string firstName, string lastName) => (" << firstName << "," << lastName<< "," << age << ")" << endl;
}

Person::Person(string firstName, string lastName, int age){
  firstName = firstName;
  lastName = lastName;
  age = age;
  cout << "  Person::Person(string firstName, string lastName, int age) => (" << firstName << "," << lastName<< "," << age << ")" << endl;
}

Person::~Person(){
  cout << "  Person::~Person() =>(" << firstName << "," << lastName<< "," << age << ")" <<  endl;

}

void Person::sayHello(){
  
}
      
      