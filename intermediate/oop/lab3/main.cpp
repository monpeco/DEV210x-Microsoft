#include <string>
#include <iostream>
#include "person.h" 
#include "student.h" 
#include "teacher.h" 
using namespace std;

int main(){
  
  cout << "Create person1" << endl;

  Person person1;
  person1.outputIdentity();
  person1.outputAge();
  
  cout << "\nCreate student1" << endl;

  Student student1("string first_name", "string last_name", 12, "string race");
  student1.outputIdentity();
  student1.outputAge();

  cout << "\nCreate teacher1" << endl;

  Teacher teacher1;
  teacher1.outputIdentity();
  teacher1.outputAge();

  /*g++ main.cpp person.cpp student.cpp teacher.cpp -o main.exe*/

  return 0;
}
