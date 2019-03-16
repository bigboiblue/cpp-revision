#include "ExampleClass.hpp"

#include <iostream>

//Access static symbols inside a class using :: (scope resolution) operator
//Must initialise static symbols outside class or function definitions, as they have static duration
int ExampleClass::numOfObjects = 0;


ExampleClass::ExampleClass(){
    ExampleClass::numOfObjects++;
}

ExampleClass::ExampleClass(const ExampleClass &other){
    ExampleClass::numOfObjects++;
}

void ExampleClass::printNumOfObjects(){
    std::cout << "Number of ExampleClass objects = " <<numOfObjects << std::endl;
}

//Member functions can access static symbols however:
void ExampleClass::tryToAccessStatic(){
    std::cout << ExampleClass::numOfObjects << std::endl;
}
