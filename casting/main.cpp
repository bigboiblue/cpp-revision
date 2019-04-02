#include <iostream>
#include <climits>

class Parent{
public:
    virtual void print() const {
        std::cout << "I am the parent" << std::endl;
    }
};

class Brother: public Parent{
public:
    void print() const override {
        std::cout << "I am the brother" << std::endl;
    }
    void punch() const {
        std::cout << "I PUNCH " << x << "TIMES" << std::endl;
    }
    int x{5};
};

class Sister: public Parent{
public:
    void print() const override {
        std::cout << "I am the sister" << std::endl;
    }
    void scream() const {
        std::cout << "AHHHHHHHHH" << std::endl;
    }
};



inline void checkPtr(void *ptr){
    if(ptr != nullptr){
        std::cout << "Conversion is considered valid / safe / sensible..." << std::endl;
    }else{
        std::cout << "Conversion is NOT considered valid / safe / sensible... This is now a nullptr" << std::endl;
    }
}


int main() {

    long long max = LONG_LONG_MAX;
    //int x{max}; Error, narrowing not allowed with {}
    int x{static_cast<int>(max)};
    std::cout << x << std::endl;

    ////STATIC CAST////
    std::cout << "\nStatic Cast:" << std::endl;
    //static_cast can convert between base and derived classes, and any type that defines a ctor for the type you want to convert to (implicit conversions). Can also cast anything to void*.
    //Static casts convert types at compile time (no checking occurs at runtime).
    //We cannot know a casted object is used incorrectly at runtime (e.g. you converted a parent into a derived class and tried to call a derived class only function)
    //For this reason we generally dont use static cast for inherited classes(we use dynamic for this)
    //Instead its mainly used to for implicit conversion or to convert anything to void*
    Parent parent;
    Brother brother;

    Parent *pParent = &parent;
    Brother *pBrother = static_cast<Brother *>(pParent); //Very unsafe, not recommended

#if 0
    pBrother->punch() // Potentially very unsafe. Parent class does not have a punch() function. May overwrite memory and cause undefined behaviour
#endif
    pBrother->print(); //However, this will work. Despite being a Brother* , remember this points to a parent, so it will call as if a parent

    //Undefined behaviour means not defined by the standard. It means the behaviour may vary from system to system and compiler to compiler.

    ////DYNAMIC CAST////
    std::cout << "\nDynamic cast:" <<std::endl;
    //Uses RTTI (Run-Time Type Information)[this is enabled by default on all modern compilers] to perform type safety checks
    //Dynamic cast returns a nullptr if the typecast is considered unsafe / invalid at runtime
    //This ensures the safest behaviour (but suffers slightly in performance)
    //Dynamic casts are only meant to be used with pointers / ref, and are generally used with inherited classes (this also fixes the prior problem posed)
    ////Using above vars
    pParent = dynamic_cast<Parent *>(pBrother); //Safe, Parent points to a Parent (through a conversion)
    pBrother = dynamic_cast<Brother *>(pParent); //Unsafe, wont have all Brother members

    checkPtr((pParent));
    checkPtr(static_cast<void *>(pBrother));


    ////REINTERPRET CAST////
    std::cout << "\nReinterpret cast:" << std::endl;
    //reinterpret_cast is generally used on pointers / ref. In reinterpret_cast, there are no checks at all.
    //It can pretty much convert any pointer type to another pointer type. The underlying binary pattern will remain the same,
    //however, its binary pattern will simply be interpreted as if it were the new type
    const char *cString = "Hello world";
    const long *wut = reinterpret_cast<const long*>(cString); //Will have undefined behaviour. Will just read the memory pattern of the string for sizeof(long) bytes
    std::cout << *wut << std::endl;
    const char *backToNormal = reinterpret_cast<const char*>(wut); //Bit pattern unchanged. Now interpreted as a c style char string again

    std::cout << backToNormal << std::endl;



    ////CONST CAST////
    std::cout << "\nConst cast:" << std::endl;
    //Pretty simple. Can add or remove const (or volatile) qualifier. This is done at compile time, so no run-time checks are done here
    //This is very dangerous, as you MUST be sure the underlying type is NOT originally const.
    //Allowed for pointers and references

//const int someInt = 123; Undefined behaviour if i were to const cast this. const_cast are meant to be used to remove const from pointers / ref that ultimately refer to a non const e.g.
    int someInt = 123;
    const int *pcSomeInt = &someInt;
    int *pSomeIntNoConst = const_cast<int *>(pcSomeInt);

    *pSomeIntNoConst = -69;
    std::cout << "Now int = " << someInt << std::endl;

    //Const cast can also be used to allow the use of normal variables in const functions

    //int * const pInt1 = &someInt; //Constant pointer to int
    return 0;
}