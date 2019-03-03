#ifndef TEST
#define TEST 1

#include <string>


//Rule or 3!
//If you have 1 of the following: Copy Ctor, Overloaded assignment, Dtor
//You should probably have all three (As you are likely working with memory and pointers.
//Copying the object would only copy the ptrs, not the objects the ptrs point to)
class Person{
public:
    Person() = delete;
    //"Test() = default" explicity defines auto generated default ctor

    Person(std::string name);

    //Copy Ctor as we want a new pid
    Person(const Person &other);

    //Overloading = operator as we dont want to copy pid
    const Person &operator=(const Person &other);

    void printInfo();
private:

    std::string name;
    int pid;
    static int numObjects;

};

#endif
