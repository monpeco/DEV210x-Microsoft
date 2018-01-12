#include <iostream>
#include "student.h"
using namespace std;

Student::Student(){
  
}

Student::Student(string first_name, string last_name, int age, string race)
: Person(first_name, last_name, age, race){

}

Student::~Student(){
  
}

void Student::outputIdentity(){
    cout << "I am a student" << endl;
}
