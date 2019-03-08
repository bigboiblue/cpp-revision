//
// Created by kyle on 07/03/19.
//

////    IMPORTANT NOTE   ////
//// Used of templates are fully implemented in header files as the compiler must know which T's to expand in definitions of functions
//// T's must be expanded at compile time to ensure they are used correctly (for example, << operator may not be defined for a specific type)

//// If your adamant you want to separate interface and implementation (which I am), you can include the implementation file at the end inside include guard (I used .tpp extension so it doesnt get compiled)

#ifndef TEMPLATES_MYTEMPLATE_H //#ifndef checks whether the given token has been #defined earlier in the file or in an included file (i didnt know this...)
#define TEMPLATES_MYTEMPLATE_H



//Naming convention is often T when single template parameter. For multiple, its advised to use descriptive names prefixed with T e.g. TValue, TKey
template <class T> //can have multiple template types if desired e.g template <class T, class TOther>
class MyTemplate {
public:

    explicit MyTemplate(const T &t);

    void printInfo();

    //Can create a template function within the template class:
    template<class C>
    auto combine(T t, C c) -> decltype(t + c);

    T getMyT();


    ////NESTING TEMPLATE CLASSES
    //Lets say for example I wanted an iterator class as part of my main template class. I must first declare the class inside this class (as its part of the class)
    //See implementation for rest of explanation...
    class iterator;

private:
    T myT;
};



////This include MUST be inside the header guard
#include "MyTemplate.tpp"


#endif //TEMPLATES_MYTEMPLATE_H



