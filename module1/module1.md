#### Module 1 Introducing C++   What Exactly is C++?   The C++ Language

# The C++ Language

If you visit http://www.stroustrup.com/C++.html, you will come across a plethora of information about the C++ programming language, direct from the designer of the language, Bjarne Stroustrup. Bjarne lists a definition of C++ as:

"... a general purpose programming language with a bias towards systems programming that

* is a better C
* supports data abstraction
* supports object oriented programming
* supports generic programming"

The language started in 1979 and was originally known as C with Classes. Essentially it meant that class files (used in object-oriented programming), were added to the C language. In 1983 it was renamed to C++.

C++ exists under the stewardship of a standards committee and became an ISO standard in 1998 with a revision in 2011 and a minor revision in 2014. It continues to be updated as a part of the standards committee work.

---

#### Module 1 Introducing C++   What Exactly is C++?   C++ a History

https://youtu.be/m4MNxxU8oL8

So if I've been using C++ since before Microsoft had a C++
compiler, and that's over 21 years,
then how long has C++ been a thing? So 1979 is apparently when
Bjarne started to work on it and to tell people about it.
And it got the name in 1983, which is 30 years now.
That's Bjarne Stroustrup...
Yes....
who is the creator of the language.
One person who said this would be a good idea, and set out
to make it happen. And is still very active in C++ and its future
and its growth as the time goes by.
So it's been around as C++ for 30 years. And it's an ISO standard.
This is kind of a weird thing for some people. It doesn't belong
to any company or person or organization other than the organization
that is standard C++.
And this ISO standard has a committee that meets, hundreds now
of people, yes?
Yeah, they had... they've had about a hundred people at the
last few meetings. So it's a big group from dozens of companies
and organizations. So it's not all commercial. Some of the...
there's people from the open source community, people from universities,
lots of research has been going into new language features for C++.
Yeah. And they are working on the language, and there's also
a library that comes with the language that the capabilities
of the library are set by the standards committee. And you have
to go through the standards process to get something changed
in the library, but then each individual vendor is responsible
for shipping and implementation of the library with their tools.
I think you can't really mix and match, yeah?
No. Generally you have to use a particular library with tools.
So, for example, our standard library only works on Windows with
our compiler. And it's largely... I mean, we use... it's tightly
coupled to the compiler. Like there's certain things in that
standard library that can only be implemented with help from
the compiler.
You have to know something about what's happening under the
covers in order to write the library.
Exactly. Yes. So there is some tight coupling there. But you
generally don't need to worry about it. When you get a compiler
package for Windows, you may be using ours, you may be using
another one, it will have everything you need, or it should have
everything you need.
That's the whole point of a standard.
Exactly. The one other thing to mention about the history is
because C++ is so old and because it didn't really start in 1979,
it started much earlier when C was invented, since it has mostly
retained backward compatibility with C, the important thing is
that it's really old and over the last 40 years we've learned
a lot about software development. So the way that we write clean
code today and how we know how to write the best code using the
best practices is very different from what we did 40 years ago.
And so a lot of code that you see out there in the wild is going
to be rather ugly or it may use a lot of non modern things.
It's really only been the last 15 years or so that we've really
started to understand how best to use the facilities that C++
has to write really great code.
Maybe a bit earlier in the '90s, but generally about 15 years
has been how long this modern C++ that we're going to be showing
you has developed.
Yes. So if you have a book that, I don't know, one of your
parents used in college to learn C++ from, please do not look
at that book. Like don't even open it. Because it's going to
be full of old-school, we don't do it like that anymore, that's
harder than it needs to be ways of coming at C++. And what James
and I want to show you today is that C++ is not a scary language.
It's a very powerful and expressive language with elegance and expressivity.
That's a word that I find myself using a lot lately about choosing
a way to write your code that makes it obvious to whoever reads
it what it does.
Yep.
And the scary tricks that people used to pull off with, no more.
Absolutely. And because of its age, there's often multiple
ways to do things. So, for example, we may see later today there's
many ways to initialize variables, at least three or four.
And this is largely because of age. Like there is one way to
do it in C, and then we learned, oh, hey, that doesn't work for
everything, so let's introduce a new way. So then we had two
ways, and they didn't really work very well, there were two of them.
So we came up with a third way, and it mostly works. And so
it's the third way that we'll be showing you, because you should
be using it pretty much everywhere in your code.
Right. So you may find C++ code elsewhere that doesn't look
exactly like what we're showing you. That doesn't make that
code wrong or our code wrong, it just makes them different because
we have a lot of different ways to do the same thing. But we
do kind of feel pretty strongly that our way is right for that
readability and expressivity.
Yep.

---

#### Module 1 Introducing C++   What Exactly is C++?   C++ Program Structure

A C++ program has a very specific structure in terms of how the code is written and some key elements that you use in your C++ programs. The simplest of C++ programs is shown here.


