/*
 *
 *
 *  RPNCalc.h
 *
 *   *  Interface of RPNCalc class, which includes key information \
 regarding the RPNCalc class.
 *
 *  Written on: 10/20/2020
 */

#ifndef _RPNCALC_H_
#define _RPNCALC_H_


#include <iostream>
#include <vector>
#include "StringStack.h"
#include "RPNCalc.h"


using namespace std;

class RPNCalc

{
public:
    RPNCalc();
    ~RPNCalc();

    void run(istream &input,bool inputType);
    void run(string command);
private:
    StringStack stack;
    bool emptyStackCheck();
    bool emptyStackCheck2();
    bool intCheck();
    bool booleanCheck();
    bool rStringCheck();
    void boolInverse();
    void swap();
    void mathOperator(string input);
    void equality(string input);
    void execute();
    void readFile();
    string getFilename();
    void ifCondition();
    void ifConditionTrueCase(string trueCase);
    void ifConditionFalseCase(string falseCase);
    string parseRString(istream &input,bool inputType);
    string parseFromCin(istream &input, int &curly_braces_open);
    string parseFromFile(istream &input, int &curly_braces_open);
};

#endif
