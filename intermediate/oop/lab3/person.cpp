#include <string>
#include <iostream>
#include "person.h" 
using namespace std;

Person::Person(){
    first_name = "null";
    last_name = "null";
    age = -1;
    race = "null";
}

Person::~Person(){
  
}

void Person::outputIdentity(){
    
}

void Person::outputAge(){
    cout << "I am " << age << " years old" << endl;
}


