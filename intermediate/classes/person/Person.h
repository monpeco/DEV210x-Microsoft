#include <string>

using namespace std;

class Person{
  private:
    string firstName;
    string lastName;
    int age;
    
  public:
    Person();
    Person(string fName, string lName);
    Person(string fName, string lName, int age);
    ~Person();
    void sayHello();
};