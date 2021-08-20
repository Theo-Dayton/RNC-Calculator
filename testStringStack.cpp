/*
 *
 *
 *  StringStack.cpp
 *
 *   *  Driver containing main function, which is used to unit test the StringStack class and its functions
 *
 *  Written on: 10/12/2020
 */

#include <iostream>
#include <vector>

using namespace std;

#include "StringStack.h"

int main() {
    string element = "15";
    StringStack stack;
    stack.push(element);
    cout << stack.top() << endl; //test push and top functions
    stack.clear();
    /*cout << stack.top() << endl; //test clear function and throwing runtime_error when calling top on empty stack */
    element = "30";
    stack.push(element);
    cout << stack.top() << endl;

    return 0;
}
