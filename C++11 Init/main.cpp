#include <iostream>
#include <climits>
#include <vector>
#include <initializer_list> //US Spelling

//Arg1 = push/pop, Arg2 = name/identifier, Arg3 = number of bytes for padding (so the class mem size will be a multiple of n bytes)
#pragma pack(push, test, 1) //Just testing out pragma.
struct S {
    int id;
    std::string name;
};
#pragma pack(pop, test) //Pops until it reaches "test" identifier



class Test{
public:
    Test(const std::initializer_list<std::string> &texts)
    :texts(texts)
    {
        for(auto it = texts.begin(); it != texts.end(); it++){
            std::cout << *it << std::endl;
        }//Or could use foreach
    }

    unsigned long getListSize(){
        return texts.size();
    }

private:
    std::initializer_list<std::string> texts;
    int x{0}; //You can also set default values for members of a class should they not be initialized through a ctor (can also be done with = or ())
};











int main() {

    //NOTE: You can actually define classes within functions. This will be rarely useful, but may be useful for local custom functors etc.
    //You used to not be able to do this. This restriction may have been lifted in C++11 as a result of the introduction of lambdas

    //C++98 init of a struct using {} (Only for init)
    S s1 = {1, "Greg"};
    //C++11 init of struct using {} (direct & list initialisation)
    S s2{1, "Greg"};




#if 0 //List initialisation does not allow narrowing (e.g. for numbers this would stop truncation)
    int x{LONG_LONG_MAX}; //This would not compile, as this must be truncated to fit in int, causing massive loss of data. Will show narrowing compilation error.
#endif
    //However, other initialisation methods would allow narrowing (bad in most cases)
    int x = LONG_LONG_MAX;
    int y(LONG_LONG_MAX);
    std::cout << "\nIncorrect narrowing / truncation: " << x << " and " << y << '\n' << std::endl;




    //Additionally, using () for init can look a little like function declarations: int x();

    int z1(); //This is confusingly parsed as a function declaration
    int z2{}; //This is a variable




#if 0 //Despite this, using {} with auto keyword may incorrectly evaluate types. Favour other init types in this situation.
    auto someInt{5}; //Will evaluate to an std::initialiser_list<int>
#endif

    //So using {} init in a ctor that accepts an initialisation list will call that. This may or may not be what you want, so be weary (example = std::vector, std::string)
    //So in most cases, prefer {} over other initialisation methods

    //Example if incorrect ctor called. Wanted 60x D. Called initializer list variant instead
    std::cout << "Accidental call of initialiser list ctor" << std::endl;
    std::string someString{60,'d'}; //60 parsed as '<' character
    std::cout << someString << std::endl;

    std::string otherString(60, 'd');
    std::cout << otherString << '\n' << std::endl;



    //Similar example (using class I declared before main) [a bit like passing a const vector to a function, but without having to init a vec]:
    std::cout << "My own initializer_list example:" << std::endl;
    Test test{"YOU", "ARE", "GAY"};
    std::cout << "Initializer list size: " << test.getListSize() << std::endl;
    Test t1();





    //OTHER RANDOM EXAMPLES

    std::cout << "\nList init with Ptrs" << std::endl;
    int *pInts = new int[5]{3,3,1,2,3};
    for(int i = 0; i < 5; i++){
        std::cout << pInts[i] << std::endl;
    }
    delete [] pInts;





    //() and {} will init to default value, e.g. int() or int{} == 0 e.g.
    int intArray[5]{};
    std::cout << "\nDefault init:" << std::endl;
    for(const int &x: intArray){
        std::cout << x << std::endl;
    }


        return 0;
}