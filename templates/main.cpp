#include <iostream>
#include <climits>


#include "MyTemplate.h"


//Can also simply define a template function outside a class:
template <class T> //Can also use typename instead e.g. template <typename T>
void printT(T t) {
    std::cout << "Param <template version> = " << t << std::endl;
}

void printT(int t) {
    std::cout << "Param (int version) = " << t << std::endl;
}


int main() {

    ////Template Class
    using U64 = long long;

    MyTemplate<U64> t1(LONG_LONG_MAX);
    t1.printInfo();
    //std::cout << myTemplate.combine<char>(myTemplate.getMyT(), 'g') << std::endl; <--- //function template argument deduction means you dont necessarily have to specify template params.
    //(its type can be inferred at compile time)
    std::cout << t1.combine(t1.getMyT(), 'g') << std::endl;

    MyTemplate t2(322); // in c++17 CLASS template argument deduction was introduced also

    ////Nested Template Class
    MyTemplate<int>::iterator it;
    it.print();


    ////Template function
    std::cout << std::endl;
    printT("I am sir GREGATONE");
    printT(5);      //Non-template overload version better matches the argument, so it is called
    //To call template version, I must either place <> brackets
    printT<>(5);
    printT<int>(5);// or explicitly define a type in template parameters.
}





////TEMPLATE SPECIALISATIONS AND PARTIAL TEMPLATE SPECIALISATIONS////
//A template specialisation allows customisation of a templates behaviour for a given category of template args
#if 0 //Full template specialisation
    template<class T>
    class greg {...};

    template<int>
    class greg {...}; //Define different behaviour specifically for int
#endif


#if 0 //Partial template specialisation
    template<class T, class C>
    auto someFunc (T t, C c) -> decltype(t + c) {...}

    template<class T>
    auto someFunc (T t, T t) -> T {...} //NOTICE: the func args are the same. Only 1 template param required. Other arg is explicitly defined (could be an int if you wanted)
#endif

////DEFAULT TEMPLATE ARGS

//Allows for an optional template arg, analogous to the optional arg feature for functions:
#if 0
    template<class T, class C = T> // Could be any type. could be an int if you wanted
    class greg {...};
#endif
/////////////