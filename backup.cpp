string RPNCalc::parseFromCin(istream &input, int &curly_braces_open) {
    string element = "{";
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
       if (curly_braces_open == 0) {
           break;
        }
    }
    return element;
}

string RPNCalc::parseFromFile(istream &input, int &curly_braces_open) {
    string element = "{";
    string addition = "a"; //placeholder value
    string userInput;
    getline(input,userInput);
    while (!input.eof()) {
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
   }
       if (curly_braces_open == 0) {
           break;
       }
       getline(input,userInput);
   }
   return element;
}

/* parseRString function which reads in an input and returns everything it reads in as a string, in between curly braces
    Parameters:
        input: reference to an istream, to be read in by the function
        inputType: true if input is cin
    Effects: Returns error if it reaches end of input without finding corresponding closing curly braces
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
