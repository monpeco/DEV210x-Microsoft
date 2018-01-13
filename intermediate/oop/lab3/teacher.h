#include "person.h"

class Teacher : public Person{
  private:
  
  public:
    Teacher();
    Teacher(string first_name, string last_name, int age, string race);
    ~Teacher();
    virtual void outputIdentity();
};