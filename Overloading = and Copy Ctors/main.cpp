#include <iostream>
#include <vector>

#include "Person.hpp"

int main(){

    std::vector<Person> people;

    //Allocate 20 spaces for elements to avoid unnecessary automatic resizing of underlying array (meaning more copy ctors will be called)
    //This is a benefit of using smart pointers instead of emplace back (the resize will only copy the ptrs, and not call copy ctor of object)
    people.reserve(20);


    #if 0 //This is an inneficient method of adding items to a vector.
        //First, the parameterised Ctor is called. Then the copy ctor is called...
        people.push_back(Person("Mark"));
    #endif

    //This is more efficient. emplace_back inits Person only once (or you could use vector of smart ptrs)
    people.emplace_back("Mark");  //Parameterised
    people.emplace_back("Jeffry"); //Parameterised
    people.emplace_back(people.back()); //Copy ctor. New pid, but name = Jeffry
    people.emplace_back("Greg"); //Parameterised
    Person person = people.back(); //NOTE: Calls copy ctor (this is copy intialisation, not assignment)

    std::cout << std::endl;

    people.emplace_back(person); //Calls copy ctor (last is now also Greg)

    std::cout << std::endl;

    people.back() = Person("John"); //Calls Parameterised Ctor, then overloaded assignment operator

    std::cout << std::endl;
    std::cout << std::endl;


    for(size_t i = 0; i < people.size(); i++){
        people[i].printInfo();
    }
    std::cout << "\nPID: 5 was missed out as this was used by the temp object: \"person\"" << std::endl;

    //NOT FINISHED
}
