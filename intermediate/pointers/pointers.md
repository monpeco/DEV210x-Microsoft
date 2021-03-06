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

# Simple Pointers Demo

>> In this demonstration we're gonna take a look at creating
simple pointers in C++.
I've got Visual Studio 2015 open, and
I have a simple C++ console based application created here.
I've got an include statement that, basically, brings in my
input, output, stream header file, which allows me to make
use of my C out, or console output statements, down here.
So, let's take a look at our application.
The first line of code, here on line 14, is relatively simple,
and you should be familiar with this syntax already.
We've declared an integer type variable called num and
we have assigned a value 3 to it.
Next, what we've done on line 17 is we have created an integer
pointer, or a pointer to an integer, called pNum.
So pNum becomes a pointer object.
And it's interesting to talk a little bit
about the way that we declare the pointer variables,
cuz you may see it differently in books or
other types of documentation or material that you read.
In this instance,
I've actually got the asterisk right next to my data type.
And this just simply says this is going to be a pointer to
an integer type or pointer to int.
But the Compiler is perfectly happy even if we add some white
space where we can have the asterisk completely separated
from the data type.
Some people prefer that because they like the white space so
that they can see the different components of what they're
working with specifically.
So that's permissible.
You can actually do that.
And others like to have their pointer variables declared in
this manner where we've got the asterisk right next to
the actual pointer name.
Some people prefer it this way because they look at it from
this perspective and say well any time I see asterisk pNum,
I know that this is a pointer variable.
And it's one small step to just go back and
take a look at the data type that's been declared and
we know that this will actually be a pointer to a type of int.
Now the other aspect that's also important to keep in mind is
when we declare a pointer to a specific data type,
in this case int,
that's the data type to which we should be assigning the value,
or sorry, the variable that this pointer will point to.
And in this case we're going to use the address for
the variable num, which is an int, and that's perfectly fine.
If we were to declare this as a pointer to a double, and
then we attempted to assign the memory address of num to that
pointer variable, it depends on your compiler,
it depends on the systems that you're using.
You may receive a warning, you may receive an error, or
it may simply compile successfully.
The problem is that when your application accesses that,
you're attempting to access memory beyond the size of
the variable to which you're pointing, if that makes sense.
So a double takes up more memory than an int does and so
therefore it would be attempting to access memory that would be
in a much larger space than an integer data type would be.
All right, so enough of that.
Let's take a look at the next assignment line of code that
we have here, which is assigning the address of the variable num
to our pointer.
So we wouldn't be able to simply say pNum equals num.
And because when we do that,
the compiler's gonna give us at least in Visual Studio, this
little squiggly line that tells us that there is an error here.
And it tells us that a value of type int cannot be assigned to
an entity of type int, so an entity means an object.
So it knows the difference between pNum and
num as being two different types.
Even though they're both gonna deal with integer data types,
pNum is actually an object.
And so pointers are objects in your code.
So we have to use the address of operator or
the address operator which is the ampersand.
This now tells us that we will assign to pNum
the memory address of the num variable.
And that's perfectly legitimate, that's allowed.
That's the value that a pointer actually stores.
So the pointer variable is storing that memory address.
Once we get that memory address,
we're going to run through a couple of C out statements.
We'll print out the value of num right here, then we will print
out what the memory address of num is in the computer, and
then we will also print out what value is currently stored
in pNum.
So let's go ahead and execute this program.
Now I'm gonna press Ctrl+F5, which is a keyboard shortcut for
Visual Studio.
And when dealing with console-based applications,
if you wanna actually see the information displayed on
the screen, if you want the console window to remain open,
you should use Ctrl+F5 to allow that console window to stay open
once you've executed the program.
Our project is out of date,
that's because I made some changes earlier on and
what we are dealing with here, so we need to recompile it.
So yes, let's build the application.
And then our console window will open up.
And we can see that our first output statement gives
the value of 3 which is what we assigned to num.
Our second statement outputs the memory address of what was
basically given to num by the operating system.
And then we also output that same value because that is what
pNum is actually holding,
which is the address of the num variable.
Now I want to run this application one more time and
what I want you to take note of is the current value that is in
here right now, 0018F7DC, so
a hexadecimal version of a memory address.
I'll press the Enter key to close my application,
Ctrl+F5 one more time, and
you'll notice that the memory address now is different.
So what this is telling you is that each time your application
runs, the operating system will assign a memory
address that is currently available to the executing code.
So you'll often see that memory address change on
a regular basis.
So that's a really quick and simple demo of simple pointers.
Once again just declaring a simple integer variable,
declaring a pointer variable that points to int.
Assigning the address of our integer variable to that
pointer, and
then outputting the values to see how they're displayed.


---

#### Module One Pointers   Pointers   Demo: The Dereference Operator

# Dereference Demo

https://youtu.be/9_wZYfS1I_E

