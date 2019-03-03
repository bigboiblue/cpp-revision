//
// Created by kyle on 03/03/19.
//

#ifndef MATHS_H
#define MATHS_H


namespace maths {

    /** binary maths operations **/
    double multiply (double a, double b);
    double add (double a, double b);
    double subtract (double a, double b);
    double divide(double a, double b);

#if 0  // Does not work as function () operator has higher precedence. This would mean the function we are passing is actually a function that returns a pointer to a double
    double binOperation(double a, double b, double *operation());
#endif
    // However, this works, as now the parenthesis invoke the * operator before (), making is a pointer to a function that returns double
    double binOperation(double a, double b, double (*operation)(double, double));
    //If I wanted to make a function pointer to binOperation, I could do: double (*fPtr)() = binOperation;

    bool moreThanZero(double a);

    }


#endif //LAMBDA_MATHS_H
