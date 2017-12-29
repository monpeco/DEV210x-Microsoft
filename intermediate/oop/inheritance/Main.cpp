#include <string>
#include <iostream>
#include "Person.h"
#include "Student.h"
using namespace std;

int main(){
  cout << "\nLets create p1" << endl;
  Person p1("jose","lopez");
  //p1.firstName = "Tom";
  p1.sayHello();
  
  cout << "\nLets create s1" << endl;
  Student s1;
  s1.sayHello();

  return 0;
}