>> In a previous demo we saw an example of using simple pointers
in C++.
In this demo we're gonna take that to the next step.
We're gonna take a look at the dereference operator.
The dereference operator uses the same symbol as
the pointer does.
And it's also the same symbol as the multiplication symbol used
within C++.
This is just an example of operator overloading
within the language.
And operator overloading simply means that we make the use of
the same operator for multiple dissimilar purposes.
So let's take a look at how we do that with this dereference
operator demo.
In our first line of code we're gonna declare a simple variable
called num, which is an int type and we assign the value 3 to it.
In the next line, this is similar to the previous
demo on simple pointers, we simply declare a pointer to int,
in which case we're calling it pNum.
And we assign to it the address of the num variable.
And then, in this line here, we will output that address
by using the pNum variable to gain access to the value stored
in pNum which is the address of the num variable.
Now it's important to know here that
we've used the asterisk up here to declare our pointer variable.
But when utilizing that variable in an output statement, or later
on in the program, if we're only interested in the address for
that pointer or the content within that pointer itself,
we don't use the asterisk.
And the reason being is because once we include that asterisk
with that variable name later on, so as long as it's not
in a declaration statement, it becomes a dereference operator.
And that's what's taking place right here in this line of code.
So we're issuing a similar output statement as what we did
here, with the difference that
we've now included the asterisk in the pNum variable name.
This now indicates to the compiler
that *pNum is a dereference operator.
What this will do is it will give us indirect access
to this value which is stored in num.
And it's indirect because it's using the address stored in
pNum to indirectly gain access to the value
of 3 which is stored in num.
Finally, what we're gonna do in the demo is we're gonna take
a look at how we can use the dereference operator
to directly impact the value stored in another variable.
So in this case, we will use the dereference operator here
to assign a new value to num and the new value becomes 45.
So once again,
remember the dereference operator simply says,
I want to get to the value that is being stored at
the memory address that was declared up here.
Once we do that, we will output the value of that num variable,
and we're doing it through the use of the dereference operator.
So this statement is identical to this statement here.
And then just to prove that we have actually modified
the underlying value in the num variable through that
dereference operator, we will output the num variable here
showing that the value has indeed changed.
So let's execute the code with the Ctrl+F5 and
we see in our first output statement.
I'll just move this window a little bit so
we can see the lines of code that pertain to this.
Our first output statement said, give me the address
that is stored in pNum which is the address of num.
So this is the memory address in the computer currently.
Once again, that will change for
each execution that you do the program.
It will typically end up with a new memory address each time.
Then we come down here, and we use the dereference
operator to actually print out the value that is stored
in the memory address pointed to by pNum which is the variable
num which is the value 3 and we see that output here.
Finally, in the dereference operator assignment statement
right here, we change the value
that is stored in num to 45.
We issue the same dereference output statement
here as we did earlier.
But instead of getting the value 3,
we now get the value 45 showing that we have changed
the underlying value that pNum is pointing to.
And just to prove it, in the final statement,
we output the value of num directly, and in this case,
it's showing 45 showing that we did indeed change the underlying
value through the dereference operator.
So that's a quick little demo on using the dereference operator
in C++.

---

#### Module One Pointers   Pointers   Demo: Simple Pointers

# Simple Pointers Demo

TODO: missing video

>> Let’s take a closer look at how pointers work and better understand the pointer operator,
the address of operator, and the dereference operator.
If we were able to zoom in on the memory in the computer and see how it is addressable,
ie it uses memory addresses for access to the memory segments for storing and retrieving
values, we might zoom in on a specific part and see the actual addresses.
In this case, we are using generic addresses because each computer will have differing
addressing structures depending on hardware specifics that we don’t go into here.
Just note that they are sequential and are typically denoted in hexadecimal format.
As you can see from the first occupied memory slot, the data stored there is binary data.
Even if you place a text value in memory, the computer will store it in binary format.
Now, let’s assume that we have the following line of code, (first animation).
We create a variable called num, of type int, and store the value 3 in that variable.
Recall that a variable is simply a named memory location.
It makes it easier for us to read.
The computer stores the value in a memory slot.
We have no control over where, but it also returns a memory address for num so that it
knows how to get to that value when asked.
How can we get the address of memory where the value is stored?
We use the pointer operator, which is the asterisk.
So if we write this line of code < cue next animation #2 >, we create a pointer variable
called pNum.
It is a pointer variable because we preface it with the asterisk.
Because we declared it as an int pointer, or a pointer to an int, the compiler knows
to request memory large enough to store an integer value.
On most currently systems, that is a 32-bit value.
Also in this line of code, we make an assignment to the pNum variable.
But what are we assigning?
Notice the ampersand in front of num.
This operator is known as the address of operator.
It tells the compiler to assign the address of the num variable that we declared earlier,
to the pointer.
Let’s focus on this for a second because this is one key to understanding pointers.
The ampersand is the address of operator and it gets the memory address of where the computer
has stored the value for num.
This is the only legal value that we can assign to pNum because pNum is a pointer to an int.
In other words, pNum can only store the memory address of a int variable.
Based on our pseudo memory diagram, we note that <cue animation #3 > the address of the
value 3, hence the variable num, is 0x00017.
Due to the assignment of this address to the pointer variable pNum, we find that &num and
pNum contain the same value, the address of the variable num.
If we want to see what that memory address is, we can output it to the console window.
<cue animation #4 >. Issuing a cout statement for pNum or &num will output the value 0x00017.
Of course if you run this code on your own computer, you will get a completely different
memory address.
In fact, if you try it a number of times, you should get a different memory address
each time you run the application.
Finally we take a look at the dereference operator.
For example, what if want to gain access to the value stored in num?
You might be thinking that we can simply use the num variable, and you would be correct.
That is one method of gaining access to the value 3 that is stored in num.
However, it we are dealing with objects, it can be more complicated because we might be
declaring objects dynamically as the application runs and at the time you are writing the code,
you may not have all variable names available to you.
As a result, we can make use of the dereference operator in an assignment statement, < cue
animation #5 >. In this line of code, we are assigning the variable contents, the value
that is located in the memory address pointed to by pNum.
This is sometimes considered direct access.
It is also the cause of confusion in C and C++ programs and can result in unintentional
assignment of values in memory.
So, how do we know whether we are using the asterisk as a pointer operator or a dereference
operator?
They are both the same symbol, and in these code samples, the variable pNum is used in
both cases.
What is the difference?
It’s actually quite simple.
All you have to do is take not which side of the assignment operator that the asterisk
is on.
For example, in the second line of code in this animation, the asterisk is on the left
side of the assignment where we assign the address of num to the variable pNum.
So, left of assignment means pointer.
In the last line of code where we assign to the variable contents, the asterisk is on
the right side of assignment, which makes it a dereference operator.
Keeping these two concepts in mind will help you know which purpose the asterisk is being
used for.

