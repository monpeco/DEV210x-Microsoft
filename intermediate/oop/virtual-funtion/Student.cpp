#include "Student.h"

void Student::display() const{
  Person::display();  // Call the base class version of display()
  cout << "Override Person::display() in Student Implementation" << endl;
}