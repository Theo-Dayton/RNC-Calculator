/*
 *  RPNCalc.cpp
 *
 *   *  Implementation of RPNCalc class, which includes key functions regarding the RPNCalc, such as the default constructor, readFile, run function and other
 functinos used in the calculator.
 *
 *  Written on: 10/20/2020
 */
 #include <iostream>
 #include <sstream>
 #include <fstream>
 #include <vector>
 #include <string>
 #include <cstdio>
 #include <cstring>
 #include <stdlib.h>

 #include "StringStack.h"
 #include "RPNCalc.h"

 /* A function that will tell you whether a string can be interpreted
 * as a integer number, and, if so, give the
 * value.
 */
bool got_int(string s, int *resultp) {
         /* Holds the first non-whitespace character after the integer */
         char extra;

         return sscanf(s.c_str(), " %d %c", resultp, &extra) == 1;
}

 /* default constructor. stack is initialized by itself
     Parameters:
         None
 */
RPNCalc::RPNCalc() {

}

 /* default destructor. stack already has a desconstructor
     Parameters:
         None
 */
RPNCalc::~RPNCalc() {

 }

 /* emptyStackCheck function which cerr's an error if stack is
 empty. Returns true if not empty
     Parameters:
         None
     Effects:
     returns error to cerr if stack is empty
 */
bool RPNCalc::emptyStackCheck() {
    if (stack.size() == 0) { // if stack is empty ce
        cerr << "Error: empty_stack" << endl;
        return false;
    }
    return true;
}

/* emptyStackCheck2 function which cerr's an error if stack is
empty or contains only 1 element. Returns true if not
    Parameters:
        None
    Effects:
    returns error to cerr if stack is empty or 1 element only
*/
bool RPNCalc::emptyStackCheck2() {
    // if stack is less than size 2 cerr an error
   if (stack.size() == 0 || stack.size() == 1) {
       cerr << "Error: empty_stack" << endl;
       return false;
   }
   return true;
}

/* intCheck function which cerr's an error if top 2 elements are
not int. Returns true if they are
    Parameters:
        None
    Effects:
    returns error to cerr if top 2 elements not integers
*/
bool RPNCalc::intCheck() {
    int value;
    // first get top 2 elements from stack
    string element1 = stack.top();
    swap();
    string element2 = stack.top();
    swap();
    // if top element is not int, pop it and cerr error
    if (!(got_int(element1,&value))) {
        cerr << "Error: string_not_int" << endl;
        stack.pop();
        return false;
    }
    // if 2nd from top element is not int, pop top 2 elements and cerr error
    else if (!got_int(element2,&value)) {
        cerr << "Error: string_not_int" << endl;
        stack.pop();
        stack.pop();
        return false;
    }
    return true;
}

/* booleanCheck function which cerr's an error if top element not
a boolean. Returns true if it is
    Parameters:
        None
    Effects:
    returns error to cerr if top element not boolean
*/
bool RPNCalc::booleanCheck() {
    // if top element is not boolean cerr error
    if (stack.top() != "true" && stack.top() != "false") {
        cerr << "Error: string_not_bool" << endl;
        return false;
    }
    return true;
}

/* rStringCheck function which returns false if top element not
an rString. Returns true if it is
    Parameters:
        None
    Effects:
        None:
*/
bool RPNCalc::rStringCheck() {
    if (!emptyStackCheck()) { // if stack empty return false
        return false;
    }
    string element = stack.top();
    string elementString = element;
    istringstream iss(elementString); //turn string into istringstream
    string firstChar;
    iss >> firstChar;
    // now check if first character of isstream is {
    if (firstChar == "{") {
        return true;
    }
    return false;
}

  /* boolInverse function which pops a boolean from the top of the
  stack and
  return the boolean inverse
      Parameters:
          None
  */
void RPNCalc::boolInverse() {
    string element1 = stack.top();
    stack.pop();
    // if top element is true return false
    if (element1 == "true") {
        string element2 = "false";
        stack.push(element2);
    }
    // else return true
    else {
        string element2 = "true";
        stack.push(element2);
    }
}

/* swap function which swaps the values of the top two elements of
the stack
    Parameters:
        None
*/
void RPNCalc::swap() {
    string element1 = stack.top();
    stack.pop();
    string element2 = stack.top();
    stack.pop();
    stack.push(element1);
    stack.push(element2);
}

