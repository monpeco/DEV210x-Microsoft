#### Module Three More OOP in C++   Inheritance   Inheritance Refresher

# Inheritance Refresher

New classes can be derived from existing classes using a mechanism called "inheritance".  
Classes that are derived FROM are called "base classes" and derived classes are also known 
as sub-classes.  The following is an example:

```c++
class Vehicle
{ 
    private:
       string Make;
       string Color;
       ...
}; 

class Car: Vehicle
{ 
     // member list includes Make and Color
     // other Car specific members would go here.
};
```

In this example, Vehicle is the base class and Car is the derived class.   Car automatically 
inherits the Make and Color properties and is also free to implement its own properties and 
methods that are specific for a Car.

---

#### Module Three More OOP in C++   Inheritance   Types of Inheritance in C++

# Types of Inheritance in C++

C++ supports three different forms of inheritance, public, private, and protected.  Public 
inheritance describes how a derived class inherits all the member variables of a base class, 
both private and public, but is only able to directly access the public members of the base 
class.  All members of the base class will retain their accessibility in the derived class.  
Let's see an example.

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

**Student.h**
```c++
#pragma once
#include "Person.h"

class Student : public Person
{
public:
    Student();
    ~Student();
};
```
    
**Student.cpp**

```c++
#include "stdafx.h"
#include "Student.h"


Student::Student()
{
}

Student::~Student()
{
}

// this line will cause a compiler error    
firstName = "Tom";
```

**Main.cpp**
```c++
#include "stdafx.h"
#include "Person.h"
#include "Student.h"

int main()
{
    Student student1;

    // this line will generate a compiler error
    student1.firstName = "Tom";

    // this line is ok
    student1.SayHello();

    return 0;
}
```

In this example we have a Person class.  We are only listing the header file for this 
example so as not to get bogged down in the implementation details just yet. Next we 
show the header file for a Student class.  Note that the class name Student, is 
followed by a colon and then public Person.  This indicates that Student is a derived 
class of Person using public inheritance.  Also note that the Student class contains a 
default constructor and a destructor.  These are separate from the constructor and 
destructor for the Person class.

In the main.cpp file we declare a Student object called student1.  We then attempt to 
set the firstName variable to a value.  That line of code will generate a compiler 
error even though Student has inherited the firstName member variable from Person.  
The reason is the public inheritance rule and the fact that the firstName member 
variable is declared as private in Person.  We'll cover how to access these variables 
in a little bit.  But notice that the student1.SayHello() function call will work as 
SayHello() is a public function.  Also note that in the Student.cpp class, we attempt
to use the firstName variable directly but the compiler will throw an error against 
this line as well.

At this point you might be asking what use the private member variables are if they 
can't be accessed in a derived class.  The answer is a simple one in that we need to 
go back and think about encapsulation again.  Providing public getters and setters 
for these private member variables is the proper way to gain access to them from 
outside the class.  

As mentioned, there are three types of inheritance in C++, public, protected, and 
private.  This table explains the differences:

| public | protected | private | 
| ------ | --------- | ------- | 
| public members are public in derived class and can be accessed directly by member functions and nonmember functions | public members become protected members in derived class and can be accessed directly by member functions | public members become private in derived class and can be accessed directly by member functions | 
| protected members are protected in derived class and can be accessed directly by member functions | protected members become protected members in derived class and can be accessed directly by member functions | protected members become private in derived class and can be accessed directly by member functions | 
| private members are hidden in derived class and can be accessed by member functions though public or protected member functions | private members are hidden in derived class and can be accessed by member functions though public or protected member functions | private members are hidden in derived class and can be accessed by member functions though public or protected member functions | 

You can initialize members of the base class by calling the base class constructor 
from your derived class.  It is recommended that you make the call to the base class 
constructor as the first thing in your derived class to ensure that member variables 
in the base class are initialized before they are accessed or used in the derived 
class.  The way to call the base class constructor from your derived class is 
demonstrated here.

```c++
Student::Student():Person("Tom", "Thumb")
{
}
```

Note that immediately following the constructor for Student we see a colon and then 
a call to the Person constructor that accepts two arguments.  You can place any valid 
constructor here including one that takes no arguments, in which case the default 
constructor will be called.  Make it a good programming practice to call the base 
class constructor in this manner to ensure your base class is initialized before 
entering the body of your derived class.  Other languages, such as Objective-C, 
require that the base class is initialized before your derived classes.


---

#### Module Three More OOP in C++   Inheritance   Demo: Inherit from a Base Class

# Inherit from a Base Class Demo

https://youtu.be/gGjpkF-Lmak

