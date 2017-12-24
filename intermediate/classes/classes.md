#### Module Two More C++ Classes   Splitting Classes   Introduction to Splitting Class Files

# Introduction to Splitting Class Files

If an aspect of object-oriented programming is encapsulation, then why would we split our classes into separate 
files?  Why not keep it all in one if we wish to "encapsulate" all there is about the class?

Recall that a part of encapsulation is also data hiding.  Think about your car for a bit as we use it in an 
analogous way.  A car is a complex device that contains many different components.  You are able to operate 
your car without the need to understand the complexities of the internal combustion engine or the radio electronics.  
You don't need that knowledge to be able to effectively operate the car.

Likewise, a programmer using your class files does not need to know how you have implemented your methods to 
achieve the functionality.  In fact, perhaps you have a proprietary algorithm for a spell checker that is really 
fast and you don't want anybody to know how it works.   Users of that class also don't need to know how you 
implemented the spellchecker.  They only need to know how to make use of it.   "How to make us of it" comes in 
the form of the methods and their signatures.  As long as a user knows how to call your methods and what to 
expect as a return value, if any, they can use your class in their application.

In the car analogy, the owner's manual is analogous to the method signatures.  It specifies what you can do to 
operate the car and how to interact with the car's "interface".  In the separation of class files, the header 
file (.h file), is analogous to the car's owner's manual.  It specifies what "interface" elements are available 
(methods), providing information on how to use them.   There are no implementation details in the header file 
just as there are no implementation details on the internal workings of your car's engine, in the owner's manual.

---

#### Module Two More C++ Classes   Splitting Classes   Header Files

# Header Files

In C++, your code will often contain multiple class files.  As a review, recall that class files allow 
you to model real-world objects in your code, and they also provide a container for functionality and 
behavior of coding structures.

C++ applications typically consist of multiple files.  Each of these files in your application may use 
any or all of the class files that you define in your application.  If this is the case, that class file 
definition must be the same in each and every file that uses it.  In order to avoid the duplication of 
code, C++ uses the concept of a header file and the #include preprocessor directive.

In C++, the common practice is to create your classes as two separate files.  The header file, with 
a .h extension on the filename, is used to contain the declarations found in the class file.  
Declarations include function prototypes and class constructors typically.   The actual implementation 
of the code that performs the processing, exists in the implementation file that has the .cpp or .c 
filename extension.

To illustrate an example, let's go back to one of the examples found in the Introduction to C++ course 
on edX by Microsoft.  In Module 4 we created functions that represented some common mathematical 
operations to calculate the power of a base raised to an exponent, calculate the sine of an angle, and 
finally one to calculate the average of values in an array.  For this example, we will start to focus 
on building our own math library.

In C++, there is an existing library called cmath.  This library contains many common mathematical 
functions and we can simply make use of cmath rather than create our own library, but the exercise of 
doing so will serve a couple of purposes in this course.  First, it will allow you to learn how to 
create class files with header files.  Next, you will learn how to deal with namespaces, which are 
covered later in this module, and finally, the culmination of the math functions that you will build 
will help to serve as a project for this course.

This sample code will provide a starter for you by demonstrating the use of header and implementation 
files for a class called Math with a function for calculating the value of a base raised to an exponent.  
We'll call this function pow.

**Math.h**

```c++
// Math.h
// Header file for the Math class

#pragma once

// Math class definition
static class Math
{
	public:

	// given base and exponent, calculate value
	static int Math::pow(int base, int exp);

};
```

Let's evaluate the code listings one at a time.  In the first section, `Math.h`, we see the header file 
for our `Math` class.  Outside of the comments we see a line that indicates #pragma once.  This is a 
preprocessor directive that tells the compiler to only include this header once, regardless of how 
many times it has been imported in the program.

Next we see the class definition, static class Math.  The static keyword needs a little explanation 
so let's get that out of the way first.  When we declare a class as static, it is an indicator that 
we do not have to instantiate the class to use it in our program.  For example, if Math were not 
static, before we could use it in our program, we would need to create an instance of it as shown here:

```c++
Math math = new Math();
math.pow(2, 8);
```