/* mathOperator function which takes in a string containing a math
operator and applies the operator to the top two elements of the
stack
    Parameters:
        input: string which contains an operator
*/
void RPNCalc::mathOperator(string input) {
     string element1 = stack.top();
     stack.pop();
     string element2 = stack.top();
     stack.pop();
     int value1,value2,result;
     got_int(element1,&value1); // transforms string into int
     got_int(element2,&value2);
     if (input == "+") { // do operation based on input
         result = value2 + value1;
     }
     else if (input == "-") {
         result = value2 - value1;
     }
     else if (input == "*") {
         result = value2 * value1;
     }
     else if (input == "/") {
         result = value2 / value1;
     }
     else {
         result = value2 % value1;
     }

     stack.push(to_string(result)); // push result of operation
  }

  /* equality function which takes in a string containing a math
  equality and applies the operator to the top two elements of the
  stack
      Parameters:
          input: string containing equality
  */
void RPNCalc::equality(string input) {
    string element1 = stack.top();
    stack.pop();
    string element2 = stack.top();
    stack.pop();
    int value1,value2;
    bool result;
    got_int(element1,&value1); //transform strings into ints
    got_int(element2,&value2);
    if (input == "<") { // do operation based on input
        result = value2 < value1;
    }
    else if (input == ">") {
        result = value2 > value1;
    }
    else if (input == "<=") {
        result = value2 <= value1;
    }
    else if (input == ">=") {
        result = value2 >= value1;
    }
    else {
        result = value2 == value1;
    }

    string element;
    if (result) {
        element = "true";
    }
    else {
        element = "false";
    }
    stack.push(element); //push result of operation
}

/* execute function which pops the top element from the stack, an rstring, and
executes its commands
    Parameters:
        None
*/
void RPNCalc::execute() {
    string element = stack.top();
    stack.pop();
    string element2 = "a"; // initialize with placeholder value
    string commands = element;
    istringstream iss(commands); //turn rstring into isstream to read in
    string command;
    iss >> command; // skip first opening curly bracket
    while (!iss.eof()) {
    iss >> command;
        if (command == "{") { // if rstring, push it to the stack
            element2 = parseRString(iss,true);
            if (element2 != "error") {
                stack.push(element2);
            }
        }
        else if (command != "}"){
            run(command);
        }
    }
}

/* getFilename function which pops top element from stack, an rstring
containing a filename and returning it
    Parameters:
        None
*/
string RPNCalc::getFilename() {
     string element = stack.top();
     stack.pop();
    string filenameRString = element;
    istringstream iss(filenameRString);
    string filename;
    iss >> filename; // skip opening curly bracket
    iss >> filename; // read in filename
    return filename;
}

/* readFile function which pops the top element from the stack, an rstring
containing a filename, reads in the file, and executes the commands.
    Parameters:
        None
*/
void RPNCalc::readFile() {
    string filename = getFilename(); //get filename
    string commands;
    ifstream infile;
    infile.open(filename);
    if (infile.fail()) { //if error reading, cerr error
        cerr << "Unable to read " << filename << endl;
        return;
    }
    else {
        while (infile >> commands) {
            if (commands == "{") { //if rstring, run it
                string parsedString = parseRString(infile,false);
                istringstream iss3(parsedString);
                run(iss3,true);
                string placeholder;
                while (iss3 >> placeholder) {
                    infile >> commands;
                }
            }
            else if (commands != "}") {
                run(commands);
                }
            }
        }
    infile.close();
}

/* ifConditionTrueCase function which executes the trueCase rstring in the
ifCondition function
    Parameters:
        trueCase: rstring converted to string containing commands
*/
void RPNCalc::ifConditionTrueCase(string trueCase) {
    istringstream iss(trueCase);
    string commands;
    iss >> commands;
    while (iss >> commands) { // read in
        if (commands == "{") {
            string parsedString = parseRString(iss,true);
            istringstream iss3(parsedString);
            string elementToPush = parsedString;
            stack.push(elementToPush);
            execute();
            string placeholder;
            while (iss3 >> placeholder) {
                iss >> commands;
            }
        }
        else if (commands != "}") {
            run(commands);
            }
        }
}

