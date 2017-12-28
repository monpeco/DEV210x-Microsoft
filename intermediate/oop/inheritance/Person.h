#pragma once
#include <string>
using namespace std;

class Person{
  private:
    string firstName;
    string lastName;
    int age;
    
  public:
    Person();
    Person(string firstName, string lastName);
    Person(string firstName, string lastName, int age);
    ~Person();
    void sayHello();
};