```c++
1. #include <iostream>
2. 
3. int main()
4. {
5.   std::cout << "Hello World!";
6.   return 0;
7. }
```


In this simple program we notice some elements listed. The line numbers are used for reference only and are not part of the program code.

* **Line 1**: this is known as a pre-processor directive. it instructs the compiler to locate the file that contains code for a library known as iostream. This library contains code that allows for input and output to streams, such as the console window.

* **Line 3**: Every C++ program must have a method known as main(). It is referred to as the entry point for the application when you start execution of the program on your computer. The int portion is the return type of the method. The empty parentheses () after the method name indicate that this a method and that it takes no arguments, in other words, there are no parameters for passing in values.

* **Line 4**: Method bodies in C++ start with an open curly brace. **Line 5**: This code uses a method known as cout (pronounced "see out") to send the text Hello World! to the console for output and display. The std:: prefix to this command is a way of indicating that cout is part of a namespace known as std. The :: is is used to indicate that cout is part of the std namespace.

Also notice that the line ends with a semi-colon. C++ statements are terminated with semi-colons.

* **Line 6**: The return statement is used to end a function or method when a value is expected to be sent back to a caller. In this case, the caller is the operating system and the value returned is an integer value of 0. If the program reaches this statement, returning a value of 0 is an indication to the operating system that the code executed successfully. In the past, programmers would return 0 to indicate successful execution and non-zero values to indicate that an error had occurred in the program somewhere.

* **Line 7**: This line closes out the body of the function main() and is necessary so the compiler knows where the function or method ends, but is also used for other purposes that will be covered later in the course on variable scope and visibility.

---

#### Module 1 Introducing C++   Portability, Compiling, and Linking   C++ Apps on Different Platforms

### C++ Apps on Different Platforms

Writing code in multiple languages as a way to have your applications execute on multiple platforms or different operating systems can take a considerable amount of time resulting in duplication of effort. Application portability may not be a requirement for all software applications but what if portability is required? So, what exactly is portability or the ability to execute on multiple platforms?

Primarily, portability refers to the process of compiling your code, without major changes, across different compilers or different platforms. Platforms typically mean computer hardware, operating systems, CPU architectures, or device form factors. Compilers refer to the process of turning your code into executable form. Each platform or operating system may have different compilers available from different providers such as Microsoft, Intel, or Oracle.

---

#### Module 1 Introducing C++   Portability, Compiling, and Linking   Compilation Process

# Module 1 Introducing C++   Portability, Compiling, and Linking   Compilation Process

https://youtu.be/0BOLiqC_w6A

The first thing that happens is we say that the code is built.
And that in itself is a multistep process.
First a tool called the preprocessor goes through your code and
manipulates it a little bit. The output of the preprocessor goes
to something called the compiler.
As James mentioned, real programs have lots of files in them,
like not just five or ten, but thousands. And each one is compiled
individually and the output of that is called an object file.
After everybody's been compiled, then they're linked together
into your actual executable, the thing that you run under the
debugger or without the debugger.
Now, when you're writing these individual files, the compiler
makes sure that you've used the syntax of the library correctly.
For example, the single line of useful code in there had quite
a lot of syntax. It had bits and pieces of punctuation that you
will understand by the time we're done. And the compiler makes
sure that all that punctuation is being used properly.
It doesn't necessarily check every single thing about your program.
You are allowed to basically make a promise to the compiler.
I'd like to call this piece of code that I swear to you will
be somewhere else.
The linker makes sure that those promises are being kept.
And it puts all the somewhere elses together and connects everybody
to the places they were planning to use and, okay, this is good,
it all works.
Those three steps of building are actually critical to understanding
what happens when you get error messages. I've been teaching
people C++ a very long time, and most people don't read their
error messages at all. They don't even necessarily read the message
part that tells them what the mistake is, but they also don't
notice that in C++ you're told whether the error is a compiler
error or a linker error. And that's vital to being able to solve
the problem.


#### Module 1 Introducing C++   Portability, Compiling, and Linking   The Role of the Linker

Once the compiler has completed its tasks, the linker is then invoked. The linker is responsible for taking all the object files, that will be part of the application's executable code, and then links them all together in the application .exe file. At the same time, the linker ensures that all promises of the compiler are kept, during the linking process.

A an example, if your program makes use of the cout function, that is found in the iostream set of files, the linker will ensure that the necessary code for that function, is included in your .exe file.

---

#### Module 1 Introducing C++   Portability, Compiling, and Linking   C++ Editors and Tools

# C++ Editors and Tools
Marcar esta página
While the demonstrations in this course are using Microsoft's Visual Studio environment, you are free to choose the editor and compiler of your choice.  The samples used here follow the C++ 11 standard and therefore should work on your platform of choice and the editor and compilers you use on those platforms.

