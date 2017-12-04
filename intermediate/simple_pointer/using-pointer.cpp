#include <iostream>

using namespace std;

int main(){
  
  int num = 3;
  int *pNum = &num;
  
  cout << "num:\t" << num << endl;    // variable value
  cout << "&num:\t" << &num << endl;    // variable address
  cout << "pNum:\t" << pNum << endl;    // pointer value
  cout << "*pNum:\t" << *pNum << endl;    // pointing's variable value
  cout << "&pNum:\t" << &pNum << endl;    // pointer's address
  
  *pNum = 45;
  cout << " --- *pNum = 45--- " << endl;    // variable value

  cout << "num:\t" << num << endl;    // variable value
  cout << "&num:\t" << &num << endl;    // variable address
  cout << "pNum:\t" << pNum << endl;    // pointer value
  cout << "*pNum:\t" << *pNum << endl;    // pointing's variable value
  cout << "&pNum:\t" << &pNum << endl;    // pointer's address


  return 0;
}
/*
Output: 
num:    3
&num:   0x7ffc7b55f984
pNum:   0x7ffc7b55f984
*pNum:  3
&pNum:  0x7ffc7b55f988
 --- *pNum = 45--- 
num:    45
&num:   0x7ffc7b55f984
pNum:   0x7ffc7b55f984
*pNum:  45
&pNum:  0x7ffc7b55f988
 */
 