---

#### Module One Pointers   Pointers   Understanding Pointers Better

# Understanding Pointers Better

https://youtu.be/tblpv3P1r5U

>> Let’s take a closer look at how pointers work and better understand the pointer operator,
the address of operator, and the dereference operator.
If we were able to zoom in on the memory in the computer and see how it is addressable,
ie it uses memory addresses for access to the memory segments for storing and retrieving
values, we might zoom in on a specific part and see the actual addresses.
In this case, we are using generic addresses because each computer will have differing
addressing structures depending on hardware specifics that we don’t go into here.
Just note that they are sequential and are typically denoted in hexadecimal format.
As you can see from the first occupied memory slot, the data stored there is binary data.
Even if you place a text value in memory, the computer will store it in binary format.
Now, let’s assume that we have the following line of code, (first animation).
We create a variable called num, of type int, and store the value 3 in that variable.
Recall that a variable is simply a named memory location.
It makes it easier for us to read.
The computer stores the value in a memory slot.
We have no control over where, but it also returns a memory address for num so that it
knows how to get to that value when asked.
How can we get the address of memory where the value is stored?
We use the pointer operator, which is the asterisk.
So if we write this line of code < cue next animation #2 >, we create a pointer variable
called pNum.
It is a pointer variable because we preface it with the asterisk.
Because we declared it as an int pointer, or a pointer to an int, the compiler knows
to request memory large enough to store an integer value.
On most currently systems, that is a 32-bit value.
Also in this line of code, we make an assignment to the pNum variable.
But what are we assigning?
Notice the ampersand in front of num.
This operator is known as the address of operator.
It tells the compiler to assign the address of the num variable that we declared earlier,
to the pointer.
Let’s focus on this for a second because this is one key to understanding pointers.
The ampersand is the address of operator and it gets the memory address of where the computer
has stored the value for num.
This is the only legal value that we can assign to pNum because pNum is a pointer to an int.
In other words, pNum can only store the memory address of a int variable.
Based on our pseudo memory diagram, we note that <cue animation #3 > the address of the
value 3, hence the variable num, is 0x00017.
Due to the assignment of this address to the pointer variable pNum, we find that &num and
pNum contain the same value, the address of the variable num.
If we want to see what that memory address is, we can output it to the console window.
<cue animation #4 >. Issuing a cout statement for pNum or &num will output the value 0x00017.
Of course if you run this code on your own computer, you will get a completely different
memory address.
In fact, if you try it a number of times, you should get a different memory address
each time you run the application.
Finally we take a look at the dereference operator.
For example, what if want to gain access to the value stored in num?
You might be thinking that we can simply use the num variable, and you would be correct.
That is one method of gaining access to the value 3 that is stored in num.
However, it we are dealing with objects, it can be more complicated because we might be
declaring objects dynamically as the application runs and at the time you are writing the code,
you may not have all variable names available to you.
As a result, we can make use of the dereference operator in an assignment statement, < cue
animation #5 >. In this line of code, we are assigning the variable contents, the value
that is located in the memory address pointed to by pNum.
This is sometimes considered direct access.
It is also the cause of confusion in C and C++ programs and can result in unintentional
assignment of values in memory.
So, how do we know whether we are using the asterisk as a pointer operator or a dereference
operator?
They are both the same symbol, and in these code samples, the variable pNum is used in
both cases.
What is the difference?
It’s actually quite simple.
All you have to do is take not which side of the assignment operator that the asterisk
is on.
For example, in the second line of code in this animation, the asterisk is on the left
side of the assignment where we assign the address of num to the variable pNum.
So, left of assignment means pointer.
In the last line of code where we assign to the variable contents, the asterisk is on
the right side of assignment, which makes it a dereference operator.
Keeping these two concepts in mind will help you know which purpose the asterisk is being
used for.


---

#### Module One Pointers   Reference Types   Introducing Reference Types

# Introducing Reference Types

C++ includes a type known as a reference.  A reference type is simply an alias for another type.  It "refers to" or 
"references" another type in your code.  A reference type overloads the use of the & operator.  So far you have seen 
the & operator used to represent the address-of operator for obtaining the address of a variable.  References also 
use this operator to denote a reference to another variable.

You declare a reference type using a syntax similar to declaring a pointer variable.  That is, you declare the data 
type of the C++ variable or object that will be referred to, then you use the & character followed immediately by 
the reference type name.  Finally, **it's important to note that when declaring a reference, you must assign it at t
hat time**.  It behaves similar to a constant in this sense.  An example demonstrates the declaration.

    int num = 3;
    int &refNum = num;
    int &refNum2;
    cout << refNum << endl;

In the code sample above we create an integer variable called num and assign it a value of 3.  Next we declare a 
reference called refNum.  The & character tells us this is a reference value.  Note that we immediately assign it 
to the num variable.  This binds refNum to num.  This reference cannot   be reassigned later in program code.  

The third line in the code sample will cause an error because it has not been initialized.  The last line will 
output the value 3, which is correct because refNum is an alias or reference to num, which holds the value 3.

