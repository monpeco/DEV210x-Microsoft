#### Module Four Streams and Files   Module Four Introduction   Module Introduction

# Module Introduction

The reason we titled this opening section as Stream I/O is because input/output operations in C++ occur in 
streams.  Streams are essentially a sequence of bytes that are sent from device to device.  A device can 
refer to an input device such as a keyboard, a disk drive or even across the network or output devices such 
as display screens, printers, etc.  

These streams are typically raw bytes but they have meaning within the context of an application.  Consider 
a Microsoft Word document being opened from disk.  If you attempt to open it using a generic text editor, 
you won't see the proper representation of the information stored in the document.  Word uses many different 
formatting characters and other information that specifies how the document should appear inside the Microsoft
Word application.  Opening it in Microsoft Word, the stream of bytes now have the actual representation of the 
bytes and the text data and formatting data are properly separated.
 
 
---

#### Module Four Streams and Files   Stream I/O   Introduction to Streams

# Introduction to Streams

C++ defines a standard iostream library, which allows you to input and output data to the console using `<<` and `>>` 
operators. We've seen some simple examples of these operators already. Here's another example, which asks the user 
to enter a couple of numbers and outputs their product:

```node
#include <iostream>
…
double unitPrice;
int quantity;

std::cout << "What is the unit price? ";
std::cin >> unitPrice;

std::cout << "How many do you want? ";
std::cin >> quantity;

std::cout << "Total cost is " << unitPrice * quantity << std::endl;
```

cin and cout are predefined objects in the std namespace. There's also a predefined object called cerr, which is 
handy for outputting error messages. These three objects are defined in the `<iostream>` header file. 

- `cin` is an instance of the istream class, and allows you to perform input from the stdin device.
- `cout` is an instance of the ostream class, and allows you to perform output to the stdout device. 
- `cerr` is another instance of the ostream class, and allows you to perform output to the stderr device. 

We'll take a closer look at the istream and ostream classes in the next topic. 

**Note:** std::endl outputs a newline character to the output stream. Technically speaking, std::endl is a manipulator. 
We discuss manipulators later in this section.


---

#### Module Four Streams and Files   Stream I/O   A Closer Look at istream and ostream