>> Hi, in this demonstration I'm going to show how to implement inheritance using
two simple classes. We'll have a base class called Person and we'll have a
derived class called Student, which inherits everything and adds additional
features. So let me show you the base class first of all. We'll have a look at the header
file Person.h. So this is quite a simple class, as you can see. The Person
class has one private field and a protected field. I've decided to make
age protected in case the derived class wanted to access it. Then we have two
constructors for the sake of the example. The first constructor has no arguments
and initializes the Person with simple values and then we have a proper
constructor which initializes the Person properly. Ah, plus, for the sake of interest I
have a displayNameAge() method there, which will display the person's name and
age. So that's the simple definition for the Person class. The implementation is
quite simple as well. So in the Person class we have constructor, which
initializes the name and age with made-up values if you like and a little
message here that will display on the console to indicate that this constructor
has been called. That would be useful to help you understand the order in which
constructors get called when you have inheritance. What you'll find is always
the base class constructor gets called first, followed by the derived constructor. So the
object gets built from the brown, the object gets built up from the ground up
if you like.
So then we have a proper Person constructor which initializes the Person
with a given name and age plus another message to say which constructor has
been executed and here's a simple message to display on the console. So
that's the base class now let's have a look at the Student class which inherits
from it. So first of all, notice, when you inherit you have to specify, you have to
include the whole of the header file to the base class. Obviously the compiler
needs to know everything about the base class so that it understands what
inheritance means. For Student here we note, specify that Student inherits
publicly from Person.
Don't forget the public keyword. That's important. If you leave that out the
default is private and public inheritance is what you want. It means that
members in the base class, which are public, remain public when you inherit
them. So they are still accessible in the derived class.
So don't forget that. And then the Student has some additional data as well
as inheriting the name and age from Person.
it also has a course, couple of constructors, a default constructor there,
plus a constructor to initialize everything a Student has, including
inherited data such as name and age plus the additional piece of data which is the
course. And here we have another method which displays that course. So that's the
definition for the Student class. Now let's see how it is implemented. So a
couple of interesting points here. In the constructor, the default constructor here,
notice that we don't mention the base class. If you don't mention the base
class constructor, the compiler will automatically invoke the no argument
constructor anyway. It'll always invoke the base constructor whether you want it
or not. You can't avoid it. So if you don't mention the base class there, it will
invoke the default constructor in the base class, and if your base class
doesn't have a default constructor then you have a compiler error. So this will
invoke the default constructor from Person to initialize the name and age with
artificial values. Then after that's finished, it'll fire up this code to set the
course and then it will output a message to say that that's this constructor
being executed. Now our second constructor is a bit more interesting,
a bit more explicit. In this constructor we do call the Person constructor explicitly.
So that would call the base constructor to initialize the name and age with the
values passed into us. After that's finished, then we'll set our course
property to the value that's being passed in, and we'll also display
a message on the console.
Ok, so that's our inheritance hierarchy. I have a very simple main application here, in
main.cpp, to illustrate both the no arg constructor and the parameterized
constructor. So first of all I create a Student using the no arg constructor.
That will implicitly invoke the Person constructor with no arguments and
then I display the person's name and age and of course remember that the student
inherits that method from the
base class. It's still accessible to us in our client code. Then I create a
Student object using in the parameterized constructors. This will vote the second
Student constructor, which invokes the parameterized Person constructor to set
everything properly and then we display that students details on the console as
well. So I'll run the application and let's just have a look here.
So for the first Student object that got created, we have the Person constructor
with no arguments called first. Always the base constructor gets called first.
Then the derived constructor, and these are the display methods, displayNameAndAge()
and displayCourse(). These are the methods that we've got here. And then
these statements here come from the Person constructor that took arguments and the
Student constructor that took arguments. So in our code we called the Student
constructor, but underneath the surface it will first of all call the base
constructor, then it'll invoke our constructors. The object gets built
ground upwards. And as you can see when we display the details, they have been set
properly.


---

#### Module Three More OOP in C++   Encapsulation and Protected Access   The Protected Keyword

# The Protected Keyword

When dealing with inheritance in your C++ code, you may find situations where you would 
like to keep certain members of the base class private to the "outside world" but public 
to derived classes of that base class.  C++ provides the keyword protected, for this purpose.

As an example, let's consider our Person class and some derived class, such as Student.  
In our existing code samples thus far, we have noted that Student cannot access firstName, 
lastName, or age directly.  This is because the member variables are declared private in 
Person.  We could use the public accessor methods of the Person class to gain access to 
these private member variables or, we could make those member variables protected instead.  
By doing so, we can then initialize them directly in our Student class without needing to 
call the call the accessor methods.   Perhaps we want to do this because we want to, as 
an example, validate age differently for a Student versus a Teacher.  We can create custom 
validation code in the Student or Teacher derived classes and then set the member variable 
directly for age by making age have protected access.

