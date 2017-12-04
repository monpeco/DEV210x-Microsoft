#include <iostream>

using namespace std;

int main(){
  int num = 3;
  int *pNum = &num;

  cout << "num: " << num << endl;
  cout << "&num: " << &num << endl;
  cout << "pNum: " << pNum << endl;
  
  return 0;
}