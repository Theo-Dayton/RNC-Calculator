/*
 *
 *  StringStack.h
 *
 *   *  Interface of StringStack class, which includes key information \
 regarding the StringStack class.
 *
 *  Written on: 10/12/2020
 */

#ifndef _STRINGSTACK_H_
#define _STRINGSTACK_H_


#include <iostream>
#include <vector>


using namespace std;

class StringStack

{
public:
    StringStack();
    StringStack(string* array,int size);

    bool isEmpty();
    void clear();
    int size();
    string top();
    void pop();
    void push(string element);
private:
    vector<string> stack;
};

#endif
