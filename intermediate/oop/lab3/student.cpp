#include <iostream>
#include "student.h"
using namespace std;

Student::Student(){
  cout << "Student()" << endl;
}

Student::Student(string first_name, string last_name, int age, string race)
: Person(first_name, last_name, age, race){

}

Student::~Student(){
  
}

void Student::outputIdentity(){
  cout << "I am a student" << endl;
}

void Student::outputAge(){
  cout << "I am a student" << endl;
  Person::outputAge();
}
//Override the Student's OutputAge() virtual method to display the text "I am a student" and then calls the Person class's OutputAge() method