To see how this affects the original value of num, let's create another small code sample that displays the value 
for num, modifies it through refNum, then outputs the memory addresses of num and refNum.

    int num = 3;
    int &refNum = num;

    cout << "num contains " << num << endl;
    cout << "refNum contains " << refNum << endl;

    refNum++;    // increment refNum by 1

    cout << "num contains " << num << endl;
    cout << "refNum contains " << refNum << endl;
    cout << "refNum is located at " << &refNum << " and num is located at " << &num << endl;


On my computer, this code produces the following output.

    *num contains 3
    refNum contains 3
    num contains 4
    refNum contains 4
    refNum is located at 0018FE14 and num is located at 0018FE14
    Press any key to continue . . .*

Lines 1 and 2 are now familiar to you as we created and assign num and a reference refNum.  The first two cout 
lines output the value of num and refNum and you can see that both contain the value 3.  On line 5 we increment 
refNum, which will also increment num due to refNum being an alias for num.

The remaining lines show us that num was indeed incremented to 4 as was refNum.  The last line outputs the 
memory address of num and refNum to show that they both point to the same memory location.   As a result, any 
changes made to refNum affect num.

References are commonly used with parameters to functions.  The default mechanism used by C++ when calling a 
function, is to pass arguments into the parameters of that function, by value.  This means that only the value 
is passed.  This has one effect in a program as we see here.

    using namespace std;

    void passByValue(int);

    int main()
    {

        int num = 3;
        cout << "In main()" << endl;
        cout << "Value of num is " << num << endl;

        passByValue(num);

        cout << "Back in main and the value of num is  " << num << endl;


        return 0;
    }

    void passByValue(int num1)
    {
        cout << "In passByValue()" << endl;
        cout << "Value of num1 is " << num1 << endl;

        // modify num1, won't impact num
        num1++;

        cout << "num1 is now " << num1 << endl;
    }

In this sample code, we declare our function prototype before main().  Inside main(), we declare and assign 
the variable num.  We output a line indicating which function we are in (main()) and then what the value of 
num is (3).

Next we call the passByValue(int num1) function and pass num as the argument to the num1 parameter.  We print 
a line indicating that we are inside the passByValue() function and then output the value of num1 to show that 
indeed has the same value as num (3).

Inside passByValue, we increment num1 and output its new value, which in this case is 4.

Once passByValue() is finished executing, control returns back to main() where we indicate we are back inside 
the main function and we output the value for num, which is still 3, not 4.  

The pass by value behavior shows that we only passed in a copy of the value that is held in num and not a 
reference to num itself.  Therefore any changes inside the passByValue() function only impact the local 
variable num1 and not the original variable num.   If we wanted to modify num inside our passByValue function, 
we would need to pass in a reference, not a value.  The following code sample changes the function name, only 
to make it logical what the function is doing, and the way the parameter is passed in.

    using namespace std;

    void passByRef(int &num1);

    int main()
    {

        int num = 3;
        cout << "In main()" << endl;
        cout << "Value of num is " << num << endl;

        passByRef(num);

        cout << "Back in main and the value of num is  " << num << endl;


        return 0;
    }

    void passByRef(int &num1)
    {
        cout << "In passByRef()" << endl;
        cout << "Value of num1 is " << num1 << endl;

        // modify num1 which will now change num
        num1++;

        cout << "num1 is now " << num1 << endl;
    }

This produces the following output:

    In main()
    Value of num is 3
    In passByRef()
    Value of num1 is 3
    num1 is now 4
    Back in main and the value of num is  4
    Press any key to continue . . .


Because we passed num as a reference, C++ was able to access the contents of num directly in memory rather 
than a copy of the value held by num as in the passByValue() example.

For more information , you can see: 
C and C++ with Visual Studio: https://aka.ms/edx-dev210.2x-vs02

---

#### Module One Pointers   Reference Types   Demo: Reference Types

# Reference Types Demo

