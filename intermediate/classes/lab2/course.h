#include "student.h"
#include "teacher.h"


class Course{
  static const int N_STUDENTS = 3;
  string name;
  
  public:
  Course();
  Course(string name);
  ~Course();
  
  Student students[N_STUDENTS];
  Teacher teacher;
};
