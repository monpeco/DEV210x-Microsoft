#pragma once
#include <string>
class Person
{
  private:
    std::string name;
    int age;
    
  public:
  virtual void display() const;
  
};