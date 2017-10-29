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