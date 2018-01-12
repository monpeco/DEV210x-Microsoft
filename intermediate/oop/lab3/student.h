#include "person.h"

class Student : public Person{
  private:
  
  public:
    Student();
    Student(string first_name, string last_name, int age, string race);
    ~Student();
};