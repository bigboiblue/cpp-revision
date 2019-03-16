#include <iostream>
#include <typeinfo> //For C++98 typeid operator
#include <climits>
#include <vector>


////USING TEMPLATE////
template <class T> using greg = std::vector<T>;
/////


////MORE DECLTYPE////
template <class T, class S>
auto get(T t, S s) -> decltype(t + s) { //Use of C++11 trailing return.
                    // Can be helpful when creating template functions, as T + S may return a completely unrelated type (depending on the definition of the + operator)
    return t + s;
}

//We can use auto keyword in functions with a trailing return type.
//Trailing return allows use of the functions own parameters in return type expression (using decltype)
auto testFunc(const std::string &x) -> decltype(get(x, x)) {
    return get(x, x);
}
/////


int main() {

    ////DECLTYPE////
    std::cout << "\nDecltype: " << std::endl;
    //typeid() returns a type_info object
    //The following gives a strange output. This is because of name mangling
    //Name mangling is the encoding of function and variable names so that a linker can separate common names (such as overloaded functions) in a language
    std::string someString;
    std::cout << typeid(someString).name() << std::endl;

    //decltype(var) simply extracts the type from var, instead of having to retype the full type manually
    decltype(someString) otherString = "GREGORUS";
    std::cout << typeid(otherString).name() << std::endl; //See, this is the same type
    std::cout << otherString << std::endl;


    ////DECLTYPE WITH AUTO TRAILING RETURN FUNCTIONS////
    std::cout << testFunc("\nYou wot m8") << std::endl;




    ////TYPEDEF and USING (FAVOUR USING)////
    std::cout << "\nTypedef / Using: " << std::endl;
    //typedef [original-type] [your-alias];
    typedef unsigned int U32; //Extremely simple. A typedef allows you to make type alias for a specific type

    U32 myUInt = UINT32_MAX;
    std::cout << "Max unsigned int (U32) number = " << myUInt << std::endl;

    //using [your-alias] = [original-type];
    //using keyword works in the EXACT same way as typedef (it actually has the same semantics [meaning])
    //using is newer, however (c++11) and can also be used with templates, so favour using
    ////template<class T> using greg = std::vector<T>; <-- this works, but a template declaration cannot appear at block scope, so is defined at beginning of file
    greg<int> ello;
    ello.push_back(1);

    ////ENUMS////
    std::cout << "\nEnums: " << std::endl;
    //Enums allow us to refer to integer types in code by names
    //There are 2 type of enums: regular enums, and enum classes
    //The only difference is that enum classes must be referred to using className::ENUM_NAME, and int cannot be compared to className
    enum class Animal{
        COW = 0, CAT, DOG, RABBIT, HUMAN //convention to use caps for enum. By default starts at 0 and counts up (1 each time)[you can change start, or even all values]
    };

    std::cout << "Rabbit enum: " << int(Animal::RABBIT) << std::endl; //Static cast (or conversion), as Animal not implicitly convertible


    return 0;
}