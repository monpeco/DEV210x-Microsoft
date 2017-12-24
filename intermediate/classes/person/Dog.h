#include <string>

using namespace std;

class Dog{
  private:
    string firstName;
    string lastName;
    int age;
    
  public:
    Dog();
    Dog(string fName, string lName);
    Dog(string fName, string lName, int age);
    ~Dog();
    void sayHello();
};