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

    cout << "End program" << endl;
    return 0;
}