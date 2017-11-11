#### Module 3 Control Statements   C++ Operators   C++ Operators

# C++ Operators

Because you will start to learn about control statements in C++, it's important to understand the C++ 
operators that exist in the language first, as they play an important role in control statements.

You will work with comparison operators to determine if values are equal, greater, or less than each 
other.  C++ also allows you to use mathematical operators for incrementing values to help control the 
number of iterations in a loop.  You can also make use of bitwise operators to speed up some operations 
in your code. 

| Operator	 | Description | 
| ---------- | ----------- |
| +	 | addition | 
| -	 | subtraction | 
| *	 | multiplication | 
| /	 | division | 
| %	 | modulo | 
| += (y += x)	 | same as y = y + x | 
| -= (y -= x)	 | same as y = y - x | 
| *= (y *= x)	 | same as y = y * x | 
| ++	 | increment by 1 | 
| --	 | decrement by 1 | 
| ==	 | equal to | 
| !=	 | not equal to | 
| >	 | greater than | 
| <	 | less than | 
| >=	 | greater than or equal to | 
| <=	 | less than or equal to | 
| &&	 | logical AND | 
| `||`	 | logical OR | 
| !	 | logical NOT

This video explains some of the C++ operators available to you.

https://youtu.be/u_wWuL3q3W4

So the C++ operators kind of start simple like that. They lull
you into a false sense of security, I feel. So we have plus,
minus, star for multiply and slash for divide. Many people go
looking for the operator that means to the power. So X squared,
X, insert some punctuation here to. There is no punctuation
for power of. There's a function. We'll talk about functions
very shortly, but there is not an operator for that.
Then we have plus equals and his cousins minus equals, times
equals and divides equals, which I don't think get used very often.
I use plus equals and times equals quite a lot. In our demos,
we've had really, really simple variable names like I and X.
That's really easy to write I is equal to I plus 2. But what
if the variable was called tomorrow's shipping limit and I needed
to write tomorrow's shipping limit equals tomorrow's shipping
limit plus new additions.
And maybe some of it would roll off the end of the screen, especially
the smaller screens of long ago. So the plus equal operator
just saves you from having to repeat the variable name twice.
So I plus equals 2 means exactly the same thing as I is equal
to I plus 2. It's just a convenience.
We talked about plus-plus and minus-minus in their beginning
before and after versions.
And you saw the greater than being used for comparison.
There's greater than, less than, and as well as greater than
or equal to as well as less than or equal to.
I don't see a lot of use of greater than or equal to or less
than or equal to by C++ programmers, it's purely an idiom.
If we want to do something five times, we'll start at zero and
go until it's less than five.
It would be exactly the same to go until it was less than or
equal to 4. We just don't do it. I mean, it's not wrong.
It's just the way we happen to express ourselves.
The equals comparison, that is, is X equal to Y, this one trips
up people who come from some other languages. You have to press
two equal signs.
If you only press one equal sign, you will actually be changing
the value of X to the value of Y, which is probably not what
you wanted.
And if you want to compare that things are not equal, it's the
exclamation mark equals sign.
So I've heard that JavaScript has something with three equal signs.
Three equals.
So do we have anything like that?
No, we don't.
No, we don't.
So no one can ever complain about our punctuation.
Okay, excellent.
We also don't have a different operator for, like, case sensitive
and non-case sensitive comparisons and that kind of thing too.
So we could be worse, yeah. Wait, the standards committee might
hear us and put more punctuation in.


---

#### Module 3 Control Statements   Decision Statements   Introduction

# Introduction

C++ decision structures provide logic in your application code that allows the execution of 
different sections of code depending on the state of data in the application. You might ask 
users whether they wish to save any changes to a file that is open in the application. The 
decision structure permits you to code behavior to execute based on the answer provided by 
the user. C++ uses conditional statements to achieve this functionality.

The primary conditional statement in C++ is the if statement. An alternative to the if 
statement is a switch statement.  As you will see in the section on the switch statement, 
you might want to use it for more complex decisions.


---

#### Module 3 Control Statements   Decision Statements   if Statements



