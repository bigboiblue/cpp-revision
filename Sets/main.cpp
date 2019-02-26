#include <iostream>
#include <set>

int main(){

    //A map is like an implementation of a set using std::pair
    //Sometimes an objects value can be aggregated into the key (so long as < operator defined)
    //This means map can be kind of redundant, though it saves time
    std::set<int> ids;

    //[] operator not overloaded, as there are no values to access
    ids.emplace(4);
    ids.emplace(2);
    ids.emplace(1);
    ids.emplace(72);

    int num = 43213;
    if(ids.find(num) != ids.end()){
        std::cout << "FOUND: "<< num << std::endl;
    }else{
        std::cout << "CAN'T FIND: "<< num << std::endl;
    }

    for(auto it = ids.begin(); it != ids.end(); it++){
        std::cout << "Key: " << *it << std::endl;
    }

    return 0;
}
