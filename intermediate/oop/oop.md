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