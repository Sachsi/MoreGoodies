#include <iostream>
#include <filesystem>

#ifdef FILE_LIBRARY

int main(void){
    using namespace std::filesystem;
    path p{R"(C:/Repo/install/home/storage/app/sachse_t/wfl2InstrumentLinux)"};
    //tell me if the filename has a file. But the class "path" does not validate the path. 
    if (p.has_filename())
    {
        std::cout << p.filename() << std::endl;
    }
    //the file path we break in his parts with a rang baised for loop
    for (const auto &part : p)
    {
        std::cout << part << std::endl;
    }

    //To validate the path, we have to take create a objecte of the "directory_iterator"
    directory_iterator beg{ p };
    //One directory iterator for another emty objecte for the END
    directory_iterator end{};
    
    while(beg != end){
        std::cout << *beg << std::endl;
        ++beg;
    }
        
    return 0;
}

#endif