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
