#include <iostream>
#include <utility> //For std::move

#include "Test.h"

int main() {

    Test test1{123,12,31,2,3,1213};
    Test test2 = test1;
    Test test3 = std::move(test2); //Move Ctor   test2 now an empty object, must delete it
    test3 = std::move(test1); //Move assignment  test1 now an empty object, must delete it

}