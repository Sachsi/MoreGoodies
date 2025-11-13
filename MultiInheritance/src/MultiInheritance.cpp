#include <iostream>
#include <string>


class Stream {
    std::string m_FileName;
    public:
        Stream(const std::string &filename){
            std::cout << "Stream(const std::string&)" << std::endl;
        }
        const std::string & GetFileName()const{
            return m_FileName;
        }
        ~Stream(){
            std::cout << "~Stream()" << std::endl;
        }
};

class OutputStream : virtual public Stream{
    std::ostream &out;
    public:
        OutputStream(std::ostream &o, const std::string &filename) :out(o), Stream(filename){
            std::cout << "OutputStream" << std::endl;
        }
        std::ostream & operator <<(const std::string &data){
            out << data;
            return out;
        }
        ~OutputStream(){
            std::cout << "~OutputStream" << std::endl;
        }
};

class InputStream : virtual public Stream {
    std::istream &in;
    public:
        InputStream(std::istream &in, const std::string &filename) : in(in), Stream(filename){
            std::cout << "InputStream" << std::endl;
        }
        std::istream & operator >> (std::string &data){
            in >> data;
            return in;
        }
        ~InputStream(){
            std::cout << "InputStream" << std::endl;
        }        
};
// in this code the file will invoked twice because of two base classes.
// The base classes have the same base clase. In this case this "class have to be virtual",
// so they will be not invoke again the thir base class (Stream) when IOStream invoke his base class.
class IOStream : public OutputStream, public InputStream {
    public:
    IOStream(const std::string &filename) : OutputStream(std::cout, filename),
    InputStream(std::cin, filename), Stream(filename) {
        std::cout << "IOStream" << std::endl;
    }
    ~IOStream(){
        std::cout << "~IOStream" << std::endl;
    }
};


int main(void)
{
    IOStream stream("data.txt");
    std::string data;

    stream >> data;
    stream << data;
    // this is not possible with invoking twice the file. The Error os ambiguous.
    stream << stream.GetFileName() << std::endl;
    return 1;
}
