#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

//#ifdef FILE_IO_COPY

int main(void)
{
    using namespace std::filesystem;
    
    //path source{R"(D:\Dokumente\Software\Weiterbildung\CppProjects\MoreGoodies\FileInOutput\src\)"};
    path source{R"(C:\Users\SACHSE_T\Documents\Weiterbildung\Cpp\Udemy\MoreGoodies\FileInOutput\src)"};
    std::cout << "current path: " << source.filename() << std::endl;
    source /= "FileIOCopy.cpp";
    

    //path dest{R"(D:\Dokumente\Software\Weiterbildung\CppProjects\MoreGoodies\FileInOutput\src\)"};
    path dest{R"(C:\Users\SACHSE_T\Documents\Weiterbildung\Cpp\Udemy\MoreGoodies\FileInOutput\src)"};
    dest /= "Copy.cpp";

    std::ifstream input{source};
    if(!input){
        std::cout << "Source file not found" << std::endl;
        return -1;
    }
    std::ofstream output{dest};
    std::string line;
    //copy the file line by line. Just text files
    while (!std::getline(input, line).eof())
    {
        output << line << std::endl;
    }
    input.close();
    output.close();

    return 0;
}

//#endif