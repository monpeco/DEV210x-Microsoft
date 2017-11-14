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

### if Statements

In C++, if statements are concerned with Boolean logic. If the statement is true, the block 
of code associated with the if statement is executed.  If the statement is false, control 
either falls through to the line after the if statement, or after the closing curly brace 
of an if statement block.

The following code sample demonstrates an if statement to determine if a response contains 
a value of y or Y.
```c++
char response = 'y';
if (response == 'y' || response == 'Y')
{
    cout << "Positive response received" << endl;
}
```
Note the use of curly braces in the code sample.  You can eliminate the curly braces if your 
statement to execute is a single line statement.  C++ understands that if no curly braces are 
used, the line immediately after the if(condition) will be executed if the condition is true.  
Otherwise that line of code is not executed and the code resumes after that line.  If you need 
to have multiple statements execute if the condition is true, then you must use curly braces 
to surround the body of the if structure as in the code sample.  

TIP: To avoid confusion as to which lines will execute for a true condition, a recommended 
practice is to always use curly braces for your if statement.

In C++, if statements can also have associated else clauses. The else clause executes when 
the if statement is false.

The following code example shows how to use an if else statement to execute code when a 
condition is false.

### if else Statements
```c++
string response;
if (response == "connection_failed")
{
    // Block of code executes if the value of the response variable is "connection_failed".
}
else
{
    // Block of code executes if the value of the response variable is not "connection_failed".
}
```
if statements can also have associated else if clauses. The clauses are tested in the order 
that they appear in the code after the if statement. If any of the clauses returns true, the 
block of code associated with that statement is executed and control leaves the block of code 
associated with the entire if construct.

The following code example shows how to use an if statement with an else if clause.

### else if Statements
```c++
string response;
if (response == "connection_failed")
{
    // Block of code executes if the value of the response variable is "connection_failed".
}
else if (response == "connection_error")
{
    // Block of code executes if the value of the response variable is "connection_error".
}
else
{
    // Block of code executes if the value of the response variable is neither above responses.
}
```

You can create as many else if blocks as necessary for your logic, or until you become completely 
lost from too many else if clauses.  If you require any more than five else if clauses, you might 
want to consider the switch statement, presented next.

---

#### Module 3 Control Statements   Decision Statements   switch Statements

# switch Statements

If there are too many else if statements, code can become messy and difficult to follow. In this 
scenario, a better solution is to use a switch statement. The switch statement simply replaces 
multiple else if statements. The following sample shows how you can use a switch statement to 
replace a collection of else if clauses.

### switch Statement

```c++
char response = 'y';
switch (response)
{
   case 'y':
      // Block of code executes if the value of response is y.
      break;
   case 'Y':
      // Block of code executes if the value of response is Y.
      break;
   case 'n':
      // Block of code executes if the value of response is n.
      break;
   default:
      // Block executes if none of the above conditions are met.
      break;
}
```
Notice that there is a block labeled default:. This block of code will execute when none of the other 
blocks match.  The default block is optional.

In each case statement, notice the break keyword. This causes control to jump to the end of the switch 
after processing the block of code. If you omit the break keyword, the application may not perform as 
you anticipate.  In other languages, such as C#, omitting the break; keyword will cause the code to no 
longer compile. 

Without the break statement, the code will "fall through" to the remaining cases until it encounters a 
break statement.   Be very careful in using fall through logic in your switch statements.  The most 
common use for a fall through scenario is when you want to handle multiple cases with a single statement 
or set of statements.

If you are coming from another programming language, such as C#, that also uses the switch statement, 
you might notice that in the C# language, you can use string values in your switch statements and don't 
have to use integers or enumerated types.  C++ switch statements support the following data types as 
expressions:

* intrinsic data types such as int or char
* enumerations

---

#### Module 3 Control Statements   Decision Statements   The Conditional (Ternary) Operator

# The Conditional (Ternary) Operator

