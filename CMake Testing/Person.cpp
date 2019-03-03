#include "Person.hpp"

#include <iostream>

int Person::numObjects = 0;

Person::Person(std::string name)
:pid(++Person::numObjects){
    std::cout << "Parameterised Ctor Called" << std::endl;
}

//Copy Ctor as we want a new pid
Person::Person(const Person &other)
:pid(++Person::numObjects){
    std::cout << "Copy Ctor Called" << std::endl;

    name = other.name;
}

//Overloading = operator as we dont want to copy pid
const Person &Person::operator=(const Person &other){
    std::cout << "Overloaded = Operator Called" << std::endl;

    name = other.name;
    return *this;
}

void Person::printInfo(){
    std::cout << "PID: " << pid << " --- Name: " << name << std::endl;
}
