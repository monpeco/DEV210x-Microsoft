#### Module One Pointers   Pointers   Introducing Pointers

# Introducing Pointers

In order to understand pointers we must first start with an understanding of how computers handle the data for you application.  
When you declare a variable in your code, you are providing key pieces of information to the compiler for handling the data 
stored as a part of that variable.  The data type determines how much memory is requested for that variable.  Once the variable 
is declared, you don't need to worry about where in memory it is stored.  Simply referring to the variable name in code is 
sufficient for gaining access to the value stored there.

But let's take this concept a little further and explore memory locations in your code.  Consider the following code:

    int num = 3;

This is a simple variable declaration of type int, called num, that stores the value 3.  The variable num actually references a 
location in the computer's memory.  The memory location is what gives num an identity.  During an execution of the application 
code, while num is in scope, it will have one memory address for the entirety of its scope. Most objects in C++ have an identity, 
which means that they have a unique memory address during their lifetime (scope).

A pointer is simply a variable that holds the memory address of an object in C++.  To use pointers, you create a pointer variable.  
As an example, if we want to, we can create a variable to point to our num variable's address in memory by using the following 
line of code:

    int* pNum = &num;

In this line of code, int* is referred to as a pointer to an int.  In other words, it will contain the memory address of an 
int data type.  The variable that will actually hold that memory address is called pNum.   After the assignment operator, we 
see the use of the & symbol.  the & symbol, in this instance, is known as the  address-of operator and it allows us to get at 
the memory address for the num variable.

Depending on the documentation you read, you may also find the * used in this manner:

    int *pNum;

In this case, the author of the text is trying to show that pNum is the actual pointer.  Regardless, the concept is the same.  
pNum is a pointer an int.

If you compile and run the following code, you will notice the memory address of num output to the console window.  On my first 
run, the address for num was 001CF79C and on the second run it was 0018FD38.  Subsequent runs will offer up different memory 
addresses showing how the "identity" of the variable is only good for the duration of its lifetime.  The values you see may 
be different that these addresses returned for this execution of the program.

```c++
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{

    int num = 3;
    int *pNum = &num;

    cout << pNum << endl;

    return 0;
}
```

NOTE: A word of caution when using pointers.  You should always initialize a pointer variable to NULL, nullptr, 0, or with a memory 
address.   Leaving a pointer variable uninitialized is an error that can result in difficult to find bugs and create security 
issues for your code.

```c++
int *pNum;  // not recommended

cout << pNum << endl;
```

Referring to the preceding code, some compilers will not compile the code and will issue a warning or raise an error because of the 
pointer not being initialized.  For compilers that do not catch this error, you could see a memory address output to the console but 
you will have no idea what data resides at that memory address.

One final note, when declaring a pointer, ensure that the variable you will be pointing to is the same data type as the pointer you 
are declaring.  This is important because of the difference in the number of bytes stored in the various data types.  

For more information , you can see: 
C and C++ with Visual Studio: https://aka.ms/edx-dev210.2x-vs02

---

#### Module One Pointers   Pointers   The Dereference Operator

# The Dereference Operator

This operator is another source of confusion for those who are new to pointers.  The reason is 
because we are "overloading" the use of the * symbol.  It is used as the pointer symbol and 
also as the dereference symbol.   So what is a dereference?  Consider the following code sample.

    int num = 3;            // a simple variable holding the value 3
    int *pNum = &num;        // a pointer holding the address of num
    cout << pNum << endl;    // output the memory address of num
    cout << *pNum << endl;    // output the value 3

In the first line, we declare a variable called `num` and assign it the value 3.  Next we create a 
pointer `*pNum` and assign it the memory address of the variable `num`.  The first cout statement 
outputs the address of num, because that is what the pointer variable pNum holds.   But the last 
line outputs the value 3.  Why?  Here is where the power and the danger of pointers starts to 
become apparent.

Using the dereference operator, you can gain direct access to the underlying value in the variable 
num.  If you are unsure what this means, lets add another code segment to help clarify.  Copy and 
paste this code into a C++ app to see it working on your system if you want to test it.

    int num = 3;
    int *pNum = &num;
    cout << pNum << endl;
    cout << *pNum << endl;

    *pNum = 45;
    cout << *pNum << endl;
    cout << num << endl;

What is being demonstrated here is that we are using the dereference operator to change the underlying 
value of num, indirectly.  The two last cout lines demonstrate that the value of num and *pNum are 
precisely the same value. You might be thinking at this point that we could simply have changed the 
value of num directly and you would be correct. But hold that thought for a moment and  we'll revisit 
the importance of this later in the lesson when we discuss the purpose of pointers and their uses.

---

#### Module One Pointers   Pointers   Why Pointers?

# Why Pointers?

Now that you know what a pointer is, you may be wondering why you need them. One reason for using pointers 
is application performance.  In our simple examples thus far, the amount of data that we have passed into 
functions has been small.  But if we were using large data structures, as class files can sometimes be, or 
if need to perform repetitive operations on lookup tables, then it is far more efficient to pass a pointer, 
which is just the memory address, than it is to pass the entire data structure.

As you saw in the code example that passed a variable by reference, pointers can also be used to modify the 
value in the variable passed in.  Once again, the pointer provides a direct link to the underlying value of 
the variable allowing you to change the value without the overhead of copying the value into the function.

Pointers also allow you to dynamically allocate memory in your application.  You may run across a requirement 
for this when creating arrays and objects in your C++ code.  Dynamically allocating means that you do not need 
to know the size of memory that will be needed for an object at compile time but rather that the size will be 
allocated during runtime of the application. 

---

#### Module One Pointers   Pointers   Demo: Simple Pointers