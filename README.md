# RPN-Calculator

Compile/run RPN-Calculator:
     - Compile using
            make
     - run executable with
            ./RPNCalc

Compile/run testStringStack:
    - Compile using
           make testStringStack
    - run executable with
           ./testStringStack


Program Purpose:

This project implements a Reverse Polish Notation (RPN) calculator. This is done through a StringStack class that stores elements of type string in it.

Taken from Wikipedia:
In reverse Polish notation, the operators follow their operands; for instance, to add 3 and 4 together, 
one would write 3 4 + rather than 3 + 4. If there are multiple operations, operators are given immediately 
after their second operands; so the expression written 3 − 4 + 5 in conventional notation would be 
written 3 4 − 5 + in reverse Polish notation: 4 is first subtracted from 3, then 5 is added to it.


How to use:

-Entering an integer adds it to the Calculator stack
-Entering a mathematical operator, e.g. "+","/","mod", applies the operation to the last two ints
-Entering a mathematical equality, e.g. "<","<=","==", applies the comparison to the last two ints and puts a
boolean value at the top of the stack
-Entering "clear" clears the Calculator's stack.
-Entering "swap" swaps the top 2 
-Entering "if" looks at top valu
-Entering "quit" exits the program


Files:

StringStack.cpp:
      Implementation of StringStack class. It contains a vector of Datums that behaves as a stack, removing and adding elements from the top only.

StringStack.h:
        Interface of StringStack class.

RPNCalc.cpp:
        Implementation of RPNCalc class. It contains the main run function as
        well as various other helper functions.

RPNCalc.h:
        Interface of RPNCalc class.

main.cpp:
        file containing main function running an instance of RPNCalc

testStringStack.cpp:
        file containing main file for unit testing the StringStack class

test.cyl:
        File containing commands to test RPNCalc class.
test2.cyl:
        File containing commands to test RPNCalc class.

Makefile:
        File containing instructions for compiling

README:
    This file

Data Structures:

Data structures used include, a stack, which is contained within a DatumStack
class. The stack is used with a vector data structure and takes advantage
of already existing functions. An instance of the stack is created in the
RPNCalc class, and its functions are used for the RPN calculator to work.
The stack is very efficient in being used in an RPN calculator because of
how RPN works. By just pushing and popping things from the top of the stack,
one can perform various mathematical operations.

Testing:

Testing for this project was separated in two parts.
Firstly, testing for the DatumStack class was done in the testDatumStack.cpp
file which contains a main functions with various done on the stack, to make
sure all the functions worked as intended. Although the DatumStack class
used already existing vector functions, they were still unit tested to
make sure the class was fully debugged before starting to work on the
RPNCalc class.
Then, testing for the RPNCalc class was a bit different. Firstly, using the
main.cpp file and running the run function, taking in cin input, I manually
input commands to make sure the more simple commands worked, such as pushing
an integer or boolean, printing the top element, or clearing the stack. Then,
to test the more complex functions, I input some manual commands but I also
wrote some .cyl files to make sure functions such as the if or the file
function worked correctly.

Known bugs: such as in test2.cylc. The program skips one of the commands, in
this case, one of the execs.