For the Math class that we are creating in this course, we will consider it to be a utility class 
and therefore we want it to be static so we don't have to create an instance each time we want to 
use functionality in that class.

Next, our class definition continues with the opening curly brace and then the keyword `public:`   
Anything after the public: keyword is considered to be of public visibility.  That is, it can be 
called from other classes directly.   

After public: we declare our function for generating the power of a base raised to an exponent.  
Note that this method is also using the static designation.  In order to call the function from a 
static class, the function must also be static.

Note that the function contains no implementation details however.  We simply indicate the data 
types of the parameters that we expect to use with this function.  As a matter of fact, we don't 
even have to use parameter names in this declaration at all, simply using `static int Math::pow(int, int);` 
is sufficient as we only need to indicate the data types that are expected by the function.

The last key piece to note about this declaration of the Math class is that we end it with a 
semicolon after the closing curly brace.  Most new programmers have a tendency to forget this.  
Microsoft Visual Studio automatically adds the semicolon for you and many newer IDEs may also 
do the same.

For more information , you can see: 
C and C++ with Visual Studio: https://aka.ms/edx-dev210.2x-vs02

---

#### Module Two More C++ Classes   Splitting Classes   Implementation Files

# Implementation Files

Let's now look at the implementation file, the one with the .cpp extension and the file that 
contains the actual functionality.

**Math.cpp**

```c++
#include "stdafx.h"
#include "Math.h"

int Math::pow(int base, int exp)
{
	int result = 1;

	for (int i = 0; i < exp; i++)
	{
		result = result * base;
	}

	return result;
}
```

**MathTest.cpp**

```c++
// MathTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Math.h"
#include <iostream>

using namespace std;

int main()
{
	int result = Math::pow(2, 10);

	cout << result << endl;

	return 0;
}
```

Let's evaluate the code listings one at a time.  In the first section we saw Math.h, the 
header file for our Math class.  In this section, we discuss the Math.cpp file.  This is 
the implementation file for the Math class.  

We open the class file with two #include statements.  One includes the stdafx header file 
and the second brings in the Math header file.  The stdafx.h file is the precompiled header 
directive that is used in Visual Studio but some other compilers also make use of it.  Next, 
we include Math.h because the compiler needs to know what functions are part of this class.  
Recall the discussion about function prototypes.  These now exist in the header file and 
not in the .cpp file.

The rest of the class contains the implementation details for calculating the power function.  
The function name looks a little different now.  Instead of just the function name, we are 
using Math::pow as the function name.  This is using the concept of a scope resolution 
operator (::).  There are a couple of uses for the scope resolution operator, and it will 
be covered again in the discussion on namespaces but, in this instance, it is required to 
call static members of the class.  

The code in this function implements the functionality using a for loop to calculate the 
base raised to the exponent provided.  Also note that there is no semicolon at the end 
of the closing curly brace.

Finally, in MathTest.cpp we see our standard main() function that we use for testing 
purposes.  Some refer to this as a driver program used for testing our code.  In the main() 
function, declare an int variable called result and assign it the value that is returned 
from the pow function in Math.   Note the use of the scope resolution operator again (::) 
and that we did not create an instance of the Math class but simply called the function 
directly on the class itself.  This is an example of a static class in action.

So how exactly does the header file factor into our code?  It is a concise method of 
describing what the class is intended to do.  In other words, it provides a look into the 
functions that exist in a class without concerning ourselves with the implementation 
details of those methods.  It also provides us with a mechanism to help reduce coding 
bugs by having the compiler catch omissions and misuses of the class and its components.  
However, once again think about declaring a class in your applications main file, the one 
that includes main().  In our sample code with the Math class, if we did not include the 
Math.h file directive in MathTest.cpp, then MathTest will have no knowledge of Math.cpp 
and the compiler will generate an error.  By placing the include directive in MathTest.cpp, 
the compiler will actually make a copy of the contents of Math.h inside MathTest.cpp, 
which will mean that the function declarations will be included, and the compiler will 
understand the Math class.

---

#### Module Two More C++ Classes   Splitting Classes   Demo: Header and Implementation Files

# Demo: Header and Implementation Files

TODO: missing video 


---

#### Module Two More C++ Classes   Constructors and Destructors   Class Constructors

