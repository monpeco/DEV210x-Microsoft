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

    cout << "End program" << endl;
    return 0;
}