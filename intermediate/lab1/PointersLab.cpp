#include <iostream>

using namespace std;

void PassByValue(int parameter);
void PassByRef(int *parameter);

int main(){
  bool debug = true;
  
  int num1; // 2. In your main() function, create two variables.  One variable needs to an intrinsic integer variable named num1 and the second needs to be a pointer to an int pNum.
  int *pNum;
  
  
  num1 = 3; // 3. Assign the value 3 to num1.
  if(debug) cout << num1 << endl;
  
  // 4. Assign the value 5 to the memory location stored in pNum.
  pNum = &num1;
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
  
  return 0;
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

