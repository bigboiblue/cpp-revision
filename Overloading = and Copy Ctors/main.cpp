#include <iostream>
#include <vector>

#include "Person.hpp"

int main(){

    std::vector<Person> people;

    #if 0 //This is an inneficient method of adding items to a vector.
        //First, the parameterised Ctor is called. Then the copy ctor is called...
        people.push_back(Person("Mark"));
    #endif

    //This is more efficient. emplace_back inits Person only once (or you could use vector of smart ptrs)
    people.emplace_back("Mark");  //Parameterised
    people.emplace_back("Jeffry"); //Parameterised
    people.emplace_back(people.back()); //Copy ctor. New pid, but name = Jeffry
    people.emplace_back("Greg"); //Parameterised
    Person person = people.back();



    //NOT FINISHED
}
