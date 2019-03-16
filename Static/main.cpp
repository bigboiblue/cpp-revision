#include <iostream>
#include <vector>

#include "ExampleClass.hpp"
#include "OutsideClass.hpp"

inline void insideFunctionLoop();

int main(){

    std::cout << "There are 3 contexts a static member can be in:" << std::endl;
    std::cout << "1. Inside a class" << '\n';
    std::cout << "2. Outside a class" << '\n';
    std::cout << "3. Inside a function or loop" << std::endl;
    //This means the var/func is allocated at the beginning of the program, and deallocated at the end
    std::cout << "Regardless of their context, it means the symbol has static duration" << std::endl;

    std::cout << "Choose an example: " << std::flush;
    int choice;
    std::cin >> choice;
    std::cout << "\n" << std::endl;

    std::vector<ExampleClass> exampleClasses;
    do{
        switch(choice){
            //Inside Class
            case 1:
                exampleClasses.reserve(20);
                //Push Back creates a copy of the object, therefore, this should create 20 objects (as copy ctor called also)
                //To avoid use emplace back
                for(int i = 0; i < 10; i++){
                    //exampleClasses.push_back(ExampleClass());
                    exampleClasses.emplace_back();
                }

                ExampleClass::printNumOfObjects();
            break;
            //Outside a Class
            case 2:
                //Declared in OutSideClass.hpp
                g_printStatic();

                #if 0 //Will not work. Cannot be seen within this translation unit
                std::cout << "Static var is: " << staticNumber << std::endl;
                #endif
            break;
            //Inside a function or loop
            case 3:
                insideFunctionLoop();
            break;
            default:
                choice = -1;
                std::cout << "Choose 1, 2 or 3: " << std::flush;
            break;
        }
    }while(choice == -1);

    return 0;
}

#define NUM 15
inline void insideFunctionLoop(){
    std::cout << "Looping " << NUM << " times:" << std::endl;
    for(int i = 0; i < NUM; i++){
        static int loopCount = 0;
        loopCount++;
        std::cout << "Loop Count " << loopCount << std::endl;
    }

}
