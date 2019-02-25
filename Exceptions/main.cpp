#include <iostream>
#include <exception>

class MyException: public std::exception {
public:
  const char * what() const noexcept{
    return "myException";
  }

private:

};



int main(){

  //Try block immediately followed by  at least 1 catch block
  try{
    std::cout << "This is trash" << std::endl;
    //Only use exception handling for errors a program cannot recover from
    throw MyException();
  }
  //Excpetion catching order matters, rules of polymorphism apply
  catch(MyException &e){
    std::cout << e.what() << std::endl;
  }catch(std::exception &e){
    std::cout << e.what() << std::endl;
  }catch(...){
    std::cout << "Some exception was caught" << std::endl;
  }

  return 0;
}
