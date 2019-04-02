//
// Created by kyle on 07/03/19.
//

#ifndef MOVE_CTOR_ASSIGNMENT_TEST_H
#define MOVE_CTOR_ASSIGNMENT_TEST_H

#include <vector>
#include <initializer_list>

class Test {
public:

    Test(std::initializer_list<const int> iList);

    //Copy Ctor
    Test(const Test &other); //If exception thrown in ctor, other is const, so its unaffected, and no object is constructed. This is guaranteed.
    //Move Ctor
    Test(Test &&other) noexcept; //noexcept is necessary here as the same is not guaranteed. other is not a const object, so it will be modified.
                                 //When 'other' goes out of scope after move ctor, and an exception is thrown, since some of the objects have been
                                 //set to nullptr, and Test is not even constructed, memory leaks will occur.

    //Overloaded Copy Assignment
    Test &operator=(const Test &other);
    //Overloaded Move Assignment
    Test &operator=(Test &&other) noexcept;


    ~Test(); //Memory leaks will occur if exceptions are thrown in dtor, as delete would not be called on raw pointers (should they exist)

private:
    std::vector<int> *nums;

};


#endif //MOVE_CTOR_ASSIGNMENT_TEST_H
