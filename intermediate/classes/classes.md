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

---

#### Module Two More C++ Classes   Scope in Classes   Demo: Class Scope


# Demo: Class Scope

>> In this demonstration we're going to take a look at how to use class scope
within our classes. For this particular demo we have a person class.
So our person header file shows that we have our three private member
variables for first last in age.
We also have our three constructors and our destructor but
we've also added some setters and getters and then we have our Say Hello
function and these are all public functions which means that they are
accessible outside of the class.
When we create our classes in the sample code will see that
we call a couple of these functions and how they actually behave
based on the classic we are calling or the classes were using. We also have the
dog class and the dog class looks pretty much identical to our
person class. We have three private
member variables three constructors and destructors
setters, getters and another public function called Say Hello!
The reason we're showing you that the dog class in a person class are the
same in structure is because we have function names that are identical
in each one of the class files.
This is a part of what we talked about in the theory for this portion, where we
talked about the class scope meaning that we can use the same names
for variables and for functions within different classes and not have a
compiler get confused as to which one we are referring to, it will be
basically inferred by the class.
We are using so the compiler will know which one of these functions
we are actually calling. So let's go ahead and take a look at our
little driver program here we have classscope.cpp we are bringing in the
person and dog header files. So that our main class here our main method
knows about these two classes.
In our first line here we are creating a new person variable
using a pointer called p and we are using the constructor that accepts a
first and last name then what we will do is we will output a statement to the
console window. By using the get first name to pull, the first name that we have
assigned from that person object.
Then we will call the Say Hello function on that person object.
Once we've completed that will then create a new dog object pointed at
by the variable D and we will use the same constructor the two valued
constructor,but you'll notice we have a different first name
for our dog then we did for the person.
Then we will do the same thing again, we will output the dogs first name
by calling to get first name function and then we will ask the dog to
Say Hello and again the whole purpose behind this is just to really realize
and recognize that we are using function names that are identical.
So the exact same function name
in each one of these calls, but because of class scope the
compiler will know exactly which ones we are referring to.
So let's go ahead and run this code and see what happens, you'll notice in our
first line here in the console window the person's first name is equal to Tom
and indeed that is what we set for
the person's first name here. The Say Hello function output
the word hello to the screen then we've created the dog object
and we set the dogs first name remove this console window just up here
a bit and we'll see that the dogs
first name was Fido and we see that when we output what the dog first name was
indeed it was Fido and then when we called to Say Hello woof was printed
rather than hello. So again
focusing on the implementation details in the person class. We had to
get first name which would return this first name. So the first name for that
specific instance. but also in our Say Hello function we are simply
the output into the console Hello.
In the dog implementation we still had to get first name using the this
keyword but we also had to Say Hello function and in this case it's simply
said woof in the implementation.
So again it's just a quick demonstration to show you
how class scope plays into calling classes with functions that have the
same names or even dealing with functions that have the same member
variables again the class scope means that those member variables
and functions are hidden inside the class in terms of the compiler
knowing which one to call.
So they're not technically hidden because their public
but when you call a function on a class. The scope
is based on the class name or the object that it's pointing to
when the compiler looks for which function it is to call.


---

#### Module Two More C++ Classes   Scope in Classes   Encapsulation

# Encapsulation

When we consider the term encapsulation we should be clear on the context in which we are using it.  
We can say that encapsulation is the programming language aspect that permits the inclusion of data 
and functionality into a single package.  In this definition, inclusion means to take all of the data
(member variables) and functionality that acts on that data (member functions) and enclose it within 
the definition of a class file.

The second definition is considered data hiding or data restriction.  As an example to help explain 
this definition, consider the case of our Person class used in previous topics.  We may want to ensure 
that a user of the Person class cannot set the first name, last name, or age member variables directly.  
In our sample code, we have declared these member variables to be private, which means direct access is 
not possible.  The only way, in the current code sample, to set these variables' values is to use the 
constructor.  

A best practice is to also provide public functions that allow users of the class to change these values 
but indirectly.  That is to say, they can only modify the values through the use of a public function.  
Inside that function, you, as the developer, control how data passed in from the user is handled.  For 
example, you might want to validate the data passed in for the age variable to ensure it is a valid age 
for the intended purpose.   In other words, if a user attempts to pass in a negative value or a character 
value for age, your public method could check for these instances and handle the situation appropriately. 
You might send an error message to the user or you could trim blank spaces, etc.

