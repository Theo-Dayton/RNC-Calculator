/*
 *  parser.cpp
 *
 *   *  Contains one function called parseRString which takes an istream reference  as a parameter.
 *
 *  Written on: 10/12/2020
 */


 #include <iostream>
 #include <vector>

 using namespace std;

 /* parseRString function which reads in an input and returns everything it reads in as a string, in between curly braces
     Parameters:
         input: reference to an istream, to be read in by the functio
     Effects: Returns error if it reaches end of input without finding corresponding closing curly braces
 */

string parseRString(istream &input) {
    string element = "{";
    string addition = "a"; //placeholder value
    int curly_braces_open = 1; //counts num of open curly braces
     // Reads in input until it reaches final matching } or end of input
    while (curly_braces_open != 0 && !input.eof()) {
        input >> addition;
        if (addition == "}") {
            curly_braces_open--;
        }
        else if (addition == "{") {
            curly_braces_open++;
        }
        element += " ";
        element += addition;
    }
    // if function reaches final matching }, return result
    if (addition == "}" && curly_braces_open == 0) {
        return element;
    }
    else { // if function does not reach final matching }, return error.
        throw std::runtime_error ("no final matching '}' found");
    }
}

int main() {

    return 0;
}