>> In this demo,
we're gonna take a look at the use of reference types.
We have this demo divided up into two segments.
The first one, we'll focus strictly on
just working with a simple reference type and
how we can use it as a reference to a standard variable.
And then in the second section, we'll take a look at how we use
references when we're passing variables into functions.
So let's take a look at the first part of the demo where
we're declaring a simple int variable called num and
assigning it a value of three.
So this is just common for what we've been doing for
all of our demos so far in this class.
And second, we create a reference type called refNum and
we assign the variable num to that reference type.
Now, once again,
we are overloading the use of an operator in C++ and
in this case, we're overloading the use of the ampersand.
When we see it on this side of an equal or
an assignment statement.
This basically tells us that what we are referring to here
now is a reference type as opposed to
the address of operator.
Which we typically would find over here on the right-hand side
of the assignment operator.
So all we're doing in this particular instance is we're
creating a reference type.
Which will basically be an alias for an int data type and
we're assigning num to that.
What we will do once we have the assignment complete is we will
use a couple of output statements and
we will indicate what num contains.
And then we will output the value for the variable num.
And then we will also put the value contained in
the variable refNum.
Now those will be the same and
you'll see that in a moment when we execute the code.
Then, what we do is, we increment refNum.
So, we're incrementing the reference type itself as opposed
to num, and when we do the output statements,
we'll see that the value in num,
and refNum has been incremented the same.
So basically, we're impacting the same value.
And just to prove that, we'll come down, in the next statement
here and we'll actually increment num by one.
And then output the two values here and
you'll be able to see that those as well indicate the same value
after we've done the incrementing.
And then finally, we'll output the memory address of refNum and
num so that we can see that they are equal.
So they are pointing to the same identity or
the same actual value in the memory location.
And let's not be confused about the use of the ampersand here.
This is the address of operator in this instance, as opposed
to the reference operator up here in this instance.
So let's execute this code and see what the output looks like.
So we CTRL + F5, so that our command window or
our console window remains open.
We've made changes or I've made changes to the codes since it's
been built, so I will rebuild it again.
And then we're gonna see that our console window pops open.
I will move it just to the side a bit, so
we can see the lines of code and how they pertain to the output.
So our first output lines is num contains and
it says value three, which is what we assigned up here.
And then we also say refNum contains and
we see that it contains the value three.
We incremented refNum here, so now refNum should equal four.
And because refNum is an alias to num, it should also equal
four and it does here in both of this statement.
Incrementing num by one makes it five, but
also makes refNum five.
And we prove that with the two output statements.
And then finally, when we output the memory address of the two,
we see that refNum is located at 0018FA98.
And num is also located at that same memory address.
This proves that refNum, the refNum type is an alias for
the type num and that they both have the same identity.
So let's close our console window for a moment.
Now what we're gonna do is go in and take a look at a more
common use of the reference type if you will.
So in this case, what I wanna do is I am going to comment out
these lines because I no longer require them for the time being.
If you're using Visual Studio, there's a shortcut
key combination that works very nicely for
commenting out a section of code that you don't want to have
execute if you're trying to do debugging.
In my case, I'm demonstrating some other code and I don't want
this code to execute and clutter up my screen.
So the Ctrl + K and C provides a comment shortcut and
it comments all of that code out for me.
Equally well because I have this code surrounded with
the older C style comments I wanna use this code.
So I will simply highlight that and use the keyboard shortcut of
Ctrl + KU, which means uncomment.
So now this code has been uncommented
with the exception of one line.
We'll take a look at,
I'll change these in a moment because I wanna demonstrate
passing by value and passing by reference.
And we'll do those in a moment.
At the top of my screen, so for
those of you who wanna grab this code a little bit later on and
paste it in or look at it in your own code editor.
Whatever it is that you might be using, I'm utilizing
function prototypes up here at the top of my code file.
Now typically, you'll find these in header files, but
rather than complicating the demo code here with
multiple files or header files and an implementation file.
I've just simply included these function prototypes at the top
up here for the time being.
Just so that C++ doesn't complain when I try to use
the functions a little bit later on.
So let's scroll down and take a look at what we're doing.
The first thing I wanna do is actually demonstrate
the passByValue which is the default mechanism for
passing values to a function.
And so what we're doing in this code is we have again,
our standard num variable declared of type int and
it contains a value of 3.
And then we're going to use some output statements to indicate in
the console window which method or which function that
we're actually in as the code executes.
And then what the value of the variable is within
that function as we execute the code.
So what's gonna take place when we execute this,
when we start running the application.
Is that it will print out that we were in the main function
which we will be cuzs if we scroll up,
we'll be in the function main here.
And so it says we're in main and it will output the value
of num and in which this case is going to be three.
Cuz we haven't done anything with it yet, but
then we will call the function passByValue.
And we will pass in num as the variable coming into
passByValue.
Now here is our passByValue function.
And you can see that it's accepting one integer type
variable.
And in this case, I've used num1 just so
that we don't confuse this variable num which
is the argument that's being passed into this parameter num1.
I just have a tendency to do that in my code.
I don't like to use the same variable names here in my
parameter list as I do for the values that are being passed in.
It's just my personal coding convention.
So within the passByValue function, we will output this
first line that indicates that we're actually in that function.
And then we will print out what the value of num1 is,
in which case we're going to use,
as we see num1 here, the value that's passed in.
That will be three because we are passing in the value three
through the num variable up here in the function call.
Once we've output the value three,
then what we're going to do is increment num1.
Now the way that pretty much all programming languages work
is that num1 has been declared within the scope of this
functions.
So num1 is a local variable to this function and
when we make the change to num1 and output the value,
you'll see that the value will become four.
But when this function call is finished,
the instructions gets passed back up to where we left off.
And we will print out one final statement that says we are back
in main and the value of num is.
And in this case,
we'll see that the value of num has been unchanged,
because this is a pass by value mechanism.
So let's go ahead and run that code and
we will see what that looks like.
So Ctrl + F5, so that we'll keep the console window open,
yes to build the application.
And then you can see as we take a look at what
takes place here in our code.
It says we are in main,
the value of num is three, we call pass by value.
So we come down here and we'll output in pass by value.
The value of num1 is 3 which is the value that we did
in the pass in here.
And then we do the increment statement.
And then we output what num1 is, in this case,
it indicates num1 is now 4.
Once that function concludes its execution,
we step back into main.
And then we print out,
we're back in main and the value of num is 3.
So this num1++ did not impact num at all.
But what if we wanted it to?
What if the whole purpose of our program was to actually
make that change to the num variable?
And we wanted that to be reflected and
stored in the memory location?
Well, what we have to do is we have to pass
by reference rather than by value.
And this is where that reference type comes into play.
So what I've done here is I've just commented out the call
passByValue and uncommented the call for passByRef.
Now if we look at the function prototype a little more closely
up here for passByRef,
we see that we are passing in an int type.
But because we're utilizing this ampersand character,
it says in the function prototype that it is
expecting a reference type to be passed in.
That's the purpose of the ampersand.
PassByValue did not have that, so passByValue simply says
I expected an int variable, that's all it's looking for.
PassByRef is looking for a reference type to a type of int.
So when we come back down here and
we see that we're going to call pass ByRef and
we're gonna send num to it, here is our passByRef implementation.
So, our data type of int and here is the ref type,
in this case, num1, that we are passing in.
But it will receive num as the argument,
it will cast it to a ref type or
actually when we take a look at it from this perspective.
The num1 reference type becomes an alias for num, so
it's not quite exactly the same as saying that we're passing num
as a reference to this.
We are actually declaring an alias to the num variable.
So we will do the same thing once we're in this function.
That we were in the function, we will output what
the value of num1 is as to what was passed in.
We will modify it, we'll output what that value now is and
then come back in the main and output the value again.
In this case, num should change because we're passing by
reference, so let's run the code and see what happens.
Yes to build it.
So again, similar outputs here in main,
the value of num is 3, which is what it should be in main.
>> And when we pass or when we call in passByRef,
we are in that function and the value of num1 is.
And in this case, we're saying num1 which is the reference
type, we've passed in num to the function.
We've created the reference type num1 to be an alias to it.
Which allows us to gain access to the value 3,
which is what is existing inside num at this time.
Incremented by 1 with the num1++ statement.
So we're not calling num++, we're calling num1++.
Num1 is now 4.
So we output here and then when we return to our main function,
we see that we are back in the main and
the value of num is now 4.
Again, the reason being is because we passed in num,
it became reference by num1 which is a reference type or
an alias for it.
Therefore, the num1++ statement not only impacted num1,
but it also impacted num
because of the way that reference variable works.
And therefore, the output was four.
So that's a quick demo on references and
how we would make use of them within functions.


