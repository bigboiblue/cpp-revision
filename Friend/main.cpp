#include <iostream>

#include "SomeClass.h"


int main() {
    SomeClass someClass("My name is BIG NATE");

    //Print string using member function (which has access to private members)
    someClass.printString();
    //Print string using friend function outside of class
    friendPrintString(someClass);

    return 0;
}