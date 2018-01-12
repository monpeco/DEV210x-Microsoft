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

Person::Person(string first_name, string last_name, int age, string race){
    this->first_name = first_name;
    this->last_name = last_name;
    this->age = age;
    this->race = race;
}

Person::~Person(){
  
}

void Person::outputIdentity(){
    cout << "outputIdentity not implemented" << endl;
}

void Person::outputAge(){
    cout << "I am " << age << " years old" << endl;
}