---

#### Module One Pointers   Managing Memory in C++   Introducing Memory Management in C++

# Introducing Memory Management in C++

You should be aware that a computer contains a finite amount of physical memory.  Operating systems manage 
that memory and are responsible for allocating memory to applications that are currently executing.  Within 
certain limits, the operating system (OS) can control the amount of memory but at the same time, it still 
attempts to provide memory to an application when it requests more.  The OS can use various methods such 
as **swapping**, where it uses a portion of storage space on the fixed disk to move data and programs out of 
main memory and to the local disk, in order to permit a running application to have memory resources.   
There are limits.

Applications can become memory hogs and cause issues for computer performance when they request and use 
large amounts of memory.  It takes considerable resources to swap data and programs to the local disk so 
making an application as efficient as possible in terms of memory usage is an important consideration 
when coding your app.

Every variable that you create in your code, every object that you instantiate, and every resource that you 
open, has an impact on computer memory usage and application performance.   Some aspects of your code, such 
as non-object data types, like int, double, bool, are scoped in a specific way and stored in the logical 
division of memory known as the **stack**.  When these variables go out of scope in your code, the memory on 
the stack is reclaimed automatically.   Not so much with objects.

Each time you instantiate an object in your code, you request memory to be set aside to store that object 
and all its data, which may include other objects.  Without going into specific details, the system uses a 
tracking mechanism for objects that are in use in an application.  It does so in order to ensure that the 
objects are available to your code when needed.  Only when you specifically indicate that an object is no 
longer required (deleting it in code), does the system release this hold on the memory used for that object.   
As a result, if you forget to release object resources in our code, they will continue to use the memory 
allocated and not release it back to the system. 

A common occurrence, unfortunately, in unmanaged code, is something known as a **memory leak**.  This is where 
an application instantiates objects, doesn't release the object when finished, and continues to request 
memory for more object creation.  Eventually, the system will run out of memory and the OS will halt the 
application, or the OS may even crash.

This section looks at methods for managing the allocation of memory consuming resources in your code and 
explains the steps necessary to ensure you are deallocating memory that is no longer required by your 
application.

---

#### Module One Pointers   Managing Memory in C++   Allocating Memory

# Allocating Memory

Allocating memory during runtime of an application is a common requirement.  For example, you may not know how many objects 
your application will need until the application is running.  Allocating memory to newly created objects at runtime makes 
use of pointers.  This is the only way to gain access to memory for new objects when your application is running.  A small 
code sample will serve to illustrate this.

    // declare a pointer to int and allocate space for it
    // with the keyword new
    int *pInt = new int; 

    // declare a pointer to double and allocate space for it
    // with the keyword new
    double * pDouble = new double;

    // store the value 3 in the memory location
    // pointed to by pInt
    *pInt = 3; 

    // store the value 5.0 in the memory location
    // pointed to by pDouble
    *pDouble = 5.0;

In this code sample, we see the use of the keyword new.  We also notice that, unlike in previous code samples with pointers, 
we didn't assign a variable to the pointer.  Instead, we told the compiler that we wanted to create a pointer to an int and 
then, when the program runs, to dynamically assign some memory to hold an int value.   We won't know what the memory address 
is until run time.  We also did the same thing with a pointer to double.

We use the dereference operator to assign a value to the memory location pointed at by pInt and pDouble.  Again, we have no 
idea what these memory addresses are because they are allocated dynamically during runtime.   The application requests some 
memory large enough to store an int value in and a double value.   Because an int, at least on the computer used for this 
course authoring, is 4 bytes and a double is 8 bytes, the operating system allocates 4 bytes for a value to be stored, 
starting at the memory address in pInt, and 8 bytes for the double value, to be stored in the memory of the computer, 
starting at the address in pDouble.

It's very important to note, at this point, that pInt and pDouble are both the same size, in this case 4 bytes, but the memory 
space storing the values are 4 bytes and 8 bytes respectively.  But how can that be when one is an int and the other is a 
double?

