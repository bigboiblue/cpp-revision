//
// Created by kyle on 04/03/19.
//

#pragma once

#include <iostream>
#include <string>

//Additionally, when you mark a class as a friend e.g.
/*
 * class someClass{
 *      friend otherClass
 * }
 *
 */ // All function in otherClass will be friend functions of someClass

//Must prototype func as static beforehand as usually friend implies external linkage
class SomeClass;
void static friendPrintString(const SomeClass &someClass);

class SomeClass {
public:
    SomeClass() = delete;

    SomeClass(const std::string &str);

    void printString();
    friend void friendPrintString(const SomeClass &someClass);

private:
    std::string str;

};


//Friend function does not need friend declaration. Function has access to all private members (still need to pass the object however)
//Must be static or inline to avoid redefinition (it extern by default) after this has been defined once, it will be available to all other translation units.
//We dont need to compile headers as the code is effectively included / pasted into the cpps. If you include a function definition in a .h that is already globally known / defined
//You are redefining it which causes an error. (However, if its not static, although its been defined before elsewhere, this translation unit doesnt know about it).
void static friendPrintString(const SomeClass &someClass) {
    std::cout << "Printing friend string: " << someClass.str << std::endl;
}

//Additionally, inline just compiles as if there were no functions. The code inside the function essentially replaces any function calls.

//To avoid all this just put definitions in the source file. Its only compiled once, and is never included, so this always works