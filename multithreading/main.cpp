#include <iostream>
#include <thread> //SEE CMAKELISTS.TXT : Using <thread> on linux requires you to link pthread library (POSIX Thread)
#include <chrono>


#if 0 //Not used
void printStringLoop(const std::string &x){
    while(true){
        std::cout << x << "\r" << std::flush;
        std::this_thread::yield();
    }
}
#endif

int main(){

    std::cout << "Strange things are about to happen as a result of multithreading..." << std::endl;
    std::cout << "Num of threads in this system: " << std::thread::hardware_concurrency() << std::endl;
    //std::this_thread:: is a namespace that includes functions referring to the current thread:
    //e.g. sleep_for(chrono secs, chrono nano), yield(), get_id(), sleep_until(chrono time_point)
    std::this_thread::__sleep_for(std::chrono::seconds(1), std::chrono::nanoseconds(0));

#if 0 //First arg is an std::function (allows fPtrs, functors and lambdas), other args are the args you pass into the
    std::thread t1(printStringLoop, "What is happening?");
#endif


    std::thread t1( [](std::string x){while(1){std::cout << x << '\r' << std::flush; std::this_thread::yield();}} , "What is happening!?");


    while(1){
        std::cout << "OH JEEEEEEEEEEEZ" << "\r" << std::flush;
        //(this will stop execution of current thread and give priority of execution to other threads momentarily
        std::this_thread::yield();
    }

    //this halts the current threads execution to wait for execution to finish in the t1 thread.
    t1.join();

    return 0;
}