#include <iostream>
#include <vector>
#include <algorithm>

#include "maths.h"

int main() {
    //// FUNCTION PTR
    //A function is simply an address to a set of instructions, so you do not need to specify & when defining a ptr to function
    double (*addPtr) (double, double) = maths::add;
    //This also means you don't need to dereference a fPtr when using it
    std::cout << "32 + 5 = " << maths::binOperation(32, 5, addPtr) << std::endl;


    //Using function pointers in std function (std::count_if())
    std::vector<double> numbers = {4.0, 6.4, -43.1};
    //Last param is a bool function ptr
    long numMoreThanZero = std::count_if(numbers.begin(), numbers.end(), maths::moreThanZero);
    std::cout << "\nNumber more than zero: " << numMoreThanZero << std::endl;




    return 0;
}