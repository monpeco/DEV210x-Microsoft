#include <string>
#include <iostream>
#include "Person.h"
#include "Dog.h"
#include "Geometry.h"

using namespace std;

int main(){
  
  Person *pOne = new Person();
  Person *pTwo = new Person("joe", "doe");
  Person *pThree = new Person("joe", "doe", 35);
  
  Person p;
  p.sayHello();
  
  p.SetFirstName("Gerry");
  cout << p.GetFirstName() << endl;
  
  // this line will output an invalid age message due to the 
  // validation check in the SetAge() function
  p.SetAge(-5);
        
  Person &pRef = p;
  pRef.sayHello();
  
  Dog dog;
  dog.sayHello();
  
  cout << "\nGeometry::PI: " << Geometry::PI << endl; 
  cout << "Geometry::area(10.0): " << Geometry::area(10.0) << endl; 
  
  cout << "\nEnd program" << endl;
  
  return 0;
}
