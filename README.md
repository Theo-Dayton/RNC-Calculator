# RPN-Calculator

Compile/run RPN-Calculator:\
     - Compile using\
            make\
     - run executable with\
            ./RPNCalc\

Compile/run testStringStack:\
    - Compile using\
           make testStringStack\
    - run executable with\
           ./testStringStack\


Program Purpose:\\

This project implements a Reverse Polish Notation (RPN) calculator. This is done through a StringStack class that\stores elements of type string in it.\

Taken from Wikipedia:\
In reverse Polish notation, the operators follow their operands; for instance, to add 3 and 4 together, \
one would write 3 4 + rather than 3 + 4. If there are multiple operations, operators are given immediately \
after their second operands; so the expression written 3 − 4 + 5 in conventional notation would be \
written 3 4 − 5 + in reverse Polish notation: 4 is first subtracted from 3, then 5 is added to it.\


How to use:\\

-Entering an integer adds it to the Calculator stack\
-Entering a mathematical operator, e.g. "+","/","mod", applies the operation to the last two ints\
-Entering a mathematical equality, e.g. "<","<=","==", applies the comparison to the last two ints and puts a\
boolean value at the top of the stack\
-Entering "clear" clears the Calculator's stack.\
-Entering "swap" swaps the top 2 \
-Entering "if" looks at top valu\
-Entering "quit" exits the program\