The important part of encapsulation from the second definition perspective is that users of your class 
have no insight into how you set the values or validate the information.  It's indicative of the way in 
which you require absolutely no knowledge of the internal combustion engine in order to turn the ignition 
key and start it.

To implement encapsulation in our Person class, we could add the following code to the Person class to 
facilitate setting and retrieving the values for the member variables.

**Person.h**

```C++
#pragma once

#include <string>

class Person
{

private:
    std::string firstName;
    std::string lastName;

    int age;

public:

    int count;
    Person();

    Person(std::string fName, std::string lName);

    Person(std::string fName, std::string lName, int age);

    ~Person();

    void SetFirstName(std::string fName);
    std::string GetFirstName();
    
    void SetLastName(std::string lName);
    std::string GetLastName();

    void SetAge(int age);
    int GetAge();

    void SayHello();

};
```

**Person.cpp**

```C++
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

void Person::SetFirstName(std::string fName)
{
    this->firstName = fName;
}

std::string Person::GetFirstName()
{
    return this->firstName;
}

void Person::SetLastName(std::string lName)
{
    this->lastName = lName;
}

std::string Person::GetLastName()
{
    return this->lastName;
}

void Person::SetAge(int age)
{
    if (age > 0)
    {
        this->age = age;
    }
    else
    {
        std::cout << "Please enter a valid age" << std::endl;
    }
}

int Person::GetAge()
{
    return this->age;
}

void Person::SayHello()
{
    std::cout << "Hello" << std::endl;
}
```

**Test Program**

```C++
int main()
{
    Person p;

    p.SetFirstName("Gerry");
    std::cout << p.GetFirstName() << std::endl;

    // this line will output an invalid age message due to the 
    // validation check in the SetAge() function
    p.SetAge(-5);

    // this line will not work because firstName is private
    p.firstName = "Gerry";

    return 0;
}
```

In our revised code, we have added some functions to set and get the member variables.  Outside of the 
constructors, this is the only way to set these values and now we actually have functions that will 
return these values if we need them in our program code.

In our sample test program code, we declare a Person variable called p.  We then use the dot notation 
to call the SetFirstName() function and also call the GetFirstName() function to output the value to 
the console window.  The SetFirstName() does nothing special other than to set the firstName member 
variable to the value passed into the function call.  

Next we called the p.SetAge() function and passed in a value of -5.  This is, of course, an invalid age 
value.  In our SetAge() function, we have simple logic that just checks to see if the value passed in 
is greater than 0. If it is, the assignment is made but if not, a message is sent back to the user of 
the application.   The encapsulation aspect to this is simple that the user has no idea what validation 
code we have placed in SetAge(), nor do they know how we are checking the age, setting the age, or 
outputting the message.   They simply see the results of the function call.

Finally, in the last part of the code we attempt to set the firstName member variable of the p object 
directly.   This will generate a compiler error when you attempt to compile the program code.  Depending 
on your compiler, the error message may differ but Visual Studio 2015 will give the error '=': function 
as left operand.  In fact, the Intellisense feature in Visual Studio will not even list private member 
variables for auto completion of code which should be a clear indicator to the developer that the line 
of code contains an error.


---

#### Module Two More C++ Classes   Scope in Classes   Namespaces

# Namespaces

Class scope covered an important aspect of working in C++ with class files but it isn't the only place 
that scope comes into consideration.  C++ provides the standard template library (STL) that consists of 
many classes and functionality.  It is conceivable that at some point in your career as a software 
developer, you will create classes with names that conflict with those in the STL or with other code in 
a software project.  C++ uses namespaces to help resolve these conflicting issues.

A namespace is a "scope container" where you can place your classes, variables, or other identifiers to 
prevent conflicts with others.  Anytime you want to reduce ambiguity or name collisions, you use the 
namespace designator ahead of the identifier.  You have already seen an example of this in the sample 
code used so far in this course with std::cout.  the cout function exists in the namespace std.  
The :: is the scope resolution operator and allows you gain access to the cout function in the std namespace. 

