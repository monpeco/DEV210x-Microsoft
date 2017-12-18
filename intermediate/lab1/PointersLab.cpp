#include <iostream>

using namespace std;

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
  
  return 0;
}