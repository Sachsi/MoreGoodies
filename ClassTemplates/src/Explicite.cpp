#include <iostream>
#include <vector>

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

// what was changed is just the function Print. So we create a template for
// Std::vector<> Print
// this has to be outside the class but inside the namespace
template<>
void PrettyPrinter<std::vector<int>>::Print(){
    std::cout << "{ ";
    for(const auto &x : *m_Data){
        std::cout << x;
    }
    std::cout << "}" << std::endl;
}

//explicite specialization for template of vector type
// template<>
// class PrettyPrinter<std::vector<int>> {
//     std::vector<int> *m_pData;
// public:
//     PrettyPrinter(std::vector<int> *data) : m_pData(data){

//     }
//     void Print(){
//         std::cout << "{ ";
//         for(const auto &x : *m_pData){
//             std::cout << x;
//         }
//         std::cout << "}" << std::endl;
//     }
//     std::vector<int> * GetData(){
//         return m_pData;
//     }
// };

//#ifdef EXPLICITE

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

    std::vector<int> vec = {1, 3 , 4, 5};
    PrettyPrinter<std::vector<int>> pv(&vec);
    pv.Print();
        
    return 0;
}

//#endif