# Class Constructors

Let's now turn our attention to the concept of constructors and destructors in our classes.  
The topic of constructors was covered briefly in the Introduction to C++ course but we'll 
offer a review here and expand on the topic of constructors in this lesson, adding in 
concepts around destructors.

A constructor is used to initialize data members of a class.  The format of a constructor, 
at its most basic level, is that it contains the same name as the class itself, has no 
return type, and may or may not contain a parameter list.  Constructors are also, almost 
always, public although you can have a private constructor for use within the class only.  
Some developers create a private constructor that is called via a public constructor, for 
the purposes of initializing private aspects of a class.

Classes can have multiple constructors.  Constructors can be overloaded in the same way 
that functions can be overloaded.  If you don't create a constructor in your class file, 
the compiler will create a default constructor automatically that will initialize member 
variables to default values.  A class has one, and only one, default constructor.  If you 
do create a default constructor or any other constructor in your class, then the compiler 
will not create one.  This is an important consideration because if you require or want a 
default constructor as well as other constructors, then you MUST create your own default 
constructor.  The default constructor, if provided, is one that does not have any 
parameters such as:

```c++
class Person
{
public:
	Person();
	~Person();
};
```

This code sample demonstrates the template that is provided in Microsoft Visual Studio when 
creating a new C++ class.  It completes the template with a very simple class definition 
that includes the class name (`Person`) and two public members, the default constructor (`Person();`) 
and the destructor (`~Person();`).  Destructors will be covered in the topic on destructors.

There are actually two more, equally important, reasons for defining a default constructor 
in your classes.  First off, compound types (arrays or pointers) that may be defined inside a 
code block, can have undefined values when initialized to their default values.  You should 
ensure that these members are initialized correctly by creating your own default constructor 
and performing the initialization yourself.

The second reason is a little more complex and arises when your class contains a member that 
is a class itself.  The compiler's default constructor is unable to initialize that member.

The following code sample demonstrates the use of three different constructors, one default 
constructor, one that accepts two arguments and one that accepts three arguments. 

**Person.h**

```c++
#pragma once

#include <string>

class Person
{

private:
	std::string firstName;
	std::string lastName;

	int age;

public:
	Person();

	Person(std::string fName, std::string lName);

	Person(std::string fName, std::string lName, int age);

	~Person();

	void SayHello();
};
```

**Person.cpp**

```c++
#include "stdafx.h"
#include "Person.h"
#include <iostream>

Person::Person()
{

}

Person::Person(std::string fName, std::string lName)
{
	firstName = fName;
	lastName = lName;
}

Person::Person(std::string fName, std::string lName, int age)
{
	firstName = fName;
	lastName = lName;

	age = age;
}

Person::~Person()
{
}
```

The first constructor is the default constructor.  It has no parameters and because we have 
not initialized our private member variables, this constructor will do so with the default 
values for data types of those member variables.

The second constructor takes two arguments and uses those to initialize the first and last 
name member variables in the class.  Here is where you need to do a little research on the 
compiler you are using to determine how the age variable will be initialized.  The reason is, 
because we do not initialize age in the class when we declared it and because this constructor 
does not initialize it either, if you try to use the age variable in an instance of Person, 
what result will you get?  The default constructor will initialize age to 0 but if you call 
the second constructor, age may or may not get initialized.

The final constructor takes three arguments to initialize all three member variables.  When 
you create a new instance of the Person class, you can choose any of these constructors and 
the compiler will know which one to use based on the number of arguments you pass in as 
shown in this code sample.

```c++
#include "stdafx.h"
#include <iostream>
#include "Person.h"

using namespace std;

int main()
{

	// create a Person instance using default constructor
	Person *pOne = new Person();
	
	// Create a Person instance using 2 argument constructor
	Person *pTwo = new Person("Tom", "Thumb");

	// Create a Person instance using 3 argument constructor
	Person *pThree = new Person("Tom", "Thumb", 15);

return 0;
}
```

For more information , you can see: 
C and C++ with Visual Studio: https://aka.ms/edx-dev210.2x-vs02

---

#### Module Two More C++ Classes   Constructors and Destructors   Class Destructors

# Class Destructors

