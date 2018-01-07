#include <iostream>
#include "Person.h"
using namespace std;

Person::Person(){
  // Any destruction code for Person object.
  cout << "Person::Person()  => Constructor" << endl;
}

Person::~Person(){
  // Any destruction code for Person object.
  cout << "Person::~Person()" << endl;
}

void Person::display() const{
  cout << "Person::display()" << endl;
}