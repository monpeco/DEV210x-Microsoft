#include <iostream>

using namespace std;

int main()
{

    int num = 3;
    int *pNum = &num;

    cout << pNum << endl;

    return 0;
}

/* Output:

1st run: 0x7fffb9a92f94
2nd run: 0x7fff6dab9114
*/