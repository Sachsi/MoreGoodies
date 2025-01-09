#include <iostream>
#include <vector>

template<typename T, int columne>
class PrettyPrinter{
    T *m_pData;
public:
    PrettyPrinter(T *data) : m_pData(data){
    }
    void Print(){
        std::cout << "Columns: " << columne << std::endl;
        std::cout << "{" << *m_pData << "}" << std::endl;
    }
    T * GetData(){
        return m_pData;
    }
};
//partcial specialization template. Is just used by 80 columns
template<typename T>
class PrettyPrinter<T, 80>{
    T *m_pData;
public:
    PrettyPrinter(T *data) : m_pData(data){
    }
    void Print(){
        std::cout << "Columns are 80." << std::endl;
        std::cout << "{" << *m_pData << "}" << std::endl;
    }
    T * GetData(){
        return m_pData;
    }
};
//this smartpointer template is single values but not for type arrays
template<typename T>
class Smartpointer{
    T *m_ptr;
public:
    Smartpointer(T *pdata) : m_ptr(pdata){

    }
    T * operator ->(){
        return m_ptr;
    }
    T & operator *(){
        return *m_ptr;
    }
    ~Smartpointer(){
        delete m_ptr;
    }

};
//for type arrays we have to create a new template for Smartpointer
template<typename T>
class Smartpointer<T[]>
{
    T* m_ptr;
public:
    Smartpointer(T* data) : m_ptr(data){

    }
    T & operator[](int index){
        return m_ptr[index];
    }
    ~Smartpointer(){
        delete[] m_ptr;
    };
};

#ifdef PARTCIAL
int main(void)
{
    int value = 800;
    PrettyPrinter<int, 80> pv(&value);
    pv.Print();

    Smartpointer<int> s1{new int(1)};
    std::cout << "value of s1: " << *s1 << std::endl;
    Smartpointer<int[]> s_array{new int[10]};
    s_array[2] = 10;
    std::cout << "array index 2: "<< s_array[2] << std::endl;
    return 1;
}

#endif