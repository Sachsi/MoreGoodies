#include <iostream>
#include <fstream>
#include <string>

/**
 * @brief stream
 * iostream: ostream and istream is used to get an stream to an console
 * fstream: ofstream and ifstram is used write and read driectly from a file
 * fstream class to read and write at the same time from a file
 */

void write(void)
{
    
    //instate of opening the file by invoking the contructor
    //we can using the open() function to given the name of the file as wel
    std::ofstream out;//{"data.txt"};
    out.open("data.txt");
    out << "Hello World" << std::endl;
    out << 10 << std::endl;
    out.close();
    
}

void read(void)
{
    //instate of opening the file by invoking the contructor
    //we can using the open() function to given the name of the file as well
    std::ifstream input{"data.txt"};
    //using the error bits of the file stream class, or the operator !
    // if(!input.is_open())
    //     std::cout << "Could not open file" << std::endl;
    
    //input.open("data.txt");
    if(input.fail())
        std::cout << "Could not open file" << std::endl;
    
    std::string message;
    //getline ist used to read the entitle line
    std::getline(input, message);    
    int value{};
    input >> value;
    //input >> value;

    if(input.fail())
        std::cout << "Could not read file" << std::endl;
    if(input.eof())
        std::cout << "End of file ist reached" << std::endl;

    if(input.good())
        std::cout << "I/O operation are successful" << std::endl;

    input.setstate(std::ios::failbit);
    input.clear();
    input.close();
    std::cout << message << ":" << value << std::endl;
}

#ifdef FILE_IO

int main(void)
{
    write();
    read();
    return 0;
}

#endif