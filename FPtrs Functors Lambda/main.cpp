#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

#include "maths.h"
#include "MyFunctor.h"


//Functors, lambdas, and function ptrs can be passed to a function using std::function as a parameter.
void printStuff(const std::string &str, int x, const std::function<int(int)> &func){
    std::cout << str << func(x) << std::endl;
}


void useFPtr(std::string (*fPtr)(std::string) ){
    std::cout << fPtr("Clapped") << std::endl;
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
    long numMoreThanZero = std::count_if(numbers.begin(), numbers.end(), maths::moreThanZero); //Unary predicate
    std::cout << "Number more than zero: " << numMoreThanZero << std::endl;



    //// FUNCTOR

    std::cout << "\nFunctors" << std::endl;

    //Sets x var in ftor to ten (state var).... When the functor is "Called" it will add 10 (x) to y (whatever is in the parenthesis)
    MyFunctor ftor(10);

    printStuff("The functor addition results in: ", 5,  ftor); //Will do 5 + 10 (15)

    //// LAMBDA

    std::cout << "\nLambda Expressions" << std::endl;


    //There are 3 parts to a lambda:
        //1: [] The capture list
        //2: () The params
        //3: {} The code

    //The most simple lambda that instantly calls itself (does nothing)
    [](){}();

    //A lambda is essentially a functor created using a fancy syntactic sugar, however when a lambda captures nothing, it evaluates to a function pointer:
    //Passing vars through the [] capture list is essentially the same as passing vars through the ctor of a functor
    useFPtr([] (std::string x) {return x + " GUVNA";});//As you may notice, the return type is deduces implicitly by the compiler
    auto lam = [=] (std::string x) {return x;}; // Simply use auto. Its very hard to deduce the complex type of a lambda. Typing is not consistent.


    //As a lambda is actually a complex functor type under the hood, it can be passed as a std::function e.g.
    double x = 5.0;
    //Can capture a var in capture list. Acts much like a member variable in a functor
    long numMoreThanX = std::count_if(numbers.begin(), numbers.end(),  [x] (double y) {return y > x;}  ); //std::count_if uses std::function as a param. Lambdas can be passed as a std::function
    std::cout << "Number more than X: " << numMoreThanX << std::endl;

    //If you you use = or & first in the capture list e.g. [=](){} or [&](){}  it will capture all local symbols by value or reference
    //You can also pass all except x by value or all but y by ref e.g. [=, &x] [&, y]
    //Additionally, since a lambda is an class in itself, it does not have access to private variables, therefore, if you want to access the current objects local variables you must capture "this"
    //e.g. [this](){}  This captures member in the class by reference (as this is a pointer / location to the actual object)
    //Since you cant simultaneously catch all by value and by ref, you cant do [this, =] just ast you cant do [&, =];

    return 0;
}


#if 0
struct Printer{
    Printer(std::string x):x(x){

    }

    template <class T>
    void operator()(T t){
        std::cout << t << " --- " << x << std::endl;
    }

private:
    std::string x;
};
#endif ///Just a lil test