Now that we know how to create objects, and we know that they consume memory while they 
hang around in our application's executable memory space, we also need to know how to 
release that memory when we no longer require the objects.  We do so with the use of a 
destructor.

In the previous code samples, you may have noticed that the destructor looked a lot like 
the default constructor, only preceded with a tilde (~).  While it looks similar to the 
a constructor, having no return type and the same name as the class, except for the tilde, 
it's important to note that a destructor cannot have any arguments passed in to it.  
Therefore, when writing your own destructors, you should not place arguments between 
the parentheses for the destructor.

The compiler will handle the actual calling of the destructor when your object expires or 
the application is closing.  If you choose, you can place code inside the destructor.  
One reason you may want to do this is to ensure that any resources used by the object, 
that may not be destroyed or cleaned up, are taken care of in your object's destructor 
code.

---

#### Module Two More C++ Classes   Constructors and Destructors   Dynamic Memory Allocation and Classes

# Dynamic Memory Allocation and Classes

When your application is coded, you may have no idea how many Person objects you will 
need during the program's lifetime.  As a result, it is likely not possible for you to 
create sufficient Person objects in code and let the compiler determine how much memory 
is required for these objects at compile time.   Chances are, you will be creating many 
objects dynamically as your application code executes.   In order to do so, the 
application must request memory from the operating system as the application is executing, 
(dynamically).  

This topic discusses the importance of two C++ keywords new and delete.  The keyword new is 
used to allocate memory for an object at runtime and delete is used to release that memory.  
This is also where the constructors and destructors play a big part.   You will also need to 
change the way you call functions and work with the objects, and we'll cover that in this 
topic.

Dynamically allocating memory to hold an object is done with the new keyword. Using the new 
keyword means that you must be making the assignment to a pointer of the correct data type.  
The following code shows a valid and an invalid use of the new keyword.

```c++
Person *pOne = new Person();

Person per = new Person(); 
```

In the first line, we declare a pointer called pOne that will hold the memory address of a 
Person object that will reside in an area of computer memory known as the heap.  When the 
new keyword is encountered, the computer will set aside enough memory to hold a Person 
object in memory and assign that memory address to the variable pOne.   We have not 
created an actual object in memory yet, we have simply asked the computer to allocate 
sufficient memory to store the object.   How does it know how much memory is needed?  
In the case of our Person class, the size is determined by looking at all the member 
variables, (the classes data), and based on the data types, it determines the maximum 
amount of memory required for the object.  No values are assigned at this time either 
so the compiler uses the maximum size of the specified data type for each member variable.

What happens if our class contains other classes nested within it?  The compiler will 
look at all the members of those classes as well and allocate sufficient memory for them 
as well.

In the second line of code above, we simple declare a variable to be of type Person and 
call it per.  However, the use of the new keyword is not legal here, at least when using 
Microsoft Visual Studio 2015.  The error message returned from the compiler indicates 
that "No suitable constructor exists to convert from Person * to Person."   This clearly 
indicates that new is seeking a pointer and not an object variable.

Once you have used the new keyword to dynamically create an object in memory, the way 
in which you access the member variables and functions is a little different than simply 
using the dot operator like you might be familiar with in other languages such as C# or 
Java.  You will now need to use the arrow selection operator to access the members of the 
class, as shown in the following code sample.

```c++
Person *pOne = new Person("Gerry", "O\'Brien");
std::cout << pOne->GetLastName() << endl;
```

In the first line of code, we declare a pointer *pOne and assign it a memory address using 
the new keyword.   The compiler sets aside memory for the object and assigns the first and 
last name values to the member variables using one of the constructors in our Person class.  
(Refer to previous code samples for the constructors).  Because the object has been 
dynamically allocated with the new keyword, we must use the arrow selection operator and we 
see that in the second line of code where we access the GetLastName() member function to 
retrieve the value stored in the object pointed to by pOne.

For every object you create using the new keyword, you also need to use the delete keyword 
to remove the reference to the memory allocated and to release that memory back to the 
operating system.  Failure to do so results in a memory leak in your application.  The memory 
that is taken up by the object is not released back to the operating system until you call 
delete or until the application quits.  If you continue to allocate new objects with new and 
fail to use delete when finished with those objects, the memory used by your application will 
continue to increase.  The use of delete is rather simple as the following code snippet 
demonstrates.

