//
// Created by kyle on 05/03/19.
//

#include "SomeClass.h"


SomeClass::SomeClass(const std::string &str)
: str(str){

}

void SomeClass::printString() {
    std::cout << "Printing normal string: " << str << std::endl;
}
