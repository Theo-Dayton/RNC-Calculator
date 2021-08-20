/*
 *
 *  StringStack.cpp
 *
 *   *  Implementation of StringStack class, which includes key functions regarding the StringStack, such as the default constructor, readFile, print function, and other funcionts used in the stack.
 *
 *  Written on: 10/12/2020
 */
 #include <iostream>
 #include <vector>

 #include "StringStack.h"

 /* default constructor. The class uses a vector constructor so this function is empty
     Parameters:
         None
 */
StringStack::StringStack() {

}

/* Overloaded constructor
    Parameters:
        array: string pointer that points to an array of strings
        size: int equal to size of array that is being pointed to
*/
StringStack::StringStack(string* array,int size) {
    for (int i = 0; i < size; i ++) {
        stack.push_back(array[i]);
    }
}

/* isEmpty function: returns true if a function is empty, false if otherwise
    Parameters:
        None
*/
bool StringStack::isEmpty() {
    return stack.empty();
}

/* clear functions which clears the current stack of all elements
    Parameters:
        None
*/
void StringStack::clear() {
    stack.clear();
}

/* size functions which returns an int equal to the size of the stack
    Parameters:
        None
*/
int StringStack::size() {
    return stack.size();
}

/* top functions which returns the top element of the stack as a string type
    Parameters:
        None
    Effects: thors a runtime error if stack is empty
*/
string StringStack::top() {
    if (size() == 0) {
        throw std::runtime_error ("empty_stack");
    }
    return stack.back();
}

/* pop function which removes the top element from the stack
    Parameters:
        None
    Effects: thors a runtime error if stack is empty
*/
void StringStack::pop() {
    if (size() == 0) {
        throw std::runtime_error ("empty_stack");
    }
    stack.pop_back();
}

/* push function which adds an element of type string to the top of the stack
    Parameters:
        element: Data of type string to be pushed onto stack
*/
void StringStack::push(string element) {
    stack.push_back(element);
}
