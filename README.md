# RPN-Calculator

Compile/run RPN-Calculator:<br/>
     - Compile using<br/>
            make<br/>
     - run executable with<br/>
            ./RPNCalc<br/><br/>

Compile/run testStringStack:<br/>
    - Compile using<br/>
           make testStringStack<br/>
    - run executable with<br/>
           ./testStringStack<br/><br/>


Program Purpose:<br/><br/>

This project implements a Reverse Polish Notation (RPN) calculator. This is done through a StringStack class that<br/>stores elements of type string in it.<br/><br/>

Taken from Wikipedia:<br/>
In reverse Polish notation, the operators follow their operands; for instance, to add 3 and 4 together,<br/>
one would write 3 4 + rather than 3 + 4. If there are multiple operations, operators are given immediately<br/>
after their second operands; so the expression written 3 − 4 + 5 in conventional notation would be<br/>
written 3 4 − 5 + in reverse Polish notation: 4 is first subtracted from 3, then 5 is added to it.<br/>


How to use:<br/><br/>

-Entering an integer adds it to the Calculator stack<br/>
-Entering a mathematical operator, e.g. "+","/","mod", applies the operation to the last two ints<br/>
-Entering a mathematical equality, e.g. "<","<=","==", applies the comparison to the last two ints and puts a<br/>
boolean value at the top of the stack<br/>
-Entering "clear" clears the Calculator's stack.<br/>
-Entering "swap" swaps the top 2<br/>
-Entering "if" looks at top valu<br/>
-Entering "quit" exits the program<br/>

