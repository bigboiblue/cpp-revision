#include <iostream>
#include <list>

int main(){
    //linked list (no random access, must use iterators)
    std::list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(5);

    //Can push to the front of the list
    numbers.push_front(0);

    //std::next returns the iterator (in first arg) incremented by the num times in the second arg
    auto space4 = std::next(numbers.begin(), 4);
    numbers.emplace(space4, 4);

    #if 0 //Cannot do random access
    std::cout << space4[3] << std::endl;
    #endif

    //Must use iterators in for loop
    for(auto i = numbers.begin(); i != numbers.end(); i++){
        std::cout << *i << ", ";
    }
    std::cout << std::flush;


    //std::distance(x,y) returns an int giving the number of times you must increment x to get to y (iterator)
    std::cout << "\nDistance between begin and end = " << std::distance(numbers.begin(), numbers.end()) << std::endl;

}
