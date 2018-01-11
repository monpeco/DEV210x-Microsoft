#include <string>
#include <iostream>
#include "person.h" 
#include "student.h" 
#include "teacher.h" 
using namespace std;

int main(){
  
  Person person1;
  
  person1.outputAge();
  
  Student student1;
  student1.outputAge();

  Teacher teacher1;
  teacher1.outputAge();

  return 0;
}
