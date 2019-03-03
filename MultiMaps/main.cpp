#include <iostream>
#include <map>

int main(){

    std::multimap<std::string, float> heights;
    #if 0 //No random access, as may be more than one value with a given key. Use emplace or insert instead
        heights["Jerry"] = 12.5f;
    #endif

    heights.emplace("Jerry", 12.5f);
    heights.emplace("Jerry", 3122.2f);
    heights.emplace("Jerry", 5.1f);
    heights.emplace("Greg", 9923.1f);
    heights.emplace("Harry", 0.1f);

    //multimap::find(x) only finds the first occurance of a key.
    //multimap::equal_range(x) returns a std::pair of iterators to first and last element with the given key
    std::cout << "Elements equal to Jerry:" << std::endl;
    auto its = heights.equal_range("Jerry");
    if(std::distance(its.first, its.second) > 0){
        do{
            std::cout << "Key: " << its.first->first << " --- Value: " << its.first->second << std::endl;
        }while(++its.first != its.second);
    }else{
        std::cout << "None found" << std::endl;
    }
    //Also a count(x) function


    //Same traversal
    std::cout << "\nAll elements: " << std::endl;
    //Still sorts based on key
    for(auto it = heights.begin(); it != heights.end(); it++){
        std::cout << "Key: " << it->first << " --- Value: " << it->second << std::endl;
    }

}