/* ifConditionFalseCase function which executes the falseCase rstring in the
ifCondition function
    Parameters:
        falseCase: rstring converted to string containing commands
*/
void RPNCalc::ifConditionFalseCase(string falseCase) {
    istringstream iss(falseCase);
    string commands;
    iss >> commands;
    int count = 1;
    while (iss >> commands) { // read in string until end
        if (commands == "{") {
            string parsedString = parseRString(iss,true);
            istringstream iss2(parsedString);
            run(iss2,true);
            istringstream iss3(parsedString);
            string placeholder;
            iss.clear(); //clears isstream and resets it
            istringstream iss4(falseCase);
            while (iss3 >> placeholder) { //skips until end of rstring
                iss4 >> commands;
            }
            for (int i = 0; i < count; i++) {
                iss4 >> commands;
            }
            while (iss4 >> commands) { //now continues reading
                if (commands != "}") {
                    run(commands);
                }
            }
        }
        else if (commands != "}") {
            run(commands);
            }
            count++;
        }
}

/* ifCondition function which execute different commands based
on bool statements.
    Parameters:
        None
    Effects:
    Cerrs error if type data doesn't match
*/
void RPNCalc::ifCondition() {
    string testCondition = "true"; // placeholder values for variables
    string falseCase = "a";
    string trueCase = "a";
    //first checking for correct data values
    if (!rStringCheck()) {
        cerr << "Error: exepcted rstring in if branch" << endl;
        stack.pop();
        return;
    }
    else {
        falseCase = stack.top();
        stack.pop();
    }
    if (!rStringCheck()) {
        cerr << "Error: exepcted rstring in if branch" << endl;
        stack.pop();
        return;
    }
    else {
        trueCase = stack.top();
        stack.pop();
    }
    if (stack.top() != "true" && stack.top() != "false") {
        cerr << "Error: expected boolean in if test" << endl;
        stack.pop();
    }
    else {
        testCondition = stack.top();
        stack.pop();
    }
    // once data type matches run either true or false case.
    if (testCondition == "true") {
        ifConditionTrueCase(trueCase);
    }
    else {
        ifConditionFalseCase(falseCase);
    }
}

/* parseFromCin function which parses an rstring from cin input
    Parameters:
        input: reference to an istream, to be read in by the function
        curly_braces_open: reference to int
*/
string RPNCalc::parseFromCin(istream &input, int &curly_braces_open) {
    string element = "{"; // placeholder value
    string addition = "a"; //placeholder value
    string userInput;
    getline(input,userInput);
    istringstream iss(userInput);
    while (iss >> addition) {
       if (addition == "}") {
           curly_braces_open--;
       }
       else if (addition == "{") {
           curly_braces_open++;
       }
       element += " ";
       element += addition;
       if (curly_braces_open == 0) { // if reached closing curly bracket, end
           break;
        }
    }
    return element;
}

/* parseFromFile function which parses an rstring from file input
    Parameters:
        input: reference to an istream, to be read in by the function
        curly_braces_open: reference to int
*/
string RPNCalc::parseFromFile(istream &input, int &curly_braces_open) {
    string element = "{"; // placeholder value
    string addition = "a"; //placeholder value
    string userInput;
    getline(input,userInput);
    while (!input.eof()) { // read until end of file
       istringstream iss(userInput);
       while (iss >> addition) { // read until end of line
       if (addition == "}") {
           curly_braces_open--;
       }
       else if (addition == "{") {
           curly_braces_open++;
       }
       element += " ";
       element += addition;
   }
       if (curly_braces_open == 0) { // if reached closing curly bracket, end
           break;
       }
       getline(input,userInput);
   }
   return element;
}

/* parseRString function which reads in an input and returns everything it
reads in as a string, in between curly braces.
    Parameters:
        input: reference to an istream, to be read in by the function
        inputType: true if input is cin
    Effects: Returns string "error" if it reaches end of input without finding
    corresponding closing curly braces and cerrs error message.
*/

