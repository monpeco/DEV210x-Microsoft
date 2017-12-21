#include <string>

// 23. Create a simple class in your C++ application called Person.
class Person
{
  public:
  // 24. Give Person member variables for name, age, height, and weight.  
  // Feel free to make these private with public accessors or make them
  //public without accessors.  It is not important for this exercise.
    std::string name;
    unsigned int age;
    double height;
    double weight;

  Person();
  ~Person();
};
