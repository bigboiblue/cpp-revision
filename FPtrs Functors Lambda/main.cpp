#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

#include "maths.h"
#include "MyFunctor.h"


//Functors, lambdas, and function ptrs can be passed to a function using std::function as a parameter.
void printStuff(std::string str, std::function<int(int)> func){
    std::cout << str << func(5) << std::endl;
}



int main() {


    //// FUNCTION PTR

    std::cout << "Function pointers" << std::endl;

    //A function is simply an address to a set of instructions, so you do not need to specify & when defining a ptr to function
    double (*addPtr) (double, double) = maths::add;
    //This also means you don't need to dereference a fPtr when using it
    std::cout << "32 + 5 = " << maths::binOperation(32, 5, addPtr) << std::endl;


    //Using function pointers in std function (std::count_if())
    std::vector<double> numbers = {4.0, 6.4, -43.1};
    //Last param is a bool function ptr
    long numMoreThanZero = std::count_if(numbers.begin(), numbers.end(), maths::moreThanZero);
    std::cout << "\nNumber more than zero: " << numMoreThanZero << std::endl;



    //// FUNCTOR

    //Sets x var in ftor to ten (state var).... When the functor is "Called" it will add 10 (x) to y (whatever is in the parenthesis)
    MyFunctor ftor(10);

    printStuff("The functor addition results in: ", ftor); //Will do 5 + 10 (15)

    //// LAMBDA




    return 0;
}