string RPNCalc::parseRString(istream &input,bool inputType) {
    string element;
    int curly_braces_open = 1; //counts num of open curly braces
    // Reads in input until it reaches final matching } or end of input
    string userInput;
    if (inputType) {
        element = parseFromCin(input,curly_braces_open);
    }
    else {
        element = parseFromFile(input,curly_braces_open);
    }
   // if function reaches final matching }, return result
   if (curly_braces_open == 0) {
       return element;
   }
   else { // if function does not reach final matching }, cerr error.
       cerr << ("Error: no final matching '}' found") << endl;
       return "error";
   }
}

  /* run function. Main run function that runs while calculator is
  being used.
      Parameters:
          input: reference to istream to take commands from
          inputType: true of input is cin
  */
 void  RPNCalc::run(istream &input, bool inputType) {
    string command = "t";
    while (input >> command) {
        int value;
        if (got_int(command,&value)) {
            string element = to_string(value);
            stack.push(element);
        }
        else if (command == "#t") {
            string element = "true";
            stack.push(element);
        }
        else if (command == "#f") {
            string element = "false";
            stack.push(element);
        }
        else if (command == "not") {
            if (emptyStackCheck() && booleanCheck()) {
            boolInverse();
            }
        }
        else if (command == "print") {
            if (emptyStackCheck()) {
            cout << stack.top() << endl;
            }
        }
        else if (command == "clear") {
            stack.clear();
        }
        else if (command == "drop") {
            if (emptyStackCheck()) {
            stack.pop();
            }
        }
        else if (command == "dup") {
            if (emptyStackCheck()) {
            string element = stack.top();
            stack.push(element);
            }
        }
        else if (command == "swap") {
            if (emptyStackCheck2()) {
            swap();
            }
        }
        else if (command == "+" || command == "-" || command == "*" \
        || command == "/" || command == "mod") {
            if (emptyStackCheck2() && intCheck()) {
            mathOperator(command);
            }
        }
        else if (command == "<" || command == ">" || command == "<=" || command == ">=" || command == "==") {
            if (emptyStackCheck2() && intCheck()) {
            equality(command);
            }
        }
        else if (command == "{") {
            string element = parseRString(input,inputType);
            if (element != "error") {
                stack.push(element);
            }
        }
        else if (command == "exec") { // first check for empty stack and rstring
            if (emptyStackCheck() && rStringCheck()) {
                execute();
            }
            else {
                cerr << "Error: cannot execute non rstring" << endl;
            }
        }
        else if (command == "file") {
            if (rStringCheck()) {
                readFile();
            }
            else {
                cerr << "Error: file operand not rstring" << endl;
            }
        }
        else if (command == "if") {
            ifCondition();
        }
        else if (command == "quit") {
            cerr << "Thank you for using this RPN Calculator.\n";
            return;
        }
        else {
            cerr << command << ": unimplemented" << endl;
        }
    }
}

/* overloaded run function. Main run function that takes in
a string and processes it
    Parameters:
        command: type string
*/
void  RPNCalc::run(string command) {
       int value;
       if (got_int(command,&value)) {
           string element = to_string(value);
           stack.push(element);
       }
       else if (command == "#t") {
           string element = "true";
           stack.push(element);
       }
       else if (command == "#f") {
           string element = "false";
           stack.push(element);
       }
       else if (command == "not") {
           if (emptyStackCheck() && booleanCheck()) {
           boolInverse();
           }
       }
       else if (command == "print") {
           if (emptyStackCheck()) {
           cout << stack.top() << endl;
           }
       }
       else if (command == "clear") {
           stack.clear();
       }
       else if (command == "drop") {
           if (emptyStackCheck()) {
           stack.pop();
           }
       }
       else if (command == "dup") {
           if (emptyStackCheck()) {
           string element = stack.top();
           stack.push(element);
           }
       }
       else if (command == "swap") {
           if (emptyStackCheck2()) {
           swap();
           }
       }
       else if (command == "+" || command == "-" || command == "*" \
       || command == "/" || command == "mod") {
           if (emptyStackCheck2() && intCheck()) {
           mathOperator(command);
       }
       }
       else if (command == "<" || command == ">" || command == "<=" || command == ">=" || command == "==") {
           if (emptyStackCheck2() && intCheck()) {
           equality(command);
       }
       }
       else if (command == "{") {
           istringstream iss(command);
           string element = parseRString(iss,true);
           if (element != "error") {
               stack.push(element);
           }
       }
       else if (command == "exec") {
           if (rStringCheck()) {
               execute();
           }
           else {
               cerr << "Error: cannot execute non rstring" << endl;
           }
       }
       else if (command == "file") {
           if (rStringCheck()) {
               readFile();
           }
           else {
               cerr << "Error: file operand not rstring" << endl;
           }
       }
       else if (command == "if") {
           ifCondition();
       }
       else if (command == "quit") {
           cerr << "Thank you for using this RPN Calculator.\n";
           return;
       }
       else {
           cerr << command << ": unimplemented" << endl;
       }
}
