#include <string>
#include <iostream>
#include "course.h"

using namespace std;

int main(){
  Student Student1("Joe","Doe",12,"Main St","555-6954-8547");
  Student Student2("Ted","Williams",18,"Lake St","555-7774-4561");
  Student Student3("David","Ortiz",17,"Boston St","555-0101-0127");
  
  Course course("Intermediate C++");
  course.students[0] = Student1;
  course.students[1] = Student2;
  course.students[2] = Student3;

  Teacher teacher("Ty","Cobb",17,"Detroit Av","454-7841-0000");
  course.teacher = teacher;
  
  course.teacher.GradeStudent();

  cout << "End Program." << endl;
  return 0;
}