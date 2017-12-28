#include <string>
#include <iostream>
#include "Student.h"
using namespace std;

Student::Student(){
    // this line will cause a compiler error    
    //firstName = "Tom";
  cout << "    Student::Student()" << endl;
}

Student::~Student(){
  cout << "    Student::~Student()" << endl;
}
