#include <string>
#include <iostream>
#include "Student.h"
using namespace std;

Student::Student():Person("Tom", "Thumb"){
    // this line will cause a compiler error    
    //firstName = "Tom";
  cout << "    Student::Student()" << endl;
}

Student::~Student(){
  cout << "    Student::~Student()" << endl;
}

void Student::setAge(int age)
{
    if (age < 5)
    {
        cout << "Student age needs to at least 5 years old." << endl;
    }
    else
    {
       this->age = age;
    }
}

int Student::getAge()
{
    return this->age;
}

void Student::sayHello()
{
    cout << "Hey, how's it goin'?" << endl;
}
