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