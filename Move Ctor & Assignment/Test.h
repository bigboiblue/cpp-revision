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
    Test(const Test &other);
    //Move Ctor
    Test(Test &&other) noexcept;


    //Overloaded Copy Assignment
    Test &operator=(const Test &other);
    //Overloaded Move Assignment
    Test &operator=(Test &&other) noexcept;


    ~Test();

private:
    std::vector<int> *nums;

};


#endif //MOVE_CTOR_ASSIGNMENT_TEST_H
