#include <iostream>
#include <string>




int main(void){
    //in the file name, the interpreter read same charater as escape sequences \n(new line) and \t (tab)
    //to avoid this we have to escabe this backslash by another one. Used for long filename
    //std::string filename{"C:\temp\newfile.txt"};
    std::string filename{"C:\\temp\\newfile.txt"};
    std::cout << filename << std::endl;
    //in a raw string literal
    std::string RawLiteral{ R"(C:\temp\newfilename.txt)"};
    std::cout << "raw file " << RawLiteral << std::endl;
    
    //raw literal with two Anführungszeichen nebeneinander, is not working
    //std::string message_one{ R"(C++ introduced filessystem API"(In C++17)")" };
    std::string message{ R"MSG(C++ introduced filessystem API"(In C++17)")MSG" };
    std::cout << message << std::endl;
    return 0;
}