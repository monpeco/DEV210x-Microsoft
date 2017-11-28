#### Module 4 Functions and Objects   Encapsulation   Introducing Encapsulation

# Introducing Encapsulation

Often considered the first pillar of object-oriented programming, encapsulation can be used to describe the 
accessibility of the members belonging to a class.  C++ provides access modifiers and properties to help 
implement encapsulation in your classes.  While some consider this accessibility configuration to be the 
only aspect of encapsulation, others also define encapsulation as the act of including all data and behavior 
required of the class, within the class definition.

We use encapsulation to prevent changing the member variables directly.  This is considered a poor practice 
because it presents the opportunity for potentially incorrect values to be assigned to these member variables.  
This can result in unexpected behavior or more serious problems with your executing code.  It also helps with 
debugging of your code.

So let's first talk about what encapsulation is.
So let's say we wanted to write a function that computes the
area of a rectangle. So we could do this quite easily. We could
write a function that says compute area that takes the rectangle
and multiplies the width by height.
And we can call it to compute the area and this works quite well
like there's nothing particularly wrong with this. But the area
is a rather fundamental property of a rectangle. It would be
really nice if we could say this is a special property of each
rectangle and so we want to express that in our code. So we
can do that using what's called a member function.
In some languages this is called a method. They're basically
the same thing and C++ we use the term member function.
So here's how we would define such a member function.
It goes in the body of the class rectangle and we can say int
get area. So it looks just like a normal function and this member
function, though, has access to a special parameter called this.
So you don't have to declare this anywhere. It's automatically
declared by the compiler. What that means this is the object
on which the member function was called. For example, if you
look over at our function F, you can see that we've called get
area on this rectangle named a rectangle. So inside of get area,
this is what's called a pointer, and we'll see more information
on that later. So it's basically a... it's the rectangle there
on the function on which we called the function.
So we can use the pointer and this arrow operator, both of which
we'll describe later, to access the members of the class.
Now, this is not the... this keyword is not necessarily required.
In most cases you don't need to use it.
Its special use, good idea to use a different naming convention
for member variables and nonmember variables that way you can
distinguish between them. If it's unambiguous what underscore
width is you can remove the its, you can remove this and height
they don't
remember it in their actual code.
That's why you started those member variables with underscores, right?
So you could easily tell them apart from locals.
That's correct. There's many different naming conventions underscore
in front, underscore behind, M underscore is common in some code
bases, how you name your variables is entirely up to you as long
as you're consistent and it makes sense to you.
So one of the most important pieces, one of the most important
reasons to use classes is we can use member functions to hide
the data that they represent. So, for example, we don't want
people to be able to change the values of width and height willy-nilly.
We'd rather like perhaps we'd like to have a resize function
that allows us to do some checking to make sure that they're
not negative numbers being passed in or something like that.
So first we'll need a way for people to be able to get access
to the width and the height. And we can do that just by writing
other member functions. So here we've written a get width and
a get height, and they just return the width and height.
Now, you'll see that we've made the width and height private.
So the private corresponds to the public and what public means
is that you can use these from outside of the class. So in our
function F that we had before, we can call get area and get width
and get height but we can't access underscore width and height.
We'll get a compiler error if we do that.
Like we do here. Those won't work. We can access the public
members we can easily call get width and get height. No problem
compiler will be very happy with it.
So this is all well and good. But what happens
is I have two slides with the same content.
What happens if we want to initialize our rectangle now, well,
we can't access the underscore width and height so we can no
longer use the initialization form where we have two different,
where we initialize them separately.
We can still do value initialization. Because we don't actually
refer to the members but we can actually initialize them to a
rectangle with dimensions of two and three.
What we can do is add a resize function. So this resize function
can take a new width and new height and assign new values to
the members. And in our function F we can just create a value
initialize rectangle so it starts off with width and height of 0.
And we can resize it to that size.
But this isn't really great. I mean, we'd really like to be able
to initialize things to their value.
This would prevent us from making the rectangle const because
you can see we're changing it after we declare it. So ideally
we'd like to be able to initialize something at the beginning.
And the way we do that is
using constructors. So here, for example, I've written two constructors
for the rectangle class and I've gotten rid of the get functions
just for brevity. So you can see here we have two constructors.
We have one that is default initializes the rectangle to have
a width and height of 0 and we have one that takes a width and
height and initializes the width and height with those. And so
we are now able to initialize our rectangle using all the same
forms that we were before. We think value initialize it still
which will end up invoking the default constructor. We can initialize
it using the two explicit width and height and that is done,
it has the same result as before but it ends up calling our constructor instead.
And similarly if we really wanted to we could value initialize
our rectangle and resize it to the dimensions we want.
So why do this? Like clearly this is a lot more work, having
to write these constructors and excessers and other things instead
of just accessing the member variables directly. But again as
we said we want to restrict how we use types as much as possible.
We want to make it easy to use them correctly which means providing
as few operations as are required. We don't want to make them
hard to use we want to make them easy to use correctly.


