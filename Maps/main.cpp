#include <iostream>
#include <map>
//Header of pairs (will be included by map however)
#include <utility>

int main(){
    //associative container / dictionary. Sorts any object (in a binary tree for fast access) that defines < operator
    //Keys must be unique like in a set
    std::map<std::string, int> ages;

    //This is actually two separate operations: 1. heights["Rob"] initialises a new pair in map will default .second item
    //2. = 15 assigns the .second item in the pair (which was returned by [] operator) to 15
    //Therefore, whenever we attempt to access map elements in this way, if an element doesnt exist, it will be added
    ages["Rob"] = 15;
    ages["Greg"] = 12;
    ages["Jerry"] = 19;

    //In order to check if an item exists before we decide to access it, we can use map::find() e.g.
    std::map<std::string, int>::iterator checkItem = ages.find("Rob");
    if(checkItem != ages.end()){
        std::cout << "ITEM EXISTS" << std::endl;
        std::cout << "Key: " << checkItem->first << " --- Value: "<< checkItem->second << "\n" << std::endl;
    }else{
        std::cout << "Item does not exist\n" << std::endl;
    }

    //When you use "map[key] = value" you cannot tell whether you initialised an element, or simply changed an element
    //To solve this problem, you could use map::insert or map::emplace. If an element with the specified key already exists
    //It is not changed ---- PS: make_pair(x,y) inits and returns a pair
    #if 0 //emplace introduced in c++11 avoids unnecessary copy of object (as it uses args to init the obj)
        ages.insert(std::make_pair("Harry", 23));
    #endif
    ages.emplace("Harry", 23);
    ages.emplace("Harry", 21); //Wont change value



    //You can also iterate through a map using iterators (probably some tree traversal implementation) e.g.
    std::cout << "Traversing map:" << std::endl;
    for(auto it = ages.begin(); it != ages.end(); it++){
        //Notice, it is automatically sorted by key
        std::cout << "Key: " << it->first << " --- Value: " << it->second << std::endl;
    }
}
