#include <iostream>
#include "MyClass.h"
using namespace std;

MyClass::MyClass(){
  cout << "MyClass::MyClass()" << endl;
  privateData = 154;
}

MyClass::~MyClass(){
  cout << "MyClass::~MyClass()" << endl;
}
  
void MyClass::memberFunction(){
  cout << "memberFunction()" << endl;
}
  
void SomeExternalFunction(MyClass &targetObject){
  cout << "SomeExternalFunction() access to privateData: " << targetObject.privateData << endl;

}