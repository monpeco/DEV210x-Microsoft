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