#include <iostream>
#include "teacher.h"
using namespace std;

Teacher::Teacher(){
  
}

Teacher::Teacher(string first_name, string last_name, int age, string race)
: Person(first_name, last_name, age, race){
  
}

Teacher::~Teacher(){
  
}

void Teacher::outputIdentity(){
  cout << "I am a teacher" << endl;
}

void Teacher::outputAge(){
  cout << "I am a teacher and ";
  Person::outputAge();
}