###
### Makefile for RPNCalc Project
### RPNCalc is an RPN calculator
###
### Author:  Theo Dayton

CXX      = g++
CXXFLAGS = -g3  -std=c++11 -Wall -Wextra  -Wpedantic -Wshadow
LDFLAGS  = -g3


INCLUDES = $(shell echo *.h)
EXECS    = RPNCalc

RPNCalc:	main.o	RPNCalc.o	StringStack.o
	${CXX} ${CXXFLAGS}	-o	RPNCalc	main.o	RPNCalc.o	StringStack.o

testStringStack:	StringStack.o	testStringStack.o
	${CXX} ${CXXFLAGS}	-o	testStringStack	StringStack.o	testStringStack.o

StringStack.o:	StringStack.cpp
RPNCalc.o:	RPNCalc.cpp StringStack.h
main.o:	RPNCalc.h StringStack.h
testStringStack.o: testStringStack.cpp StringStack.h

%.o: %.cpp ${INCLUDES}
	${CXX} ${CXXFLAGS} -c -o $@ $<

%.cylc:  %.cyl
	./cylc $^
