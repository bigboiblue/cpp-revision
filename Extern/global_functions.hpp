#ifndef GLOBAL_FUNCTIONS
#define GLOBAL_FUNCTIONS 1

#include "global_vars.hpp"

//extern keyword is redundant here. Functions are extern by default. Done for consistency
extern void g_changeNumber(){
    g_number = 69;
}

#endif