A contrived example where you're code also contains a function called cout might cause naming collisions 
and ambiguity if your code required the use of std::cout and your cout function, unless you used namespaces.  
For example, you might create a namespace for your code such as myNS.  In which case if you needed to use 
both cout functions in your code, you would call the C++ version using std::cout and your version using 
myNS::cout.   In this way, there is no ambiguity as to which function you are calling.

C++ also permits the use of using statement to help reduce the amount of code that you have to tyep when 
classes are inside a namespace.  For example, you could place the following statement at the top of your 
C++ file:

**using namespace std;**

By doing this, you can now simple use cout << "Hello"; in your code instead of typing the namespace and 
scope resolution operator, saving you some keystrokes.   However, take note that you cannot apply using 
statement if there is a chance of ambiguity in the code.  For example, you could not use the following code:

```c++
using namespace std;
using namespace myNS;

int main()
{
  cout << "std version of cout";
  
  cout << "myNS version of cout";
}
```

The compiler has no way of knowing which cout to call in these two lines.  However you could 
theoretically write code such as:

```c++
using namespace std;

int main()
{
  cout << "std version of cout";
  
  myNS::cout << "myNS version of cout";
}
```

You can define your own namespace by using the keyword namespace, followed by the chosen name 
and then enclosing your code within the curly braces.  You also have the option of creating 
nested namespaces if you choose to provide more separation of identifiers in your code.  Just 
remember that each namespace you nest, creates more code you need to type.  A code sample 
demonstrates this.

```c++
namespace Microsoft
{
  namespace Geometry
  {
      const double PI = 3.14159;

      double Area(double radius)
      {
          return PI*(r*r);
      }
  }
  
}
```

**Example with using statement**

```c++
using namespace Microsoft;

int main()
{

  double radius = 12.5;

  double area = Geometry::Area(radius);
}
```


** Example with using statement**

```c++
int main()
{

  double radius = 12.5;

  double area = Microsoft::Geometry::Area(radius);
}
```
To keep the code simplified so we can focus on namespaces, we have omitted classes and access modifiers.   
In the first code segment we have created a namespace called Microsoft and a nested namespace called Geometry.  
Within Geometry we have a constant to represent PI and a function that will calcuate the area of a circle 
given a radius.  The second and third code segments show how we would make use of this namespace and function 
in code.

---

#### Module Two More C++ Classes   Scope in Classes   Demo: Namespaces

# Namespaces Demo

https://youtu.be/6d7yZJAiB0I

