#include <string>
#include <iostream>
#include "Person.h"

using namespace std;

int main(){
  
  Person *pOne = new Person();
  Person *pTwo = new Person("joe", "doe");
  Person *pThree = new Person("joe", "doe", 35);
  
  Person p;
  p.sayHello();
  
  Person &pRef = p;
  pRef.sayHello();
  
  cout << "\nEnd program" << endl;
  
  return 0;
}
