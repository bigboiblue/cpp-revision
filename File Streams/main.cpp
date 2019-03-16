#include <iostream>
#include <vector>
#include <fstream>

int main(){

    std::string fileName = "food.txt";
    std::cout << "Output to file: " << fileName << std::endl;

    //Output to file
    std::ofstream oFile(fileName);

    if(oFile.is_open()){
        oFile << "Hash Browns" << std::endl;
        oFile << "Bacon" << std::endl;
        oFile << "Eggz" << std::endl;
        oFile << "Beanz";
    }else{
        std::cout << "ERROR:::Cannot open file" << std::endl;
    }

    oFile.close();

    //Input from file

    //Can use fstream for either. For this, you require second argument to specify io(e.g. std::ios::in)
    std::fstream iFile(fileName, std::ios::in);

    if(iFile.is_open()){
        std::vector<std::string> foods;
        //While not eof or no errors (e.g. badbit)
        while(iFile.good()){
            foods.emplace_back();
            std::getline(iFile, foods.back());
        }

        for(std::string food: foods){
            std::cout << "Food: " << food << std::endl;
        }
    }else{
        std::cout << "ERROR:::Cannot open file" << std::endl;
    }
}
