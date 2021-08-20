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
-Entering a mathematical operator, e.g. "+","/","mod", applies the operation to the last two items<br/>
-Entering a mathematical equality, e.g. "<","<=","==", applies the comparison to the last two items and puts a<br/>
boolean value at the top of the stack<br/>
-Entering "#t" and "#f" respectively adds a boolean value of true or false to the stack<br/>
-Entering a chain of commands and integers in between curly brackets, e.g. "{ 3 5 + 6 -}<br/>
allows the calculator to save it as a single item, which can be executed at a later stage<br/>
-Entering "not" inverses the last item in the stack (assuming its a boolean value)<br/>
-Entering "print" prints out the last item<br/>
-Entering "clear" clears the Calculator's stack<br/>
-Entering "drop" removes the last item<br/>
-Entering "dup" duplicates the last item<br/>
-Entering "swap" swaps the last 2 items in the stack<br/>
-Entering "exec" tells the calculator to execute the last item on the calculator, which must be a chain of commands<br/>
in between curly brackets<br/>
-Entering "file" allows the calculator to read in a file with commands, which must contain the name of the file in<br/>
between curly brackets as the last item in the stack<br/>
-Entering "if" looks at top value on the stack. If false, executes the last item (after the bool value). If true,<br/>
executes the 2nd to last item.<br/>
-Entering "quit" exits the program<br/>