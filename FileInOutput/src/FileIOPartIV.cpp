#include <iostream>
#include <fstream>
#include <string>

#ifdef FILE_IO_SEEKING
//
void Write(){
    std::ofstream out("test.txt");
    if(!out){
        std::cout << "Could not open file for write" << std::endl;
        return;
    }
    std::string message{ "C++ was inverted by Bjarne"};
    //for the current position you use the tellp()
    std::cout << "the current position write: " << out.tellp() << std::endl;
    //put write this message charater by charater into the file
    for(char ch : message){
        out.put(ch);
    }

    //change one char in the line
    out.seekp(-5, std::ios::end);
    out.put('#');
}

void Read()
{
    std::ifstream input("test.txt");
    if(!input)
    {
        std::cout << "Could not open file for read" << std::endl;
        return;
    }
    //to change the position of the read pointer you use the .seekg() function
    //input.seekg(5); //two overload function
    input.seekg(5, std::ios::beg); // the arg is the place where to start
    //tellg() function tells the current position of the pointer. By failer -1
    std::cout << "Current position is: " << input.tellg() << std::endl;
    char ch{};
    //for reading this file, need the get function read it char by char
    //the disadvantice is, reading starts always at the beginning
    while (input.get(ch)){
        std::cout << ch;
    }

}

void UsingFstream()
{
    //by fstream we have to create a file which we want to open
    std::fstream stream{"file.txt"};
    //checking if this exist, if not create a new one
    if(!stream){
        std::cout << "FILE DOES NOT EXIST: CREATE ONE..." << std::endl;
        std::ofstream out{"file.txt"};
        out.close();
        stream.open("file.txt");
    }
    stream << "Hello World" << std::endl;

    //because that fstream was writing to the file, the pointer is already
    //at the end. So we have to set the pointer at the beginning again.
    stream.seekg(0);

    std::string line;
    std::getline(stream, line);
    std::cout << line << std::endl;
}

int main(void){
    UsingFstream();
    Write();
    Read();
    return 0;
}

#endif