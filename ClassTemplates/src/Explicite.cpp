#include <iostream>
template<typename T>
class PrettyPrinter{
    T *m_Data;
public:
    PrettyPrinter(T* data) : m_Data(data){

    }
    void Print(){
        std::cout << "{ " << *m_Data << " }" << std::endl;
    }
    T* GetData(){
        return m_Data;
    }
};
//explicite specialization template for char stream
template<>
class PrettyPrinter<char*>{
    char *m_Data;
public:
    PrettyPrinter(char* data) : m_Data(data){

    }
    void Print(){
        std::cout << "{ " << m_Data << " }" << std::endl;
    }
    char* GetData(){
        return m_Data;
    }
};

#ifdef EXPLICITE

int main(void)
{
    // int data = 12;
    // float f = 3.9;
    // PrettyPrinter<int> p1(&data);
    // PrettyPrinter<float> p2(&f);
    // p1.Print();
    // p2.Print();
    //because of this char stream we have to create explicite specialization template
    char *p{"Hello World"};
    PrettyPrinter<char*> p3(p);
    p3.Print();
    char *pData = p3.GetData();
    std::cout << pData;
    return 0;
}

#endif