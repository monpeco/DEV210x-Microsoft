#pragma once
#include <string>
using namespace std;

class Person{
  private:
    string firstName;
    string lastName;
  
  protected:
    int age;
    
  public:
    Person();
    Person(string firstName, string lastName);
    Person(string firstName, string lastName, int age);
    ~Person();
    
    void SetFirstName(string fName);
    string GetFirstName();
        
    void SetLastName(string lName);
    string GetLastName();
    
    void sayHello();
};
