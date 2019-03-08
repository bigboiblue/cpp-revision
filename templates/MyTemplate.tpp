#include "MyTemplate.h"

#include <iostream>
#include <typeinfo>

//CTOR
template <class T>  //// When splitting interface and implementation, you must expicitly specify each function as a template function,
                    //// with the scope its pointing to being type Class<T>::function (as this is the specific class constructed)
                    //// JUST AS YOU DO WHEN NESTING CLASSES
                    //So this is a template function that allows /is defined for any type of MyTemplate
MyTemplate<T>::MyTemplate(const T &t)
:myT(t)
{
}


//We would have to also make this into a template class, that allows any variation of MyTemplate
template <class K> //Could just call this T if you wanted
class MyTemplate<K>::iterator{
public:
    void print(){
        std::cout << "I am an iterator for type: " << typeid(K()).name() << std::endl;
    }
};

template<class T>
void MyTemplate<T>::printInfo() {
    std::cout << "T is a: " << typeid(myT).name() << " --- has the size: " << sizeof(myT) << " Bytes --- and has the value: " << myT << std::endl;
}

                  ////Since we nested another template in template, the implementation syntax also needs to reflect this (order matters)
template<class T> ////Doing template <class T> template <class C> implies class C is nested inside class T (so template <class C> template <class T> wouldn't work)
template<class C> ////Additionally MyTemplate<T>::extraTParamFunc<C>() is different to MyTemplate<T,C>::extraTParamFunc() or MyTemplate::extraTParamFunc<T,C>() , which is what template<class T, class C> would imply...
auto MyTemplate<T>::combine(T t, C c) -> decltype(t + c) {
    return t + c;
}

template<class T>
T MyTemplate<T>::getMyT() {
    return myT;
}