---

#### Module 4 Functions and Objects   Encapsulation   Encapsulation Demo

# Encapsulation Demo

Remember.
You know, if you're writing a banking system you had to say remember
after you reduce anybody's balance also charge them a service
charge, and with encapsulation you can say I'm not going to let
you get directly to balance I'll let you call withdraw function
and withdraw will charge the service charge now whoever is working
with the bank account doesn't have to remember.
Absolutely.
To make that call.
Like back here with our rectangle our resize function has made
it impossible to change the width without the height. We have
to change them both at the same time. We might also,
we might change our resize function, for example, to check to
make sure that the area of the rectangle is not more than 10,000
and by requiring us to provide a width and a height, it allows
you to resize it more easily.
Right. So we can start to implement our business logic.
We're giving you very simple classes today. They don't really
have any business logic. But you're going to write real classes
that do and that need to be kept consistent and kept sensible
and encapsulation is really the key to letting that happen.
I've got some sample code to show you here, which is essentially
the code that you saw from the slide.
And if I run this application,
and we can step through, it's going to be a little different
now, because in rectangle.H we've implemented these constructors.
So this is the default constructor and just to prove a point
I decided to have it initialize the width and the height to 1
rather than to 0 I actually don't think I would do this in real
life but I wanted to prove that this constructor's code is actually
being used.
Do we have to provide a default constructor at all?
No, but then people can't default construct your object.
If I comment this guy out then the lines trying to use the default
constructor won't work.
This is the constructor who takes parameters and uses them, gives
initial width to width and height to height. And compiler doesn't
read your words if you want to foolishly put the width and height
and height and width you'll have a bug.
It's your friend but not that much of your friend and there's
the resize function that uses those parameters.
So if I step through here, our uninitialized variable is now
not full of the special signal value. It's used the default constructor.
However, just because the compiler will do this for you I still
don't want you ever to do this. I want you to do this with the
open and closed brace, because that really says to everyone who
is reading your code, hi I'm using the default constructor here.
Makes it really obvious what's happening.
So a value will come out with width and height of 1 as you can
see here down in the locals window and aggregate will come out
4 and 7.
I can call resize on value. Obviously that doesn't change the
size of uninitialized or aggregate. I can call resize on aggregate.
I stepped into... I meant to do that.
You can watch this here. The new width comes in as 1 and new
height is 2. Currently here are the old values and after we step through.
It's worth noting in the local's window here you can see this
object, it's the object on which we're currently executing.
This is true. It's always there for us and there you can see
what it points to as well.
We changed the width and the height to the new values. We came
out and we're back in our main code.
And we've resized both rectangles. And now we can call this
area function and independently get the area of the two rectangle,
there's no relationship between them. They just both happen
to be rectangles, any more than if I have I and J are both integers,
changing one does nothing to the other and the values and aggregate
are separate
rectangle in this application.
Now, I wanted to show you one other thing, and that's this file
here called rectangle.CPP.
We don't have to implement all of the functionality inside the
header file like this, as you've seen.
You are allowed, if you want,
to implement it in here. However, when you do that, you have
to call it by its full name.
The name of the class and that same scope resolution operator.
Its full name including the letter E.
Once when I do that, then in here I change this from a definition
to just a declaration.
And if I build, this is quite happy to build and it would run
exactly the same. You might do this if the header file was very,
very large or for some other reason that you wanted to keep the
implementation of the function in just one file rather than in
the header file. We're keeping everything mostly in one file
today just so we don't have to flip amongst as many files to
show you our demo.
But in very large projects that take a long time to compile,
oftentimes making header files as small as possible and moving
member functions into a separate file is generally done both
to improve compile times but also to improve some level of encapsulation
because all those implementation details are separated from the
actual class itself or most at least.
Even something as simple as sharing amongst developers, if
I wanted to work on the rectangle implementations I could just
check out the CPP file and other developers who wanted to change
something in the declaration of the class wouldn't need to care
about what I had done.
Yep.

