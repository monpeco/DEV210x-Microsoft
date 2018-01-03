#pragma once
#include <iostream>
#include "Person.h"
using namespace std;

class Student : public Person{
  private:
    string course;
  
  public:
    virtual void display() const;     // Override function from base class.
};