>> In this demonstration we're going to take a look at how to make
use of Namespaces
within your code. Now again thinking back on the textual content of
what we covered Namespaces in this particular module, we said that we use
Namespaces to help avoid class name collisions and to help us have the
ability to utilize class names
and our code that might exists in other libraries.
And as an example, I have the math.h or the math header file brought into my
application, now this is the standard, C standard library math header file.
and this includes all kinds of functions for doing trigonometric
things such as sine, cosine,tangent,
you can do Raising's to the power of an exponent, you can
call square root functions, you can deal with Floor, ceiling and center all kinds
of different mathematical functions here.
And this comes in the C standard library
and you may have a need to include this in some of your application code.
Will talk a little bit about,
how this creates a potential conflict in just a moment.
But I wanted to give you an example of how we utilize some of that code, so from
the math header file have actually done and include statement up here which is
cmath and for c++ we typically bring this in
and it includes some macros but
ultimately it brings in this math.header file for us with all of that
functionality. Will cover this one in just a moment when we see the little
special math class that I've created for this instance. Now in our main function
I have two different lines that are calling
some mathematical functions out of
that math header file. One for square root and one for power,
so we'll raise 2 to the power of 4
and if I execute that code you'll see that indeed this information
does print it correctly on the screen.
So once the code executes the square root of 2.3 is displayed
and then 2 raise to the power of 4 is indeed 16. Now one of the
reasons why I showed you that was, to give you an idea of why we might want to
create our own math class and in this instance if you remember from back in
your days of mathematics anytime that we use a negative
exponent on a power-- or call to a power function
such as this, any value
raised to a negative exponent is always going to give us a value of zero in
while mathematically that's true that may not necessarily be exactly what it
is that we're after. So instead what we want to do is we want to create our own
class that kind of handles that situation for us and in this case I've
done that with a math class that I've created myself.
Now I've declared it is a
static class and the reason I've done this is because I don't it's a utility
class. So I don't want to have to create an instance of this class, you know to
instantiate it and create an object to deal with that. I simply want to be able
to call the functions that exists in that class. So I've declared its static
and I've created one static method that's public inside of it and it's
called pow. So I'm going to create my own
function to raise a value to
an exponent and as we take a look at it, you'll see that this one I'm particularly
going to return it an integer value
and I'm going to accept two integer values
coming in. If we come into our C standard library header 1 and we do a quick
search and in this case we're looking for the power function we can see that
this particular header file shows us that we have one that accepts doubles
and returns doubles and if we search a little bit further on we can see that we
have another overloaded one for float etc--.
So we can continue on
look at all the overloads that are available in that header file. But the
simple fact of the matter is that, that there isn't really one this displaying
integers it will do some implicit data conversion if we pass integers in. But in
my implementation of the math class,
what I want to be able to do is, I want to be
able to check for a negative value because I don't want anybody passing it
in. We could go into any number of reasons for why this might be I could be
creating a calculator application for students to understand how to work with
exponents and we didn't want to deal with negative values. So really all I've
done here is inside my pow function where I'm accepting an integer for the
value an integer for the exponent.
I'm doing one little quick check to make sure that my exponent value is greater
than 0, If it is, I'll do the formula for calculating the power or raising that
value to the exponent it's passed in. But if it's not greater than 0
then I'm going to output a message to
the user saying, you should only enter
positive values for this exponent. So really all I've done is just created
some code it's a contrived scenario, just to show you how we can use two classes
that have the same name and a function that exists in two separate classes of
the same name. But how the compiler will know through the use of Namespaces which
one I'm specifically calling. So let's get back to our driver program Namespaces
.cpp and in here I actually have
some code that I'm going to uncomment and
this code will allow us to work with the two separate power functions that we
have. So I'll continue to call the math.h it's the C standard library power
function in math.h here and down here you'll notice that what I'm going to do
is I'm going to call my version of math
and how we tell the compiler which one
were working with is through the use of this namespace. So you'll notice in my
math. header file. I prefixed everything with the namespace and I gave
it with the namespace MyMath. So this is the designator for it
and within this code here
I explicitly tell it, I want to call the power function in MyMath namespace in
the math class found within that namespace and I'm going to pass these
values in. So let's run this code and see what happens!
We build the application and it runs in
the background and you'll see that
because we passed in that negative value, it comes back and tells us please enter
only positive values for the exponent. Now I put this line in
here as well, just to simply indicate that we are in fact inside that power
function. It didn't exist in the math. or the standard C library
math function for pow.
So in other words it turned in the what was it we were expecting it to do. So
I'll remove that negative value. Let's just to another Ctrl+F5 to run the
application again and you'll see that I didn't pass in a negative value this
time, but you can also see that indeed
the compiler new which power function to call because of that namespace code that
we've entered in there. Now to give you an idea of how the namespaces work you may
have seen some of the demo's, where we have using namespace STD or the standard
namespace here and one of the things that
I can do is, I can reduce the amount
of code that I have to type. If I were to be using this power function throughout my
code number of times, by entering this using namespace MyMath at the top and
once I do that I can actually eliminate the namespace down here in the code and
If I now compile and run this application, you should see the exact
same results that happened before.
Alright, so we still called the right power function the compiler still know
exactly how to call the power function and a part of it was because it's prefix
with the class name here and then the power function, but also because we've
introduced the using namespace statement up here as well. So this really helps to
reduce the amount of code that we have to write. So it means we don't have to
put MyMath and the resolution scope, resolution operator math scope,
resolution operator pow.
Alright, so again just a very quick and simple demo on namespaces kind of the
rationale behind, why we might want to use them in an application.
How to implement them within our math.header file simply by prefixing and
surrounding everything with the namespace in the
open, close curly braces
and then how we can import or or bring in that namespace. So we can reduce the
amount of code that we have to type in our application.


---

#### 