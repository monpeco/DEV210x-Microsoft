#include <iostream>

using namespace std;

int main()
{

    int num = 3;
    int *pNum = &num;
    cout << pNum << endl;
    cout << *pNum << endl;

    *pNum = 45;
    cout << *pNum << endl;
    cout << num << endl;

    return 0;
}

/* Output:

0x7ffddef39e04
3
45
45
*/