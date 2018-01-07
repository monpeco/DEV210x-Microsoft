#include "Student.h"

Student::Student(){
  cout << "Student::Student()  => Constructor" << endl;
}

void Student::display() const{
  Person::display();  // Call the base class version of display()
  cout << "Override Person::display() in Student Implementation" << endl;
}