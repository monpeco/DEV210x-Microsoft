#pragma once
#include "Person.h"
using namespace std;

class Student : public Person{
  public:
    Student();
    ~Student();
    
    void setAge(int age);
    int getAge();
    void sayHello();
};