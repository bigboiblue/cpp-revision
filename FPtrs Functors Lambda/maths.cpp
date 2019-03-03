//
// Created by kyle on 03/03/19.
//

#include "maths.h"


namespace maths {


    double multiply (double a, double b){
        return a * b;
    }

    double add (double a, double b){
        return a + b;
    }

    double subtract (double a, double b){
        return a - b;
    }

    double divide(double a, double b){
        return a / b;
    }




    double binOperation(double a, double b, double (*operation)(double, double)) {
        return operation(a, b);
    }



    bool moreThanZero(double a){
        return a > 0;
    }
}
