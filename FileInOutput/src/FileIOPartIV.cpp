#include <iostream>
#include <fstream>
#include <string>

//#ifdef FILE_IO_SEEKING

void Write(){
    std::ofstream out("test.txt");
    if(!out){
        std::cout << "Could not open file for write" << std::endl;
        return;
    }
    std::string message;
    //put write this message charater by charater into the file
    for(char ch : message){
        out.put(ch);
    }


}

void Read()
{
    std::ifstream input("test.txt");
    if(!input)
    {
        std::cout << "Could not open file for read" << std::endl;
        return;
    }

    char ch{};
    //for reading this file, need the get function read it char by char
    //the disadvantice is, reading starts always at the beginning
    while (input.get(ch)){
        std::cout << ch;
    }

}

int main(void){

    Write();
    Read();
    return 0;
}

//#endif