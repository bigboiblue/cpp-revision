#include <iostream>
#include <utility> //Needed for std::move


void check(const int &x){
    std::cout << "Const LValue Function Called" << std::endl;
}

void check(int &&x){
    std::cout << "RValue Function Called" << std::endl;
}


int main() {

    int val1 = 321; //val1 is an LValue (for Left Value), and 321 is an RValue

    ////Pre-requisite info////
    //An LValue is a named value that we can take the address of
    //An RValue is a temporary unnamed value which we cannot take the address of  <--- e.g. RValues are often temporary values such as a return value or a literal
    //Note postfix++ operator actually returns a temporary value (RValue) so we cant take the address when using it

    ////LValue References
    //We can only bind an LValue reference (which uses one &) to an LValue:
    int someInt = 1;
    int &rSomeInt = someInt;
    //Unless we make the type its referring to const. This will extend the lifetime of the RValue. This must exist, as it is used in copy ctors:
    const int &rSomeLiteral = 21; //Strangely works. Cannot change temporary vars (which are const by default)


    ////RValue References
    //RValue references give us a way to differentiate between temporary and non-temporary values
    //The point of RValue references is to be able to use them as function parameters to detect when an RValue has been passed to a function to potentially optimise code for this case
    //Examples of the use of RValue references are emplace in STL classes, and many std make functions e.g. make_shared or make_pair
    int &&temp = 32;

    std::cout << std::endl;
    //When an RValue is passed into an overloaded function, the RValue overload variation better matches the param, so this is executed:
    check(temp);             //RValue ref passed <--- Const LVal called: RValue Ref extended 32. As 32 now has a name (temp) its now an LValue.
    check(std::move(temp));  //RValue ref passed using move <--- RVal Called: std::move is a cast that returns an RValue reference (and return vals are temp which are RVals)
                             //(that's it, std::move only returns an rVal ref, nothing is deleted)
    int &someLVal = temp;    //See, its an LValue now...
    check(31);               //RValue passed     <--- RVal Called
    check(someInt);          //LValue passed     <--- Const LVal Called

    int *xx;
    {
        int &&greg = 4;
        xx = &greg;
        greg = 7;
    }
    std::cout << *xx << std::endl;



    return 0;
}