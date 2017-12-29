#include <string>
#include <iostream>
#include "MyClass.h"
using namespace std;

int main(){
  MyClass m;
  SomeExternalFunction(m);
  
  cout << "Program end" << endl;
  return 0;
}