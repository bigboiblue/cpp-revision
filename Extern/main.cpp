#include <iostream>


//Good practice to place all extern global vars into a separate header file
//and include the file where needed
#include "global_vars.hpp"
#include "global_functions.hpp"


//defining the global var. Global var must only be defined once
//g_naming convention for global symbols
int g_number = 17;

int main(){


    //manipulate global var
    g_changeNumber();


    //test to show it != 17
    std::cout << "Global var = " << g_number << std::endl;

    return 0;
}