The course does not, and cannot, teach all the different editors, compilers, and their syntax.  Please follow this [link](https://isocpp.org/get-started) to identify editors and compilers that you can use to write, edit, and compile C++ code.

For more information , you can see: 
Visual Studio: https://aka.ms/edx-dev210x-vs

---

#### Module 1 Introducing C++   C++ Fundamentals   Code Formatting

Code Formatting
Marcar esta página
C++ is a case sensitive language. Case sensitivity means that your keywords and variable declarations must match the case. For example, a C++ keyword for a constant type is const. If you were to type Const or CONST, the compiler would not know that your intention was to use the keyword const.

Aside from the case sensitivity, C++ also has a defined outline for program code and specific "elements" found in a typical C++ application. These elements consist of:

* **Preprocessor directives** which are used to have the compiler execute tasks prior to compiling the source code
* **using directives** which are utilized to indicate which namespaces to include in a source code file
* a **function header** which consists of a return type, function name, and parameters
* a **function body** containing the code that performs the actions required of that function
* **statements** that are contained in the C++ source code file
* **comments** for documenting the source code for programmers to understand what the code is intended to do
* a `return` statement that sends data back to the function caller
* curly braces to enclose bodies of statements. Commonly used to denote the body of a function or a flow controls statement such as a for loop

C++ source code also permits judicious use of white space (tabs, spaces, new lines) to create code that is easier to read. The compiler completely ignores the white space, with a small exception concerning if statements that will be covered later. It is highly recommended that you make use of white space to indent and separate lines of code to aid in readability of your source code files.

NOTE: Unlike Python, indenting lines after the for statement does not tell the compiler to execute those indented lines as part of the for statement. In C++, multiple statements for a single for statement, must be enclosed in curly braces. This will be covered more in Module 3, Control Statements.

---


#### Module 1 Introducing C++   C++ Fundamentals   C++ Statements

# C++ Statements

A C++ program is comprised of various components such as functions, methods, classes, etc. The instructions that form part of a C++ program typically reside inside of functions or methods. These functions are comprised of C++ statements. You will find yourself using various types of statements in your C++ code as listed here:

* **declarations** - these are used to declare variables and constants that will be used in your application
* **assignments** - these are used to assign values to variables in your application code
* **preprocessor** directives - covered in the topic on Code Formatting
* **comments** - used to document your code
* **function declarations** - covered in the topic on Code Formatting
* **executable statements** - these are used to perform operations and execute instructions. Examples would be cout << "Hello World!"; which outputs Hello World! to the console.

You will use these statement types throughout this and successive courses on C++.

---

#### Module 2 Data Types in C++   Available Data Types   Numeric Data

# Numeric Data

C++ contains intrinsic data types to store numeric values in your application code. It's important to remember that these values are binary-based and not as flexible as their base 10 counterparts. For example, in mathematical terms of a base 10 integer, the definition is a value that is negative infinity to positive infinity whole numbers. Modern computers still cannot represent numbers these large. Take as an example the int type in the Numeric Data Types table. The range does not exceed 3 billion in either direction.

The byte representation given in that table will give you a hint as to how the values are stored in the memory and on disk.

NOTE: The type names that start with a __ character are considered non-standard types.

| Type Name             | Bytes | Alias                               | Range                           |
|-----------------------|----|----------------------------------------|---------------------------------| 
| int	                | 4	 | signed	                              | –2,147,483,648 to 2,147,483,647 | 
| unsigned int	        | 4	 | unsigned	                              | 0 to 4,294,967,295 | 
| __int8	            | 1	 | char	                                  | -128 to 127 | 
| unsigned __int8	    | 1	 | unsigned char	                      | 0 to 255 | 
| __int16	            | 2	 | short, short int, signed short int	  | –32,768 to 32,767 | 
| unsigned __int16	    | 2	 | unsigned short, unsigned short int	  | 0 to 65,535 | 
| __int32	            | 4	 | signed, signed int, int	              | –2,147,483,648 to 2,147,483,647 | 
| unsigned __int32	    | 4	 | unsigned, unsigned int	              | 0 to 4,294,967,295 | 
| __int64	            | 8	 | long long, signed long long	          | –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 | 
| unsigned __int64	    | 8	 | unsigned long long	                  | 0 to 18,446,744,073,709,551,615 | 
| short	                | 2	 | short int, signed short int	          | -32,768 to 32,767 | 
| unsigned short	    | 2	 | unsigned short int	                  | 0 to 65,535 | 
| long	                | 4	 | long int, signed long int	          | –2,147,483,648 to 2,147,483,647 | 
| unsigned long	        | 4	 | unsigned long int	                  | 0 to 4,294,967,295 | 
| long long	            | 8	 | none	                                  | –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 | 
| unsigned long long	| 8	 | none	                                  | 0 to 18,446,744,073,709,551,615 | 
| float	                | 4	 | none	                                  | 3.4E +/- 38 (7 digits) | 
| double	            | 8	 | none	                                  | 1.7E +/- 308 (15 digits) | 
| long double	        | 8	 | none	                                  | 1.7E +/- 308 (15 digits) | 


---

#### Module 2 Data Types in C++   Available Data Types   Character Data

# Character Data

Character data is used to represent non-numeric data such as letters and symbols.  Character data is actually represented as numeric information under the covers.  The standard char type is used to represent the numeric values for character data as represented by the basic character set present on a particular computer.  This is determined by the locale settings.

For internationalization purposes, the wchar_t type is used which expands on the numeric values available to represent character sets from various languages found around the world. 

NOTE: The type names that start with a __ character are considered non-standard types.


| Type Name                         | Bytes   | Alias      | Range                           |
|-----------------------------------|---------|------------|---------------------------------| 
| char	                            | 1	      | none	   | –128 to 127 by default 0 to 255 when compiled by using /J | 
| signed char	                    | 1	      | none	   | -128 to 127 | 
| unsigned char	                    | 1	      | none	   | 0 to 255 | 
| wchar_t, char16_t, and char32_t	| 2 or 4  | __wchar_t  | 0 to 65,535 (wchar_t & char16_t), 0 to 4,294,967,295 (char32_t) | 

---

#### Module 2 Data Types in C++   Available Data Types   Other Data Types

# Other Data Types

C++ supports other data types outside of the numeric or character data types.  The first one we see in the table below, is the Boolean data type called bool.  This is used to represent true or false values in an application.  In previous languages such as C, false was represented as a 0 value and true was represented as any non-zero value.

| Type Name | Bytes   | Alias    | Range                           |
|-----------|---------|----------|---------------------------------| 
| bool	    | 1	      | none	 | true or false | 
| enum	    | varies  | none	 | dependant on the enclosed data types | 

C++ also has the concept of an enumeration, called an enum.  An enumeration is a set of constants stored as literal values.  They limit the choices for the type.  For example, when dealing with an int data type, you can assign any value to that data type that fits within the range of the integer type for that computer.  With an enum, you specify a limited set of literal constants that can be assigned to the type. 

Consider the need to use a data type to represent days of the week.  How do you store this information in a data type?  You could use an array, but what type of data would you use?  Perhaps a string data type.  But how do you prevent someone from adding a non-valid day of the week, like moncleday, to the array?  If you create an enumeration that stores only valid values for Sunday through Saturday, you constrain the data type to those literal constants only.

Enumerations are covered later in this module under the lesson on Complex Data Types.

---

#### Module 2 Data Types in C++   Available Data Types   Choosing Data Types

Choosing the correct data type is important in your applications to ensure that you can represent your data 
efficiently and correctly. Some examples of this would be;

* making use of **short** rather than **int** if your data range permits
* using a **double** rather than a **float** to get greater a accuracy for values representing money
* using a **wchar_t** for character data that doesn't fit in the standard ASCII character set, such as Japanese kanji

---

#### Module 2 Data Types in C++   Variables and Constants   Introducing Variables

# Introducing Variables

Variables are identifiers that you create to hold values or references to objects in your code. A variable is 
essentially a named memory location.

When you create a variable in C++, you must give it a data type. You can assign a value to the variable at the 
time you create it or later in your program code. This is known as initializing the variable. Even though you 
can initialize a variable separate from its creation, you must assign the data type when you define the variable. 
C++ will not allow you to use an uninitialized variable to help prevent unwanted data from being used in your 
application. The following code sample demonstrates declaring a variable and assigning a value to it.  C++ supports 
two methods of initializing a variable.

```c++
int myVar = 0;
int yourVar{1};
```

C++ has some restrictions around identifiers that you need to be aware of.

First off, identifiers are case-sensitive because C++ is a case-sensitive language. That means that identifiers 
such as myVar, _myVar, and myvar, are considered different identifiers.

Identifiers can only contain letters (in any case), digits, and the underscore character. You can only start an 
identifier with a letter or an underscore character. You cannot start the identifier with a digit. myVar and 
_myVar are legal but 2Vars is not.

C++ has a set of reserved keywords that the language uses. You cannot use these keywords as an identifier in 
your code. You may choose to take advantage of the case-sensitivity of C++ and use Long as an identifier to 
distinguish it from the reserved keyword long, but that is not a recommended approach.

To keep up to date on the reserved keywords for C++ you should always refer to the C++ standard but the current 
standard lists reserved keywords in the C++ Standard document found here.

https://youtu.be/owk_3MXMgxc

---

#### Module 2 Data Types in C++   Variables and Constants   Introducing Constants

# Introducing Constants

Similar to a variable, a constant expression is a named memory location for a value used in your application.  
The difference is that, as you might expect, a constant expression cannot have its value change in the program 
during run time.  C++ uses the keyword const to indicate that an expression is a constant.

When you declare a constant in C++, you must assign a literal value to that constant at the same time.  You 
cannot assign it later in program nor can you change the value in code later.  Also, because the value cannot 
be changed, you cannot initialize a constant with a variable or any other value that will have its value 
modified during runtime.

https://youtu.be/6vpY6kAXSWU

So far, we've been pretty
bossy to the compiler. We've said, this is an integer. This is
a double. Here's a function that I want you to call. And the
compiler has sort of followed along and it's been a little bit
like an assistant who knows what's going on and says, are you sure?
Did you want to do that? Gives you a warning if you try to put,
you know, a number into an integer, that kind of thing.
Sometimes gives you an error if you try to call a function that
it's never heard of.
But you can kind of engage the compiler as your helper, your
external memory, by putting more information into your program
and then getting it to enforce it. And one of the most important
things you can say that is a particular variable doesn't actually
vary, despite the name.
There are languages in which nothing varies, even when it's called
a variable. And then there are languages where it's assumed that
everything can. In C++, and this is sort of a late motif for
us, we get to choose if we want immutability, we can have it.
If we don't, we don't have to.
So when you mark something with this keyword const, you are saying
this will not change. None of the code you're about to compile
is going to change the value of this variable. And then the
compiler will actually enforce that. And if you have a line
of code later that tries to change the value of something you've
marked const, you'll get a compiler error, basically telling
you, you can't. It's const. Why would you want to do that?
I think everyone's written the kind of code where we change the
wrong half of something. You know, we're trying to do how many
transactions have we had today and is it the limit and we mean
to raise the number of transactions and just in a moment of stupidity,
we raise the limit.
And then we're running the code on the debugger and we can't
understand it. We're never getting to the limit. The limit keeps
getting bigger. What's going on. If we had told the compiler
that the limit was const, then when we wrote that stupid line,
the compiler would have said, are you sure? Is that your final answer?
And we could have caught that mistake. And that happens all
the time to me when I used const from the very beginning.
If I declare something, like a limit, that I know isn't going
to change and I immediately say that it's not going to change,
then I catch myself when I make a mistake. And I think there's
also some speed-ups possible from that, right?
Potentially. There's a few places. But you shouldn't worry
about performance when it comes to const.
No, we don't want to premature optimize.
It's not all that important. But absolutely, you should use
const everywhere you can. If you can use const somewhere, do it.
This also actually encourages several very good programming styles.
So, for example, in many programs, especially in legacy programs,
people will reuse local variables. So they might declare one
I integer at the top of a file and then have ten loops that use
that same I.
Loops, I guess, are a bad example because you have to change those.
But you always want to use each variable in as constrained a
location as possible.
So generally, yes, you should try to make everything const, but
then things like loop variables, you should, you know, because
they can't, they...
They have to change. We're going to go around and increment
I every time through the loop.
But const by default is a good rule.
Const first, and the reason is if you ever come up to a program
where the developer despite appear to have heard of const and
you try to label something const for the first time, well, the
compiler will step up and help you and you won't really enjoy
that experience very much. And I think the demo we have is actually
going to show that by having to add const as we go through.
Yes.
All right. Let's give them a whirl through that.

---

#### Module 2 Data Types in C++   Variables and Constants   Constants Demo

# CONST Demo

https://youtu.be/HxmX6iZ14jk

Actually, so what we have here is we have just a little main function.
We still have the same addtwo.
And we have, you know, this is just like we had before, I as
a regular int. But then J and K are const integers, and you can
see that we can add the const either on the left or on the right.
There are warring factions that argue that it belongs on one
side or the other. But the important...
The compiler is neutral. The compiler doesn't care.
Yeah, the compiler doesn't care. You can put it in either place.
And so we initialize each of these with this addtwo expression.
So all of that is fine.
So then this addtwo is also fine. Because we're making a copy
of the J as we said, because it's passed by value. We're going
to copy the J and we're not going to actually modify the original J.
But as soon as we try to assign to J or change its value in any
way, so even if we were to say J++, that would not work.
Similarly, for K, if we were to try to just, you know, assign
a new value, 7, that's not going to work. And if we build,
we'll see that the compiler is going to report error messages
and this time, it's actually a very easy to understand message.
It says, you cannot assign to a variable that is const. So this
is an extremely useful feature for
all code, use it everywhere.
Use it everywhere. When you declare a variable and you think
that you know it's going to change, because this is the value
I'm calculating, the total, the sales tax, whatever, then obviously
don't mark that const. But most of our programs are full of numbers
that are not going to change. And not just numbers either.
Variables of all types. And if you have the habit on every line
when you declare something of asking yourself whether it's going
to change or not, you will end up with more correct programs
that are easier to maintain in the future.

---

#### Module 2 Data Types in C++   Variables and Constants   Type Conversions

# Type Conversions

Casting refers to converting one data type to another. Some data conversions are not possible while some are 
possible but result in data loss. C++ can perform many conversions automatically, what is known as implicit 
casting or implicit conversion. For example, attempting to convert a smaller data type to larger data type 
as shown here:

```c++
int myInt = 12; 
long myLong;
myLong = myInt;
```

In the first line, we declare an integer data type and assign it a value of 12. The next line declares a long 
data type and in the third line, we assign the integer data type value to the long data type. C++ automatically 
converts the data type for you. This is known as a widening conversion. Some programmers also call this an 
expanding assignment. We are expanding or widening the data type to a larger one. In this case, there is no 
loss in data. The following table highlights some potential data conversion problems.

| Conversion	 | Potential Issues | 
| -------------- | ---------------- |  
| Large floating point type to small floating point type	 | Loss of precision and/or the starting value might be out of range for the new type | 
| Floating point type to integer type	 | Loss of the fractional component of the floating point type and/or out of range | 
| Bigger integer type to smaller integer type	 | Starting value may be out of range for the new type | 

This table only deals with numeric data type conversions. There are other conversion types such as from character 
to numeric or numeric to character, or among character types. C++ also uses the boolean type that represents 
true or false. If you assign a zero value to a bool variable, it will be converted to false. Any non-zero 
value is converted to true.

When you want to explicitly perform a conversion or cast, you can use the type cast features of C++. For 
example, the previous widening conversion in the int to long cast was implicit but you can also tell the 
compiler that you are know what you are doing by using the type cast statement as in:

```c++
long myLong = (long)myInt;

// or you can use this version as well

long myLong = long(myInt);
```

C++ also provides a cast operator that is more restrictive in its usage. This in the form `static_cast (type)`. 
This static cast operator can be used for converting numeric values or to numeric values. As an example:

```c++
char ch;
int i = 65;
float f = 2.5;
double dbl;
ch = static_cast<char>(i);   // int to char
dbl = static_cast<double>(f);   // float to double
```
https://youtu.be/E7K6czWbnkc

Yes. So I have here... it's basically a similar program to
the one we had before. We still have an int I and a double D
and a bool flag.
But here we've replaced all of those weird-looking conversions
with uses of these casts. So if we build it,
we will see that there are no errors and no warnings, so that's
a good sign. And we can see that if we run the program
basically as we step through, we'll see that it has the same
behavior as before. So when we assigned the 3.2 to I, it was
converted to int. So this was what the compiler was doing under
the hood. We've added this cast to say compiler, I know what
I'm doing. This is exactly what I meant to do.
One thing that I guess we can also show here, so when we're printing
things to the console, they don't have to be strings. Like before
we had the string "Hello, World!" Now we can print an integer,
and basically the library will go and format it as a string for you.
So here we can see we're printing I. And if we go to the output
window, we can see that... or to console window, we can see that
we've printed negative 1.
Stepping through, we can just see basically the same thing with
all the rest of these. Yeah.
Yeah. So the casting takes away the warnings from the compiler.
This particular demo is super artificial. I mean, why would
you take that constant number like 3.2 and then stick it into
an integer so as to throw the .2 away. You know, we're just
showing you this code so that you will understand what happens
in some of your code. One of my favorite newbie errors is when
somebody writes double ratio equals 1 divided by 3.
Do you want to show them what the compiler will give them when
they do that?
Yeah, that's actually... that's actually a good example.
So as we noted, integer types can only deal with integers.
So 2 is an integer, but so are, for example, 1 or 3 and 2.
So we build this, and you might think, oh, well, this is one half.
But we can't represent one half in an integer. So when we run
this, we'll see that, well, the result has been truncated and
we just get the 1. We've lost that .5.
So often what people will say is, oh, well, I can turn this into
a double.
Right.
So now I is a floating point value, so it can hold that .5,
so clearly the value is now going to be 1.5.
And it's not. It's 1.0.
The reason for this is that this expression, 3 divided by 2,
it doesn't matter where that appears. It's always going to have
the same value. And because both of those are integers, we end
up performing integer math on them. So we end up dividing 3
by 2 which yields 1 with a remainder of 1, so there's no...
there's no .5, like there's just this remainder of 1, and we
throw away that remainder. We say we're not going to use that.
And so you end up with this double precision number with lots
and lots of 0s on the end of your 1.
Something that happened fairly recently to C++ was adding the
capability to leverage the fact that the compiler knows when
you're making these assignments what the types are. So when
you take integer 3 divided by integer 2, the result is an integer.
If you were to change that to a 3.0 divided by 2, then the result
would be a double. And that's how to get around this problem,
but it also puts you in the position of if you then declared
the type of the variable yourself explicitly, sometimes the compiler
warns you and says that type doesn't go with this expression
that you're calling. And I think a lot of us have wanted this
for a long time, is to say to the compiler, if you're so smart,
why don't you do it. And that capability is actually in the language
in a keyword called auto.
Yes.
So unfortunately we cannot use this lovely initialization syntax.
And this is an oddity of the language. I'm very sorry.
So what we can do... there's another way to initialize things.
You can use the equal sign just like... you know, it looks like
assignment but it's still initialization. And we can change
this to just say auto, which means, compiler, go tell me what
this type... or go figure out what the type of this expression is.
So 3 divided by 2 is an int expression, so it's type int.
And so I here is an integer.
And if we run, we can see that I is indeed of type int, and it
has the value of 1. And in the IDE, when we're editing, you can
hover over that...
Over I....
I. You hover over the I. And you can see here that it says,
oh, it's an int, so the IDE can tell you what that type is even
though you've just said auto. So it can do that deduction.
Then if you change the expression, if you make that 3.0 divided
by 2...
Yes. Then if we hover over the I, you' see it's now a double.
Double I. So a lot of people come from other languages that
are not strongly typed and they think that this is the type adjusting
to match the expression, but it's not. It's the keyword auto
says to the compiler you figure out what to strongly type this
variable as and that will be its type for the rest of time.
Right. So in this particular example, there's no... there is...
to the compiler, there's no difference between this, this declaration
here, auto I equals 3.0 over 2. And if we were to put double
here, it's exactly the same. There's no difference between them
at all.
Well, auto is shorter than double but longer than int.
Yes. Well...
I tend to type whichever is the shortest.
Yeah. Yeah, there is still great debate about, you know, what
the right balance is between using type inference and not using
type inference.
Yes. But still.
Just know that it's a tool in your toolbox.
And you may see auto from time to time in our demos where the
things we are declaring have longer types than int or double
and we don't feel like typing all of it, but understand the compiler
does not care. It's the same as if we had typed out its name
with pressing keys. Boy, the word type is overloaded, isn't it?
Yeah.


---

#### Module 2 Data Types in C++   Complex Data Types   Arrays

# Arrays

# Complex Data Types (Arrays)

So far you have been introduced to the intrinsic data types that C++ supports. These are types that contain the 
data literals directly. The int type directly stores the literal integer value, for example.

C++ also provides support for complex data types. These are also referred to as compound data types. Mostly 
because they store more than one piece of data or potentially more than one data type.

An array is a set of objects that are grouped together and managed as a unit. You can think of an array as a 
sequence of elements, all of which are the same type. You can build simple arrays that have one dimension 
(a list), two dimensions (a table), three dimensions (a cube), and so on. Arrays in C++ have the following 
features:

* Every element in the array contains a value.
* Arrays are zero-indexed, that is, the first item in the array is element 0.
* The size of an array is the total number of elements that it can contain.
* Arrays can be single-dimensional, multidimensional, or jagged.
* The rank of an array is the number of dimensions in the array.

Arrays of a particular type can only hold elements of that type. This means that you cannot store integers, longs, and character data types in the same array.

### Creating and Using Arrays

When you declare an array, you specify the type of data that it contains and a name for the array. To declare a single-dimensional array, you specify the type of elements in the array and use brackets, [] to indicate that a variable is an array. The following code example shows how to create a single-dimensional array of integers with elements zero through nine.
```c++
int arrayName[10];
```
You can also choose to create an array and initialize it with values at the same time as in the following example 
that declares and integer array and assigns values to it. The compiler knows how large to make the array by the 
number of values in the curly braces:
```c++
int arrayName[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
```
You can also declare an array and only initialize some of the elements:
```c++
int arrayName[10] = {1, 2, 3};
```
In this case, we have declared an array of size 10 but have only assigned values to the first three elements. 
The compiler will initialize the remaining elements to the default value for the data type the array holds. 
In this case, int data type, the remaining values are initialized to 0.

### Accessing Data in an Array

You can access data in an array in several ways, such as by specifying the index of a specific element that you 
require or by iterating through the entire array and returning each element in sequence.

The following code example uses an index to access the element at index two.
```c++
//Accessing Data by Index 
int oldNumbers[] = { 1, 2, 3, 4, 5 }; 

//number will contain the value 3 
int number = oldNumbers[2];
```
Note: Arrays are zero-indexed, so the first element in any dimension in an array is at index zero. The last 
element in a dimension is at index N-1, where N is the size of the dimension. If you are using some other 
languages, such as C#, and you attempt to access an element outside this range, the C# runtime will throw 
an exception (error). C++ doesn't offer such protection. If you attempt to access an element that is outside 
the bounds of your array, you will still return data, but you have no idea what that data is.

The reason for this is because an array is simply a pointer to a memory location. The first element of the 
array is the starting memory address for the entire array. If you have an array of integer data types, then 
the number of the elements multiplied by the size of the int data type on your system, determines how much 
memory is used by the array, and at the same time, permits the access of the elements in the array by 
performing math on the memory address to get at the required element. If you attempt to access `oldNumbers[5]`, 
the program will simply return the data found at the memory address that is the next memory address location 
beyond the last array element. This can be a dangerous situation and is in fact, the result of some security 
issues found in software.

You can also iterate through an array by using a for loop. You will cover loops in module 3 so don't worry 
if you don't completely understand this example at this time. Essentially, the for loop starts at 0 and 
repeats the portion in the curly braces {} for each of the five steps in the loop.

The following code example shows how to use a for loop to iterate through an array.
```c++
//Iterating Over an Array 
int oldNumbers[] = { 1, 2, 3, 4, 5 };
for (int i = 0; i < 5; i++) 
{ 
     int number = oldNumbers[i]; 
     ... 
}
```


---

#### Module 2 Data Types in C++   Complex Data Types   Strings

# Strings

Strings are a series of characters. C++ represents strings in one of two ways. The first maintains backward 
compatibility with the C language and represents the string as a character array. There is one aspect to a 
**C-style string** that is important to note. The last character of every string you store is the null character 
string, typically represented by the ASCII code for 0 which is \0. This is necessary so that the compiler 
knows when the string ends. An example demonstrates a C-style string stored in a character array:
```c++
char isAString[6] = { 'H', 'e', 'l', 'l', 'o', '\0'}; 
char isNotAString[5] = { 'H', 'e', 'l', 'l', 'o'}; 
cout << isAString << endl; 
cout << isNotAString << endl;
```
The most common mistake made by users of the C-style string is to forget to make the char array large enough 
to accommodate the `\0` character, but also forgetting include the \0. In the previous example, a programmer 
might think that an array of size 5 would be large enough to contain Hello because that's how many characters 
are in the word. However, the null character would not be included in the second array, which could result in 
errors in code that uses this array. The reason is that C++ does not consider the isNotAString array to be a 
string.

Consider the output displayed in Figure 2.1. Note that the first output correctly terminates because C++ 
encountered the null (`\0`) character. The second did not terminate and output the contents of adjacent 
memory.

string output showing how the null character is required to ensure the end of the string is found

An alternative method of declaring a character array for use as a string is to simply initialize it with a 
string literal. A string literal is a sequence of characters enclosed in the double quotes (`"`). For example:
```c++
char isAString[6] = "Hello"; 
char isAnotherString[] = "Array size is inferred";
```
In the previous example, the first line creates an array of size 6 and assigns the string literal Hello to 
the array. The second example lets the compiler infer the size from the string literal itself. Note that 
neither of these two string literals specifies a `\0` character. The compiler will implicitly add that for you. 
However, caution is advised in the first line to ensure that you allow enough room in the array size specified 
for the null character. If you create an array that is larger than required for the string literal along with 
the null character, then C++ simply fills the remaining elements of the array with null characters.

### The string Class 

If the use of character arrays, single quoted characters, and null termination characters are making you think 
that strings aren't worth the hassle, consider the string class instead. The ISO/ANSI standard helped to expand 
the string handling capabilities of C++ by adding the string class.

In order to use the string class, you have to include the string header file. We have not covered namespaces yet but to make typing much easier, you would add a using statement as in the following example.
```c++
using namespace std; 
string myString = "Hello!"; 
std::string myNewString = "Less typing";
```
Without the using directive, you would have to type std::string every time you wanted to use the string class 
in your code, as in the second line above.

As you can see from the code example, you use string in the same manner in which you would use any other data 
type in C++. You also do not need to add a null character to terminate your string.


---


#### Module 2 Data Types in C++   Complex Data Types   Structures

# Structures

Arrays can store multiple pieces of data in one compound data type but recall, the data types must all be of 
the same type. If that is the case, how might you store multiple pieces of data in one type, where the 
individual pieces are of different data types? For example, let's say that we want to store information 
about a coffee bean. We might want to store information about the bean type, its strength, and perhaps 
which country it originated from. In this case, we could use all strings to store that information but 
what if the strength was intended to be a number from 1 to 10. In this case, we would want to store two 
strings and one integer in our coffee bean data type.

We haven't covered classes yet, which is another data type we could use, but instead, we will use a 
structure (**struct**) to store this information. Structures are known as user-defined types. You define 
the struct by giving it a name and then adding the member data types as in the following example:
```c++
struct coffeeBean 
{ 
     string name; 
     string country; 
     int strength; 
};
```
Recall that in order to use the string data type in our struct, the C++ file that contains the struct 
must include the string header file. This code snippet also assumes that using namespace std; has also 
been included.

Once we have defined the structure, we can then use it in our code the same as any other data type. To 
use the coffeeBean struct in your code, you simply declare a new variable of that type as shown in this 
example.
```c++
struct coffeeBean 
{ 
     string name; 
     string country; 
     int strength; 
}; 

coffeeBean myBean = { "Strata", "Columbia", 10 }; 
coffeeBean newBean; 
newBean.name = "Flora"; 
newBean.country = "Mexico"; 
newBean.strength = 9; 
cout << "Coffee bean " + newBean.name + " is from " + newBean.country << endl;
```
You can assign values to a struct using one of the methods seen here. For myBean, we assign values in 
the curly braces while for newBean, we use the dot notation. You can also access the values of the the 
struct members using the dot notation as well, shown in the cout statement at the end.

---

#### 