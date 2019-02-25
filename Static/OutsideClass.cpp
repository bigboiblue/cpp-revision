#include "OutsideClass.hpp"

#include <iostream>

static int staticNumber = 50;

//define extern function declated in OutsideClass.hpp
//g_naming convention for global symbols
void g_printStatic(){
    std::cout << "staticNumber = " << staticNumber << std::endl;
}
