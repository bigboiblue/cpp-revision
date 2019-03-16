#include <iostream>
#include <chrono> //Also includes #include <ratio>


int main() {

    //There are different types of clock e.g. system_clock, high_resolution_clock, steady_clock
    typedef std::chrono::system_clock clock;

    //time_point can hold num of ticks returned by clock::now();
    //2 template params <clock, tick period = clock::duration> <--- As you can see, 2nd param is tick period, which defaults to the clocks tick period you passed.
    //We dont know the clocks tick period, as it is platform / hardware specific, therefore we mostly just use one param.
    std::chrono::time_point<clock> x = clock::now();


    for(int i = 0; i < 100000; i++){
        std::cout << "You wot m8\r";
    }

    std::chrono::time_point<clock> y = clock::now();

    //std::milli is a typedef for std::ratio<1, 1000> <--- for every 1 second, there is 1000 milliseconds. I could use std::ratio<1,1000> here.
    //This is included in #include ratio (which is included in chrono).                  //std::chrono::milliseconds is an alias for std::chrono::duration< long, std::milli>
    std::chrono::duration< double, std::milli > dif     =     std::chrono::duration_cast<std::chrono::duration< double, std::milli> >(y-x);
#if 0 //I could just use a duration cast and auto here instead. The effect is the same.
    auto dif = std::chrono::duration_cast<std::chrono::duration<double, std::milli >(y-x);
#endif

    //counts type is controlled by first template param, here its a long. Count displays number of ticks with given tick period
    std::cout << "Execution time of loop: " << dif.count() << "ms" << std::endl;



    return 0;
}