Perhaps some pure OOP folks might state at this point that we should make the SetAge() 
accessor a virtual function and force derived classes to override this function, but 
we'll cover virtual functions in the next topic.  For this example, we'll use this 
scenario to demonstrate protected access.   The code changes for Person and Student 
are listed below.

**Person.h**

```c++
#pragma once
#include <string>
class Person
{

private:
	std::string firstName;
	std::string lastName;

protected:
	int age;

public:

	Person();
	Person(std::string fName, std::string lName);
	Person(std::string fName, std::string lName, int age);
	~Person();

	void SetFirstName(std::string fName);
	std::string GetFirstName();
		
	void SetLastName(std::string lName);
	std::string GetLastName();

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
	std::cout << "Destructor called as a result of the delete keyword being used" << std::endl;
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


void Person::SayHello()
{
	std::cout << "Hello" << std::endl;
}
```

**Student.h**

```c++
#pragma once
#include "Person.h"
class Student :
	public Person
{
public:
	Student();
	~Student();

	void setAge(int);
	int getAge();
	void SayHello();
};
```

**Student.cpp**

```c++
#include "stdafx.h"
#include "Student.h"
#include <iostream>

Student::Student()
{
}

Student::~Student()
{
}

void Student::setAge(int age)
{
	if (age < 5)
	{
		std::cout << "Student age needs to at least 5 years old." << std::endl;
	}
	else
	{
		this->age = age;
	}
}

int Student::getAge()
{
	return this->age;
}

void Student::SayHello()
{
	std::cout << "Hey, how's it goin'?" << std::endl;
}
```

Looking at the Person header file, we note that the member variable age is 
now listed in the section under protected.  You will also notice that the 
setAge() and getAge() are no longer present in the Person class file.  
Again, we could have left them in Person and forced or allowed overridden 
functions in the derived classes but in this instance, we are just 
demonstrating the use of protected access.

In the Student class, we note that in the setAge() and getAge() functions, we 
can now access the age member variable directly.   To test this on your own 
computer, copy and paste this code into a C++ project and verify that there 
are no compilation errors.  Then, go back into Person.h and change the age 
member variable to private and see what errors are generated in the Student 
functions dealing with age.


---

#### Module Three More OOP in C++   Encapsulation and Protected Access   Friend Functions

# Friend Functions

A class can define an external function as a friend function. This allows 
the friend function to access all the members of the class, including 
private members. Friend functions are non-members, which means they 
don't receive a "this" pointer. Consequently, they must require an 
explicit parameter to access an object. 

The following example shows how a class can declare an external 
function named SomeExternalFunction() as a friend function of the 
class. SomeExternalFunction() receives a reference parameter that 
identifies the object the function will deal with: 

**MyClass.h**

```c++
class MyClass
{
	friend void SomeExternalFunction(MyClass & targetObject);

	// Data members and member functions, as required.
	...
};
```

The following code snippet shows how you might implement 
SomeExternalFunction(). Typically, you put friend function 
implementations in the same source file as member function 
implementations, because they are all part of the semantic 
meaning of the same class. However you don't prefix friend 
functions with the ClassName:: syntax, because they are not 
members of the class:

**MyClass.cpp**

```c++
#include "MyClass.h"

void SomeExternalFunction(MyClass & targetObject)
{
	// Access any members on the target object, i.e. public, private, or protected members.
	...
}
```

---

#### Module Three More OOP in C++   Encapsulation and Protected Access   Friend Classes

# Friend Classes

A class can define another class as its friend. A friend class can access all the members of 
the first class. This is useful if you have a "binary system", that is two classes that are 
intimately related to each other. 

A good example of friend classes is the "handle-body" idiom in C++. This idiom splits one 
semantic class into two related class - a "body" class that defines the private data, and a 
"handle" class that defines the public behavior. The body defines the handle class as a friend 
class, so that the handle class can access all the members (including private members) in the 
body class. 

The following code listings show how to implement the handle-body idiom in C++ using friend 
classes.

**Body.h**

```c++
class Handle;  // Forward reference of the "handle" class, so the compiler knows about it.

class Body
{
    friend class Handle;

private:
    int someData;
    ...
};
```

**Handle.h**

```c++
#include "Body.h"

class Handle
{
private:
    Body * body;   // The "handle" class typically maintains an internal instance of the "body" class.

public:
    Handle();
    ~Handle();

    void someOperationOnBody();
    ...
};
```