Quite simply, a memory address is a fixed size on a specific computer architecture.  In this case it takes 4 bytes to hold a 
memory address.  The start of that memory address is what pInt and pDouble point to.  The computer must know the data type in 
order to work out how much total memory is assigned to that location.

As a concrete example, when this code was executed, the memory address for pInt was set to 00F1FBA8 and the ending memory 
address was 00F1FBAC and the starting address for pDouble was 00F21330 with an ending address of 00F21338.  Doing a little 
hexadecimal math we can see that pInt indeed spans 4 bytes and pDouble spans 8 bytes.  Recall that in hexadecimal, we only 
go as high as 9 then move on to letters so that we would count from the ending 8 in pInt to C as in 9, A, B, C.  That's 4 
positions. (in order to get to the ending memory address for these pointers, simply increment the pointer as in pInt++, 
and the computer will increase the memory address by the number of byes indicated by the data type pointed to).

---

#### Module One Pointers   Managing Memory in C++   Releasing Memory (Deallocation)

# Releasing Memory (Deallocation)

One final point that we need to make in your use of pointers and dynamic memory allocation is releasing memory.   
Each time you allocate memory in your application, it is reserved by the operating system so that other applications 
cannot access that memory address.  This has security implications as well as importance for separation of application 
code to prevent system wide crashes if an errant application behaves badly.

If you do not release the memory in your application, the operating system will not reclaim it and this is known as a 
memory leak.  It is compounded if your application continues to dynamically allocate memory and doesn't release it.

The simple way of releasing your allocated memory is to use the keyword delete.  For the sample code above, you would 
make use of the delete keyword as demonstrated here.

    // declare a pointer to int and allocate space for it
    // with the keyword new
    int *pInt = new int; 

    // declare a pointer to double and allocate space for it
    // with the keyword new
    double * pDouble = new double;

    // store the value 3 in the memory location
    // pointed to by pInt
    *pInt = 3; 

    // store the value 5.0 in the memory location
    // pointed to by pDouble
    *pDouble = 5.0;

    delete pInt;
    delte pDouble;

We have simply issued the delete keyword in reference to each pointer we have in the application code.  The operating 
system will now reclaim the memory used by those pointers and our code no longer has a memory leak.   Use whatever 
method makes sense to you to ensure that memory is released like using a delete keyword for every new keyword.

---

#### Module One Pointers   Managing Memory in C++   Demo: Dynamic Memory Allocation

# Dynamic Memory Allocation Demo

TODO: missing video


>> In this demo we're gonna take a look at dynamic memory
allocation.
And in order to do so,
what we've done is created two pointers.
One called pInt, which is a pointer to int and
one called pDouble which is a pointer to a type double.
Rather than initializing pInt and
pDouble with the address of a variable,
which is something that we've done in the previous demos.
We see the use of the keyword new in the data type
on the right-hand side of the assignment statement.
And in this case, the new double down here.
So what this is telling us is that we are asking the operating
system to give us a memory
address to store a variable which will be of type int.
And in this case to store a variable which will be of type
double.
Now that's important to keep in mind because as we
said before in our discussions around pointers.
You have to ensure that the pointer you're using
is of the proper data type for
the value that you intend to store into it.
And again, the reason it's important is because
the operating system needs to know how much memory to
allocate for that value that will be stored.
And if you attempt to store a double value in the memory
address that's been allocated to pInt.
It will be too large and double is essentially eight bytes,
the int is four bytes.
So we will actually go beyond the memory address that has been
allocated by the operating system.
Now in modern operating systems and
compilers, that assignment wouldn't be allowed.
So it would be an exception or
an error generated to kind of tell you that.
But on older systems, that could have been a source of problems,
bugs in the code.
Because you were storing a value that was too large for
the memory that was allocated.
So once we have assigned a memory address dynamically
from the operating system to these two pointers.
We will then use the dereference operator and
we will assign values to those.
So in this case, we'll assign 3 to our memory location
that's pointed to by pInt and then we will assign 5.0
to the memory that is allocated to pDouble.
Once we've done that assignment, we'll then print out the value
that is stored in each one of those memory locations.
And we'll use the dereference operator to get access to
the variables.
We will also print out just for
our own purposes, the address of those variables as well.
And then what we;re gonna do is take a look at how C++
deals with the size of address pointers versus
the size of the values that are stored in them.
And then finally, we're going to release those pointers down here
at the bottom.
So let's start this code with a Ctrl+F5.
And I will just drag this off to the side so we can once again,
can scroll and look at the code that gets executed in
what the output looks like.
So, we declared our pointer variables up here.
The operating system has returned dynamic memory
addresses for these two variables.
We have assigned values into those two memory locations and
then we start our output statements.
So in the first one we're saying that the value stored at pInt is
again, using in direction we get the value.
Then we output the memory address of that variable.
So in this case, we can see the value stored at pInt is three,
which is what we assigned.
And the memory address starts at 9B0210,
so this is a hexadecimal memory address.
Our next line executed was basically
the value stored at pDouble which was five.
You'll notice a difference because we stored 5.0 and
it's only outputting 5, so
it's basically dropped off the fractional part of that value.
And that's perfectly fine.
I haven't used format specifiers to indicate
how I wanted this to display.
Just know that we're actually storing that value in that
memory location.
And then we get the memory address for
pDouble which is in this case is 9B2228.
And again, these are dynamically assigned from
the operating system.
We have no say as to what those memory addresses will be.
Then we output our size of statements down here.
So in the first one, we're dealing with again, our pInt.
So that the size of pInt and
pInt is a pointer which stores a memory address.
So the size of that is four bytes.
So that basically means that the pointer is
of size four bytes in order to store that memory address.
But the size of the value stored in pInt is also four.
Now that just simply means that we are storing an integer type
in pInt or in that memory location.
And an int type in C++ on this particular computer
is four bytes in size.
Now if we look at the double,
the size of pDouble is still only four bytes but
yet the size of the value stored there is eight.
So why is there a discrepancy between these two?
Well again, for the memory architecture in this computer,
if memory address fits within four bytes of space.
So this is why the size of our pointer
is four bytes regardless of the data value stored in it.
But the value stored in pDouble is a double,
which is twice the size of an int.
So therefore,
it's actually being stored as eight bytes in the computer.
What that essentially means,
you can perform a little bit of memory address arithmetic or
pointer arithmetic if you want to.
In taking a look at saying, if the size of my pointer int
is four bytes, the value should be four bytes in size.
It's stored in that memory location.
Then essentially, the values would be stored in 9B0210, 211,
212 and 213, that's my four bytes of memory address space.
Likewise if we did the binary math or
hexadecimal math if you will on this memory address,
we would find eight bytes of that added to 9B2228.
Would give us the ending address of what pDouble would be and
so the value wouldn't go beyond that.
So once we've executed all these statements, it's important for
us to actually release the memory back to the operating
system so that other applications can make use of it.
And that's what the two delete statements are doing down here.
We're not outputting anything specific saying that the memory
has been delete.
Because once we delete the memory address or
the memory that's associated with these pointers,
those pointers go out of scope and they're no longer available.
So we can't really do anything with them.
If we attempted any line of code that acted on pInt or
pDouble after we've done the deletion,
we would generate errors in the code.
So it's important to always ensure that every time
you have called the new keyword.
That at some point in your code, you're calling a delete
keyword to also release those memory resources.
That'll change a little bit when we start talking more about
objects in the next module.
When we start looking at creating new
objects from class files.
Because we deal with constructors in a class file
when we create or instantiate an object of that type of class.
We will deal with something called a destructor
in that class which is similar to this delete keyword.
Delete is used for
these particular types of pointers because we're pointing
to intrinsic or built-in data types.
So that's the demo on dynamic memory allocation.
And again, this is using just intrinsic or simple data types.
You'll revisit dynamic memory allocation using the new keyword
when we delve deeper into some more of the class files.
And working with objects that are class files
rather than intrinsic data types in the next module.


