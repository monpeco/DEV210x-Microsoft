#include <string>
using namespace std;

//first_name, last_name, age, race, phone, as examples

class Person{
  private:
    string first_name;
    string last_name;
    int age;
    string race;
  
  protected:
    string phone;

  public:
    Person();
    ~Person();
    virtual void outputIdentity();
};