**Handle.cpp**

```c++
#include "Handle.h"

Handle::Handle()
{
    body = new Body;  // Create the underlying "body" object.
}

Handle::~Handle()
{
    delete body;      // Delete the underlying "body" object.
}

void Handle::someOperationOnBody()
{
    someData = 42;    // Perform operations on the underlying "body" object.
}
```

Client code just works with the "handle" class - the client code has no knowledge of the 
underlying "body" class. Consider the following example:

**Main.cpp**

```c++
#include "Handle.h"

int main()
{
    Handle h;
    h.someOperationOnBody();

    return 0;
}
```

---

#### Module Three More OOP in C++   Encapsulation and Protected Access   Demo: Friends

# Demo: Friends

https://youtu.be/G-ZKrtkHeI8

>> In this demonstration we're going to take a look at friend classes in C++. A
friend class is allowed to access all the members of another class even the
private members. You don't use friend classes that much in C++, but it is
useful in situations where you have two classes which are very closely related. In the example
we're going to use is the handle and body idiom where the Body class declares the
Handle class as a friend.
So first of all I'll show you what the classes look like and then we'll discuss
the why behind the example. So i have two classes. We have the Body class first of
all. This class represents some internal detail that you would like the shield
away from the client programmer. You don't want the client programmer to know much at
all about the Body class, and the reason for that is that you want to be able to
be able to change its implementation without necessarily
affecting the client's code. So what we do in the Body class, this is a very simple
implementation of the Handle/Body pattern. But in our Body class we
declare another class, Handle, as a friend.
it's the Handle class which the client code will deal with. They won't know anything
about the Body class. If you like the Handle class is the bit above the water and the
Body class is the bit below the water, that the client code won't see. When you
declare a friend class, at this point the compiler doesn't really need to know
much about the Handle class, but it does need to know that it is a class and
that's what this statement here does. This is called a forward reference. It
introduces the name of the Handle class to the compiler so it knows that the
word Handle, means class, is a class name. And that's enough for you to declare a
friend class.
Ok the compiler will say, okay this Body class, it has some other class called
Handle, which is a friend. I can live with that, and then the rest of the Body class
is whatever you want it to be. So that would be private data, functions, you know
whatever. So that's the Body class
definition, and if I show you the Body implementation. So we'd have methods in
there. That would just be a regular Body class. Now let me show you the Handle
class. Handle is effectively a wrapper over body. So this is a typical implementation.
The Handle class has a pointer to a Body. So at runtime, when a handle object is
created, it will create a Body object behind the scenes. So the Handle points
to the Body and the Handle class will define methods that encapsulate all
operations on Body. So here, the Handle class has some public method. This will
be visible in the client code. When the client code calls this
method, that method will do some work in the background on the underlying Body. Of
course the client code doesn't see the Body class at all. All the client class sees,
is the Handle, the constructor and destructor and this method underneath
the surface the Handle is actually just a wrapper for some underlying Body
implementation. So this is an example of delegation in C++. The Body class does
some stuff in the background and the Handle class is the delegated
wrapper. It's the Handle class that the clients see. They don't even know
about the Body class's existence, and that's good because it means that you
can change how the Body class is implemented later and the rest of the
world will be oblivious, because they didn't even know it existed in the first
place. And this decoupling is very important when you have large systems.
The ability to change how you might have implemented Body class internally
without changing the rest of the code at all. You don't break anything when you
re-implement how that Body class is implemented. Let me show you the Handle
implementation. So when the client creates a new Handle, the Handle internally creates
a new Body. So the Handle object contains a Body and it owns it.
Which means that when the Handle object is destroyed, it will also destroy its
associated Body. So what we can say, from an object only
point of view
is that the Handle object has custody over the Body. The Handle creates the
Body initially and Handle destroys the Body at the end. It completely owns the
lifetime of the Body and here's the implementation of the wrapper method. This
is the method that the client code will call, some operation, underneath the
surface, the Handle just does some other work on the Body. But of course that's
away from the client's view. All the client sees is the name of this method. So in
the client code, in main() we create a Handle object and we invoke a method on
the Handle object. No mention of Body at all. I can change the Body class in any
way I want. The client code isn't gonna be affected in any way whatsoever. So
that's an example of friend classes. The fact that the Body class had private
state, which it wanted the other class to be able to manipulate. So
the Handle implementation accesses some data which is actually private notice,
and it can do that because Handle is a friend of Body. So the Handle class is
allowed to access private data in Body because Handle is a friend.


---

#### Module Three More OOP in C++   Virtual Functions and Abstract Classes   Introducing Virtual Functions