```c++
Person *pOne = new Person("Gerry", "O\'Brien");
std::cout << pOne->GetLastName() << endl;

// delete object, releasing memory
delete pOne;
```

When delete is called on an object, that object's destructor is called.  The destructor is 
the correct location in code perform clean up operations on your object and anything that 
it references.  For example, you might have dynamically declared and used other objects 
from within your object.  In this case, you are responsible for ensuring that those other 
objects are also destroyed and that their memory is released.  You do this by placing the 
appropriate delete statements inside your object's destructor.

---

#### Module Two More C++ Classes   Constructors and Destructors   Demo: Constructors

# Constructors Demo

https://youtu.be/qX2he0bQ8P0

>> In this demonstration we're going to take a look at how we call
the three constructors in our Person class.
So, we have the person header file up here
screen just so that we can go back
and remind ourselves quickly of the three different constructors.
We actually created within our person
class or default, that accepts no arguments.
Second constructor which will accept the first and last name
and then the third constructor which is looking for a first name, last name
and an age. Now the we also destructor present here,
within our personalities class as well.
So how do we make use of these within our code.
Well if we come back to our using constructors that
cpp implementation file.
Within our main method this is where we're going to create some objects of
type person within our code, and then we will implement the functionality,
of the constructor simply by calling them.
Notice at the top of the cpp file, I have included
the Person.h or the Person header file.
Even though our person cpp so, the implementation file
contains that header file, include statement.
when we're using it in our application,
any other implementation file that needs to be aware of
the member variables and functions for the person class
will also need to have the header file included as well.
So, now that we've got that included. Let's go ahead and create our first
person object which will be pOne and we will implement
default constructor for this particular one
we'll just simply say new person.
Open close the parentheses semicolon
and that's a valid call to the default constructor for pOne.
Let's go ahead and create a couple more so, we'll do a person
let's call this one pTwo and this equals new person
and in this case we're going to use the second
constructor for the person class which is looking for
a first and last name. And as we start to type once
we've actually typed in the separating comma for the
parameter list within our
constructor that we have here.
You'll notice that visual studio has popped up
our little intellisense window telling us
probably what is going to be the constructor that we're going to call
and it's based on for being four different
overloads that we have available.
This one here being accepting the first and last name
and you can see the parameters listed here.
If we click the drop-down will actually start
going to cycling through the different
constructors that visual studio see's.
The first one obviously is our default which accepts nothing.
The second one is a constructor that we didn't create.
But the compiler recognizes and creates
one that will accept the reference to a person object itself
and then of course the second one we're calling
which is looking for the first and last name.
And then we will enact that third or in the intellisense list fourth
constructor here for pThree
and in this case we will pass in the values for the first name, last name
and the age as well so, we'll put in tom on begin
when we type in the comment here we can see that it's not looking
for an age value will put 25 in for that.
And then we have created calling code for all three
of the constructors that we've written within our person class.
Now it's also important to note to that each one of these
objects that we've created the pOne,pTwo and pThree
will exist on the heap of the computer's memory, because we ask
to allocate we'd ask the operating system to allocate memory for these
and only when our application ends
will these objects go out of scope and actually be destroyed.
We'll cover that more in the topic on Dynamic Memory Allocation
with your classes and where we will
take a look at the new keyword and the delete key word
but the reason I bring it up here is because one of the things that
you'll note that we don't have in the code here is an actual call
to the destructor of the class and that's not something that we typically call
directly, by using the delete keyword
the compiler calls the destructor for that class for us
and we'll see an example of that again a little bit later on in another demo
when we focus on the Dynamic Memory Allocation.
So, again this demonstration was just to show how we can,
create and call the constructors within our classes that
as we create objects of those within our code.

---

#### Module Two More C++ Classes   Scope in Classes   What is Class Scope?


When we discuss scope in the context of classes, we are referring to the names of member variables and member 
functions found within the class definition.  The scope of a class within a namespace or program file is not 
covered in this topic.