---

#### Module 4 Functions and Objects   Const Objects   Introducing Const Objects

# Introducing Const Objects

So finally we're going to talk a bit about again about
the const keyword and how it applies to objects.
As we saw before on the previous section, we can const qualify integers.
So here the int Y is cons qualified. We can't make changes to it.
Similarly we can do the same thing with rectangles or any class type.
Here we have two rectangles. One is a mutable rectangle. We can
change it. It's not const qualified and the other is immutable
const qualified and we're not able to change it.
So this is simple enough. But we'll quickly run into problems.
So, for example, if we try to call the get area function, it's
not going to work. The compiler will actually complain and we'll
see it in a moment in a demo, I think.
And the reason for this is that so at first it might seem like
this doesn't make sense. Get area doesn't change the rectangle
at all only the resize function changes it but get area only
accesses the members. So the problem is the compiler doesn't
know that. We actually have to tell the compiler no, this member
function is not going to change the object. And we do that by
adding a const qualifier to the member function. So just like
you can const qualify objects like ints and rectangles you can
const qualify
member functions, and what this does is it says I promise that
this member function isn't going to make any changes to any of
the members of the class. So, for example,
here we've made get area const because it doesn't change anything,
it just reads.
Once we make this change now we can call it get area, no problem.

---

#### Module 4 Functions and Objects   Const Objects   Constant Objects Demo

# Constant Objects Demo

I may have said we're going to demo something we didn't have
a demo prepared for.
So this is a smaller version of the same application.
And what I'm going to do is first run it to make sure that it
will run, build and be happy.
And I've just put the break point on the very end because I don't
actually care about the run, I just want to prove that it will run.
But if I take these three rectangles and I decide to make this
one value into a const rectangle
I can put the const here or I can say const rectangle value,
either way.
Immediately these red wiggles appeared.
And the hover over error is not that great.
It says the object has type qualifiers not compatible with member function.
Let's do a build and look at the output.
That's a little bit better.
Not super great. You can see, though, that the word const is
in the air. And that's really the key.
I'm taking value.area and it's saying wait
I bet you area changes value.
And you said that it was const.
Now, if we look at the code for area, you can see that it doesn't
change the value in any way. It doesn't change the width.
Doesn't change the height. So what the heck?
But as you saw, the implementation for this function might not
even be in the header file.
And there has to be a way to tell the compiler you know what
area does not change any of the member variables of rectangle.
And that way is the const keyword.
If I had the const keyword right here...
why is he not happy?
Save, maybe.
There we go.
Temporary thing from the... now, these wiggles have gone away.
Now it's okay to call area on value again.
Now, I'm not calling get width and get height right now so let's
do that.
It's called values width, VW is equal to value.get height.
No, not if we want the width. Get width.
Same thing. I get an error.
Because get width is not marked as const either. So we go in
and we say that's fine. Getting the width of a
rectangle doesn't change any of the values. Getting the height doesn't.
Now, if I build it succeeds.
This is why it's so important to think about const at the beginning.
Imagine if rectangle was an enormous class and no one had ever
made a const rectangle and then they suddenly had to go back
in and mark all these methods as being const, they'd get irritated,
and they really shouldn't. When you write rectangle for the first
time you go to save I'm going to return the width. At that moment
you should be thinking and I know that doesn't change the object
so I'm going to put this promise in here. Just in case anyone
ever wants to make const rectangles, going back and adding it
later can be really irritating. You want to do it every chance
you get.
Of course you can't do it here.
Constructor changes the object, it initializes it.
This version of rectangle doesn't have a resize, but resize isn't
const either because it changes width and height.
If we tried to make it const the compiler would not be happy
with us.
That's right. You can't just go around lying to the compiler,
it will catch you.
Thinking about const from the very beginning, that's absolutely
vital to writing good classes well encapsulated code.