---

#### Module One Pointers   Managing Memory in C++   Demo: Dynamic Memory Allocation with Classes

# Dynamic Memory Allocation with Classes

>> In this demonstration, we'll take a look
at the use of dynamic memory allocation
with the class file. We will see an example of how we
dynamically allocate memory
for an object that we create in our code and then how the destructive plays
a part in the releasing of the memory resources when we delete that
object in our code itself.
So what I've done is recreated the person class here and we can see that we
have our three private member variables. For first name, last name
and age. We have our three constructors. We have a single destructor
and then ofcourse, we have encapsulated our private member variables
with setters and getters and then, we have our SayHello function
here at the end.
Now we're not making use of everything within this class for the example as we
go through this demonstration because again it's just designed to give you
an idea of how the destructor plays a part in your class, when we delete
the object in memory. So the only thing that I've really changed in our
person class, everything here is the same. We have our default constructor,
the two argument constructor,
the three argument constructor and of course our setters
and getters but the only thing really that's different is this line of code
that I've written in the destructor itself. But this is not, something you
typically do in your code but for demonstration purposes,
I put this output statement here,
so that we can see in the console window when the destructor
is actually called. So we look at our Driver program,
for the purpose of testing.
We see that we will create a Person object called pOne
and it's a pointer variable.
So, we use the new keyword to instantiate memory for this object.
We use the three argument constructor to build that object in memory
and then what we will do is,
issue a statement here just to show that we're actually dealing
with some data for the pOne object that we've created and we will
return the first name that we set in the constructor and then just to show
that it does actually exist in memory, we will output a
a memory address which has been assigned to that variable
and again, take note that we're using the address of operator here.
And then once we've completed that,
we will basically destroy the object, indicating to
the operating system that we're finished, with the object and it can
take that memory back and we do so by calling the Delete keyword.
Now you may remember this from earlier demonstrations where we show deleting
objects through dynamic memory allocation that we
just value references. And in this case, we're dealing with a
reference variable for class.
So, a destructor will actually be called once this delete statement
is executed. So let's go ahead and run this code and see what happens.
And we wait for it to compile and the command window pops up.
And in our console window, we can see that, we didn't
indeed a sign first name Tom and that's what we pull back out with the
get first name parameter in that line of code right here.
Then we ask for the memory address of pOne
and we've been given a memory address.
In this case, it ends in FE28 and then once we call the Delete keyword, we can
see that the code within that destructor was actually executed
and we output the Person destructor called statement to tell us
that the destructor was actually called.
Now just by way of an example and again proving how
dynamic memory allocation works, I'll press the Enter key to end that
and then, I'll execute the code one more time
and you notice that, the memory address now has changed.
So we've dynamically assigned memory for each one of those objects that we
created. But our application is not continuing to consume that memory
because our destructor has been called in each instance.
So get a relatively quick short demonstration just showing how we can
dynamically allocate memory for our objects in our code when we create new
instances of the class files that we've created
and through the use of the destructor.
We saw that, this simple line told us that the destructor was called simply
by us, initiating a delete statement on that particular object
and the memory was released back to the operating system.


---
---