The C++ conditional operator is also known as a ternary operator because it takes three operands.  
How this operator functions is somewhat similar to an if statement or a switch statement, but in a 
more compact form and for one single Boolean value with one of two possible outputs.   That is to 
say, the first operand is evaluated as a Boolean result.  If the result is true, then the second 
operand will be the one evaluated.  Otherwise, the third operand will be evaluated.   A sample 
helps amplify this.
```c++
#include <iostream> 
using namespace std; 
int main() 
{ 
     int i = 1, j = 2; 
     cout << ( i > j ? i : j ) << " is greater." << endl; 
}
```
In this example, we have two integer variables, i and j which are initialized to 1 and 2 respectively.  
The ternary operator is embedded inside the cout statement and essentially follows this pattern:

it checks whether i is greater than j
it outputs the proper numeric value along with is greater.
In the code example here, j is greater than i so the condition evaluates to false and the value for 
j (2), is output to the console along with the text is greater.  In other words, the output 
is "2 is greater."  If i was 5 and j was 2, the output would be, "5 is greater." 

* i > j ? **i** : j where i is greater than j then the bold value is selected

i > j ? i : **j** where j is greater than i, then the bold value is selected

---

#### Module 3 Control Statements   Decision Statements   Flow Control Video

# Flow Control

https://youtu.be/SBa_3u9Ur08

---

#### Module 3 Control Statements   Repetition Statements   Introduction

C++ provides a number of standard constructs known as loops that you can use to implement iteration logic.  
If you are coming from other programming languages, you might recognize for loops, while loops, and do loops.  
C++ supports all three of these iteration statements.

The ability to repeat a series of statements is a core requirement of most application code.  You might need 
to iterate over a series of items in an array or perhaps you need to count the number of characters in a 
string or the number of words in a document.   Repetition, through the use of loops, is the way in which you 
achieve these operations.

---

#### Module 3 Control Statements   Repetition Statements   for Loops

# for Loops

The for loop executes a block of code repeatedly until the specified expression evaluates to false. You can 
define a for loop as follows.

```c++
for ([initializer(s)]; [condition]; [iterator]) 
{
   // code to repeat goes here
}
```

The [initializer(s)] portion is used to initialize a value, or values, as a counter for the loop. On each 
iteration, the loop checks that the value of the counter is within the range to execute the for loop, 
specified in the [condition] portion., and if so, execute the body of the loop.   At then end of each 
loop iteration, the [iterator] section is responsible for incrementing the loop counter.

The following code example shows how to use a for loop to execute a code block 10 times.

```c++
//for Loop
for (int i = 0 ; i < 10; i++) 
{
    // Code to execute.
}
```

In this example, i = 0; is the initializer, i < 10; is the condition, and i++ is the iterator. 

---

#### Module 3 Control Statements   Repetition Statements   while Loops

# while Loops

A while loop enables you to execute a block of code while a given condition is true. For example, 
you can use a while loop to process user input until the user indicates that they have no more 
data to enter.  The loop can continue to prompt the user until they decide to end the interaction 
by entering a sentinel value.   The sentinel value is responsible for ending the loop.

The following code example shows how to use a while loop.

```c++
//while Loop

string response;
cout << "Enter menu choice " << endl << "More" << endl << "Quit" << endl;
cin >> response;

    while (response != "Quit")
    {
        // Code to execute if Quit is not entered

        // Prompt user again with menu choices until Quit is entered
        cout << "Enter menu choice " << endl << "More" << endl << "Quit" << endl;
        cin >> response;
    }
```

It's imperative to include the prompt again, inside the loop braces.  Failure to put this into 
the loop body will result in an infinite loop because the sentinel value can never be changed.


---

#### Module 3 Control Statements   Repetition Statements   do Loops

# do Loops

A do loop, sometimes also referred to as a do...while loop, is very similar to a while loop, with the 
exception that a do loop will always execute the body of the loop at least once.  In a while loop, if 
the condition is false from the start, the body of the loop will never execute. 

You might want to use a do loop if you know that the code will only execute in response to a user 
prompt for data. In this scenario, you know that the application will need to process at least one 
piece of data, and can therefore use a do loop.

The following code example shows the use of a do loop.

```c++
//do Loop

string response;

do
{        
     cout << "Enter menu choice " << endl << "More" << endl << "Quit" << endl;
     cin >> response;

     // Process the data.

} while (response != "Quit");
```

