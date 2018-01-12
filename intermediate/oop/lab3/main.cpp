#include <string>
#include <iostream>
#include "person.h" 
#include "student.h" 
#include "teacher.h" 
using namespace std;

int main(){
  
  Person person1;
  person1.outputIdentity();
  person1.outputAge();
  
  Student student1("string first_name", "string last_name", 12, "string race");
  student1.outputIdentity();
  student1.outputAge();

  Teacher teacher1;
  teacher1.outputAge();
  
  /*g++ main.cpp person.cpp student.cpp teacher.cpp -o main.exe*/

  return 0;
}
