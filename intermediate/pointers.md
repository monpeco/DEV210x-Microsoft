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