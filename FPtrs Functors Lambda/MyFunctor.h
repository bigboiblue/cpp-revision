//
// Created by kyle on 03/03/19.
//

#ifndef FPTRS_FUNCTORS_LAMBDA_MYFUNCTOR_H
#define FPTRS_FUNCTORS_LAMBDA_MYFUNCTOR_H


//A functor is essentially an object with an overloaded () operator.
//It is NOT a function, it is an object. It can be used / perceived as a function, and can hold additional (state) data
struct MyFunctor {
    MyFunctor(int x): x(x) {}

    int operator()(int someParam){
        return x + someParam;
    }

private:
    int x;

};


#endif //FPTRS_FUNCTORS_LAMBDA_MYFUNCTOR_H
