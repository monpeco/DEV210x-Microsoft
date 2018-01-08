#include <iostream>
#include "Person.h"
#include "Student.h"
using namespace std;

int main()
{
    Person person;
    person.display();
    
    Student student;
    student.display();

    cout << "A base-class pointer can point to that type of object, or to any derived type of object." << endl;
    Person *p1 = new Person;
    Person *p2 = new Student;
    p2->display();  //This will call the Student display() function
    
    Person &r1 = *p2;
    r1.display();  //This will call the Student display() function, because that's the type of object r refers to at run time.
    
    delete p2;
    
    cout << "End program" << endl;
    return 0;
}