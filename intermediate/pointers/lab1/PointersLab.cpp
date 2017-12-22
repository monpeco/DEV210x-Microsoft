#include <iostream>
#include <string>
#include "person.h"

using namespace std;

void PassByValue(int parameter);
void PassByRef(int *parameter);
void ModifyPerson(Person *p);

int main(){
  bool debug = true;
  
  // 2. In your main() function, create two variables.  One variable needs to an intrinsic integer variable named num1 and the second needs to be a pointer to an int pNum.
  int num1; 
  int num2;
  int *pNum = &num2;  // pointer points to another variable!
  
  num1 = 3; // 3. Assign the value 3 to num1.
  if(debug) cout << num1 << endl;
  
  // 4. Assign the value 5 to the memory location stored in pNum.
  //pNum = &num1;
  *pNum = 5;
  if(debug) cout << num1 << endl;
  
  // 7. Call PassByValue and pass in num1 as the argument.
  PassByValue(num1);
  // 9. After the call returns to main(), output the value of num1 to the console window again.
  cout << "After PassByValue return to main: " << num1 << endl;
  // 11. Call PassByRef and send pNum as the argument.
  PassByRef(pNum);
  // 14. After the call returns to main(), output the value of pNum to the console.
  cout << "After PassByRef return to main: " << num1 << endl;
  // 15. Call PassByValue and pass in pNum as an argument.
  PassByValue(*pNum);
  cout << "After PassByValue return to main: " << num1 << endl;
  
  // 17. Create a pointer variable to a double, and allocate memory for it using the new keyword.
  double *pNum2 = new double();  
  // 18. Assign a value to the memory location.
  *pNum2 = 22.75;
  // 19. Use the dereference operator, get the value and output it to the console.
  cout << "\nDouble number: " << *pNum2 << endl;
  // 20. Deallocate the memory for that variable.
  delete pNum2;
  // 21. Output the value stored in the memory location for that variable again.
  cout << "Double number: " << *pNum2 << endl;
  
  
  // 26. Instantiate a Person object in your main() method and assign values to the member variables.
  Person *jon = new Person();
  jon->name = "Jon Skeet";
  jon->age = 46;
  jon->height = 195.5;
  jon->weight = 95.5;
  
  // 27. Output the values stored in the member variables to the console window
  cout << "\nName: " << jon->name << ", age: " << jon->age << ", height: " << jon->height << ", weight: " << jon->weight << endl;
  
  // 28. Call the ModifyPerson() function, passing in your Person object you just created.
  ModifyPerson(jon);
  
  // 30. Back in main(), output the values stored in the Person object you created.  Did the name change?  It should have if 
  // you passed the object correctly to the function.
  cout << "\nName: " << jon->name << ", age: " << jon->age << ", height: " << jon->height << ", weight: " << jon->weight << endl;

  int x[5];
  cout << endl << sizeof(x) / sizeof(int) << endl;

  return 0;
}

// 25. Create a function in your application called ModifyPerson() that 
// accepts a Person object as an argument.  NOTE: This function should 
// be in the application area and not inside the Person class.
void ModifyPerson(Person *p){
  // 29. Inside the ModifyPerson() function, change the value in the name member variable.
  p->name = "Jon Leffler";
  p->age = 55;
  p->height = 150.1;
  p->weight = 70.01;
}

// 10. Create a function called PassByRef that accepts a reference variable as an argument
void PassByRef(int *parameter){
  // 12. Output a statement indicating the current function name.
  cout << "\nPassByRef" << endl;
  
  // 13. Modify the value of pNum, setting it to 50,  and output the value to the console.
  *parameter = 50;
  cout << "Inside PassByRef: " << *parameter << endl;
  
}

// 5. Create a function called PassByValue that accepts an integer argument.
void PassByValue(int parameter){
  
  // 6. Inside PassByValue, output a text string indicating the name of the function you are in.
  cout << "\nPassByValue" << endl;
  
  // 8. Modify the value of num1 inside the PassByValue function and output the new value to the console window.
  parameter++;
  cout << "Inside PassByValue: " << parameter << endl;
  
}

/*
g++ PointersLab.cpp person.cpp -o PointersLab.exe 
*/