A couple of aspects to note about this loop.  First of all, the  response variable is declared outside 
of the loop.  This is important due to scope resolution requirements.  If you declare the variable 
inside the loop, then the `while(response != "Quit")` portion will not "see" the response variable.

Second, note that in comparison with the while loop, the prompt only needs to be placed inside the loop 
body and is not required ahead of the loop.  This is possible because the do loop executes the contents 
of the loop at least once due to the condition check being at the end of the loop.

Third, notice the semicolon at the end of the loop.  This is required in the do loop and not in the 
while or for loop.


---

#### Module 3 Control Statements   Repetition Statements   Nesting Loops

# Nesting Loops

Nesting of loops is possible in C++.  The most common is to nest for loops.  An example of nesting a for 
loop might be used for games, such as dealing four hands to card players from a deck of 52.  Your outer 
loop would count from 0 to 51 for the total number of cards in the deck and the inner loop would count 
from 0 to 3 to represent the 4 hands being dealt.   Of course, if you aren't dealing the entire 52 cards, 
you can change the outer loop counter to represent that fact.

The following code example shows nesting for loops to output a chess or checkerboard representation using 
the characters X and O.

```c++
bool alternate = true;

for (int x = 0; x < 8; x++)
{
    for (int y = 0; y < 4; y++)
    {
        if (alternate)
        {
            cout << "X ";
            cout << "O ";

        }
        else
        {
            cout << "O ";
            cout << "X ";

        }
    }
    alternate = !alternate;

    cout << endl;
}
```

---

#### Module 3 Control Statements   Repetition Statements   Flow Control Demo

# Flow Control Demo