Within a class, all of the member variables and functions are available to the class's functions.  Note that 
the members of a class can have access modifiers too such as private and public but that determines their 
visibility from outside the class.  All public and private members are available within the class to functions 
inside the class.

When accessing the members of a class, you use the class name followed by either a dot operator (`.`) or the 
arrow member selection operator (`->`) then the name of the member (variable or function).  Any variables 
declared inside a member function are local to that function in the same way as any other function implementation 
in C++.

Also note that the way you call a class member will differ depending on the type of class member.  For example, 
for accessing static members, you do not use an instance name but rather the class name as in `Math::Sum()` as 
opposed to Math myMath; and then `myMath.Sum()`.

Class scope permits the creation of class level functions and variables that will not conflict with functions 
or variables of the same name in a different class.   If we had two different class files such those shown 
below, the application knows which Speak() function to call based on the classes instance name.

```c++
#include "stdafx.h"
#include <iostream>
#include "Person.h"

using namespace std;

int main()
{

	Person person;
	Dog dog;
	
	person.SayHello();
	dog.SayHello();
	
	return 0;
} 
```

Assume that we have two classes called Dog and Person and that the Dog's SayHello() function will output "Woof" and 
the Person's SayHello() function outputs "Hello".  When you call `person.SayHello()`, the compiler knows which 
SayHello function to call because it is associated with the person object which is an instance of the Person class.  
Therefore, that SayHello() function will be executed.
 
By way of example of how to call functions using the different operators, let's consider the Person class that has 
been used in the Constructors topic, which is recreated here.

**Person.h**

```c++
#pragma once

#include <string>

class Person
{

private:
  std::string firstName;
  std::string lastName;

  int age;

public:
  Person();

  Person(std::string fName, std::string lName);

  Person(std::string fName, std::string lName, int age);

  ~Person();

  void SayHello();
};
```

**Person.cpp**

```c++
#include "stdafx.h"
#include "Person.h"
#include <iostream>

Person::Person()
{

}

Person::Person(std::string fName, std::string lName)
{
  firstName = fName;
  lastName = lName;
}

Person::Person(std::string fName, std::string lName, int age)
{
  firstName = fName;
  lastName = lName;

  age = age;
}


Person::~Person()
{
}

void Person::SayHello
{
  std::cout << "Hello" << std::endl;
}
```

As we look at the Person.h and Person.cpp files, we notice that we have three private member variables, three 
public constructors, and one public method named SayHello().  To demonstrate the scope of member variables in 
a class we have also created the following main.cpp file.

```c++
#include "stdafx.h"
#include <iostream>
#include "Person.h"

using namespace std;

int main()
{

	// create a Person instance using default constructor
	Person *pOne = new Person();
	
	// Create a Person instance using 2 argument constructor
	Person *pTwo = new Person("Tom", "Thumb");
	
	// Create a Person instance using 3 argument constructor
	Person *pThree = new Person("Tom", "Thumb", 15);
	
	Person p;
	
	Person &pRef = p;
	
	p.SayHello();
	
	// pointer method of calling a member function
	pOne->SayHello();
	
	// reference method of calling a member function
	pRef.SayHello
	
	return 0;
} 
```

In this code that makes use of the Person class, we see different ways of accessing the members of the Person 
class using instantiated objects.

On line 07, we dynamically allocate memory for a new Person object called pOne by using a pointer and the new
keyword.  We do the same with two other pointers on lines 10 and 13.  The differences are that we are calling 
different constructors for each one.  pOne uses the default constructor, pTwo uses the 2 argument constructor 
while pThree uses the 3 argument constructor.  Constructors have class scope as well as they are declared 
within the class file.

On line 15, we create a new Person object called p without using a pointer or the new keyword.  The way that 
we declare our objects is important for determining how we call the member functions or access the public member 
variables as shown in this code sample.  On line 17 we declare a new reference variable that is a reference to 
the Person object we called p.  We call the SayHello() member function on p by using the dot operator on line 
19 and that works.  We also call the SayHello function on line 25 using the dot operator and that works as 
well because we set pRef as a reference to p.

Note on line 22 however that in order to call the SayHello() function from the dynamically allocated Person 
object called pOne, we had to use the member selection operator (->) to gain access to the SayHello() function.

