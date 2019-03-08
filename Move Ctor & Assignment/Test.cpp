//
// Created by kyle on 07/03/19.
//

#include "Test.h"

#include <iostream>


//Param Ctor
Test::Test(std::initializer_list<const int> iList)
:nums(new std::vector<int>)
{
    std::cout << "Parameterized Ctor Called" << std::endl;
    for(const int &x: iList){
        nums->emplace_back(x);
    }
}

//Copy Ctor
Test::Test(const Test &other)
:nums(new std::vector<int>(*(other.nums)))
{
    std::cout << "Copy Ctor Called" << std::endl;
}

//Move Ctor
Test::Test(Test &&other) noexcept
:nums(other.nums) //Steal location of other's members
{
    std::cout << "Move Ctor Called" << std::endl;
    other.nums = nullptr; //When other calls destructor to destroy object pointed to, it wont do anything, as it now points to nullptr
}


//Assignment overload
Test &Test::operator=(const Test &other) {
    std::cout << "Copy Assignment Called" << std::endl;
    delete nums; //Cant just not delete prior objects. Not deleting will cause mem leak
    nums =(new std::vector<int>(*(other.nums)));

    return *this;
}

//Move assignment overload
Test &Test::operator=(Test &&other) noexcept {
    std::cout << "Move Assignment Called" << std::endl;
    delete nums; //Cant just not delete prior objects. Not deleting will cause mem leak
    nums = other.nums; //Steal location of other's members
    other.nums = nullptr; //When other calls destructor to destroy object pointed to, it wont do anything, as it now points to nullptr

    return *this;
}


//Dtor
Test::~Test() {
    std::cout << "Dtor called" << std::endl;
    delete nums;
}