Absolutely. So what we have here
in this code editor window, there we go, is a
simple program. So I'm actually just going to... we're not going
to walk through it first. We'll just build it and step through
it in the debugger. So you can see here that we have two integer
local variables, X and Y, and we've initialized one to...
the first to 2 and the second to zero.
So we have an if statement, and in here we check if X is greater
than 3, then we'll increment Y, so we'll add one to it.
Otherwise, we'll remove one from Y. When we hover over X, there's
another feature of the debugger is the... it will actually show
you what its current value is. So right now, we can see it's
two, which is as we expected, because that's what we initialized
it to.
And we know that 2 is less than three, I think.
It's not greater than, anyway.
Yes. So we're not going to take this first branch of the if block.
We'll use the else branch. So if we step over, we'll see that,
indeed, we've entered into the else block, and we'll change the
value of Y. So Y is now negative one.
So then we have a four-loop here, and this four-loop is going
to count from I equals zero. So we're going to initialize I to
have the value of zero. I is a common loop variable and if you
have nested loops, often people use I, J, K. And if you get
any more than that, you're in a lot of trouble.
You're doing something wrong.
Yeah, it's not good.
So we're going to loop as long as I is less than X. So it's
important to know that this is not the condition when we stop.
So this is the condition, we will loop as long as this is true.
And each time through the loop, we will increment I. So we're
basically counting from I equals zero to I equals 2.
I don't think we've shown that plus-plus operator before.
I don't think we have, no so this plus-plus operator is actually
equal to this. So there's no difference between the two of them.
It's just a shorthand notation, and it comes in very handy in
many cases.
The very name of the language is a joke based on this, that
you take the language C, and you increment it and make it a little
bit bigger, or better, and it's really vital. You see the plus
plus and awful lot in our applications, and that's all it is.
It just bumps it up by one.
And minus-minus is the opposite. It subtracts one so we can
step through here. So we've entered the loop for the first time.
So the value of I is zero. It's important to note that this increment
happens at the end of the loop body. And we'll maybe see an
example of that in a moment. And we can step over this, and so
you can see, we're printing out numbers. We're printing out
the value of I each time through the loop.
So at the end there, I was 2, and so we can see that we've printed
zero and 1. And then when I equals 2, it was no longer less than
X so we broke out of the loop.
And that's a really common C++ idiom, to go from zero to less
than X means to go X times.
Yes.
You know, so we went through that loop twice. Once for zero
and once for one. And we are a zero-based language and that's
how we go through things. And if we go through something five
times, it will be for zero, one, two, three, four. Not for one,
two, three, four, five. It's not...
Indeed. So here we have a while loop, which is effectively
the same... basically a 4 and a while loop can accomplish all
of the exact same things.
So here we're going to loop as long as X is less than 4.
So we're going to step into the loop, X is currently 2, so it's
obviously less than 4.
Now, we have another variable here, J. It's important to note
that so local variables like these are constrained by their scope,
which is defined by these braces. So the braces in which local
variables are defined specify where you can use them. So, for
example, we could not use J out here. We certainly couldn't
use it here before we, you know, we declared it. We also couldn't
use it here before it's declared, even though we're in that same
set of braces. So the scope of J is from the point where it's
declared up until the brace that ends it. These braces are called...
are what's called a compound statement, and they basically just
group statements. So each of these is a statement here, and these
braces here just say, ah, this is a set of statements that we
want to treat as a group. So that's why we put them after most
loop bodies, or most loop headers.
So we've added 2 to X so it now has a value of 4.
We come back up, we check the condition. X is no longer less
than 4 so we break out.
Here, we're showing... so that plus-plus operator that we talked
about, there's actually two different forms of it. You can have
plus-plus at the end of the X, or you can have plus-plus before
the X.
They have the same effect on X, so both of them increment X.
They both add one to the value of X. The difference is what
the value of that expression is. So, you know, you might say,
well, X++, it's, you know, you would never use the value.
But you can actually take that and, you know, use its value to
assign another variable. So X++
increments X, but then it yields the original value of X.
++X increments X and it yields the new value of X. So, for example,
we can step over here, we're going to, you know, do X++ and assign
the value to Y.
And we're going to see that Y has the value of 4, which was the
old value of X, and X has the value 5, which is the new value.
Similarly, if we again increment X, then X will have the value
6, and we expect here Y will also have the value 6, because we're
using the pre-increment form.
And, indeed, thankfully, that's what happened.
Now, if this freaks you out at all, and it does freak some
people out when they first get started, just don't ever use it,
the plus-plus operator, not just on a line of its own. That is,
we could have easily written Y equals X, and then on a new line
X++, or the other way around. And if you don't want to remember
which side of the variable the plus plus goes on, just do it
that way. Just put them on separate lines and you'll be really
clear about what you're after.
But it's important to mention it to people, because otherwise
they get very confused. Oh, and what's the most important rule
of stack overflow C++ questions?
Don't increment... don't plus plus the same variable twice on
a line and then write me a stack overflow question asking why
it's being weird. Right? Like Y equals X++ plus X++, that's a
bad thing. Yeah, so as a general rule of thumb, just avoid modifying
multiple things in a single statement. Just make sure that every
statement you may modify one thing at time, and you're totally safe.
You don't have to worry about it. So here, this is questionable,
because we're modifying both Y and X. So just in general, try
and avoid doing that and it will be much cleaner, easier to ups,
easier to debug.
That's all right. Put them on separate lines. You want to
set Y to the value of X first, then have a line that says Y equals
X first. When you're showing these lines of code because you
may be asked to read other people's code and you're going to
bump into this sort of thing. And modern C++ plus, you know,
doesn't try to pack everything into one line, one statement,
one expression. It tries to be more
sane, readable.
Perhaps, yes.
But if nothing else, if you forget, you can always load it up
in the debugger, step through it, and you can see exactly what's
happening, and that's often an effective way not only to, you
know, debug code if you want to try and understand what's going
on, but also to learn the language, you know, to just write things
and say, oh, what is happening here.
Right.
So after that, we now have another type of control flow statement
that Kate didn't mention. It's called a switch. So a switch
looks at the X or looks at whatever expression it's given, and
it takes its value and it has different cases that it can do
for each of the values. So, for example, here, if X is 4, we'll
enter this case. If X is 5, we'll do this case and so on.
So X is 6, so we're going to end up jumping into this case 6
and, indeed, then we'll see in the output window, we've printed
X as 6.
If X was none of those values, like if X had a value of, say,
20, we would enter what's called the default case and so here,
we would have printed out that it's, you know, it's not one of
those values. You don't have to have a default case, in which
case if it doesn't match any of the existing cases, it will just
skip over the whole switch statement. It won't do anything.
So that's not an error.
So you could have built this out of a whole pile of ifs?
You could have, yes.
But when you use a switch statement, you're sort of telling
the people who read your code, I'm really only expecting one
of these things to happen. So even though you see several ifs
in a row, I'm really just trying to figure out one thing to do,
whereas normally, when you see five ifs in a row, anywhere from
zero to five of those things could actually happen. The case
statement, switch statement makes it clearer your intent.
Again, if you don't want to learn a switch statement on day one,
just use a bunch of ifs and later you can start using switches.
So then finally, we have... this is not a control flow statement.
It's just another form of expression is this funny question mark
thingy, as a former colleague of mine referred to it.
And so this is called a conditional expression, and what it does
is it has three parts. This first part here is a condition.
So it will test this condition, and it will say, oh, you know,
is this true or is it false? So in this case, the debugger helpfully
tells us, hey, this is true.
If it's true, then it will evaluate this middle piece, the piece
between the question mark and the colon, and it will yield that result.
If it's false, it will do this 10 piece here, or the piece after
the colon. So if we step over, we'll see that X indeed gets the
value of 5, because Y is greater than 5 was true.


