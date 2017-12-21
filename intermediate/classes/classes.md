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