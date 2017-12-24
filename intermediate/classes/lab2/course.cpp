#include <string>
#include <iostream>
#include "course.h"
using namespace std;

Course::Course(){
}
Course::Course(string name){
  this->name = name;
  cout << "Course name: " << this->name << endl;

}
Course::~Course(){
  
}