---

#### Module 4 Functions and Objects   Introducing Functions   Introduction to Functions

# Introduction to Functions

Functions are a component of a programming language that permit you to break down the behavior of an 
application into discreet pieces of functionality, hence the name function.  A function is essentially 
a block of C++ code that you give a name and then call from other locations in your application, when 
you want the computer to perform the instructions contained in that function.

You create a function by defining it.  The function definition may contain a return type, a function name, 
parameters to accept incoming arguments, and finally a body which contains the code that will execute as 
part of that function.  Functions may or may not return a value back to the caller and they may or may 
not accept arguments passed in to the function.

When you move into more advanced C++ programming, you can also overload functions.  This refers to the 
practice of using the same function name to refer to multiple functions that perform different actions.  
Why would you do this?  Consider a simple scenario where you want to perform addition on some values so 
you create a function called Sum().  You could overload Sum() by creating variants such as:

```c++
int Sum(int x, int y)
{
     return x + y;
}

int Sum(int x, int y, int z)
{
     return x + y + z;
}
```

The compiler will know which function to call, based on the number of arguments passed in.


I've referred to functions a couple times. Functions are not
the real building blocks of C++.
That honor goes to classes and objects. But they are the building
blocks of C and C++ builds on that.
You know, anytime you've got 20 lines of code to do something,
add up all the items in an order and calculate the sales tax,
you shouldn't just sort of copy and paste those 20 lines of code
if you need them again later in your program. You should wrap
them up and give them a name, and the kids these days, Agile
kids and all that, will have to go around saying don't repeat
yourself and having a function is a good example of being dry,
of saying I'm not going to copy and paste these lines of code.
I'm going to put them in a function. The nice thing about putting
something in a function is it gives it a name. Now, anyone who's
reading it can say it calculates total and sales tax. I know
what this code does, because it's got a label on it. Unlike a
comment, which will probably end up being a lie later. And my
favorite kind of function, of course, are the ones that I don't
have to write because they came in a library and someone else
took care of them for me.
Just as variables are strongly typed, functions are strongly typed.
They have a return type, which is a lot like the type of a variable.
That's one of the places where void comes in. Some languages
have something like a sub routine where it goes off and does
something but doesn't return a value. In C++, that's a function
that returns void. And we just call them all functions.
They're also typed in the sense of what you pass to them.
If I want to write a function that takes a number and does something
to it, well, it takes a number. An integer, to be specific, or
a double, and it's not appropriate to give it a string or some
other type.
Once you get into functions having the strongly typed capabilities,
you also get into the possibility that you can actually have
two functions with the same name as long as the compiler can
tell them apart. One way the compiler can tell them apart is
if they take a different number of parameters.
In theory, compiler can also tell them apart if they take different
types of parameters, but because the compiler loves to do conversions
for you, they may not be as different as you think. But a different
number of parameters is a great way to tell functions apart.
So if you want to use a function, you have to tell the compiler
it exists. You can either do that by giving the compiler all
the code for the function to compile, or as you'll see shortly,
by just making it a promise that you keep later.

---

#### Module 4 Functions and Objects   Introducing Functions   Function Prototypes