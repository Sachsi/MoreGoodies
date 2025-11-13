#include <iostream>

//class templates are the like functions templates.Non-types are possible as well.
template<typename T, int size>
class Buffer
{
private:
    T m_Buffer[size];
    int m_Top{-1};
public:
    //default constructor
    Buffer() = default;
    //copy constructor, short or lang hand notation is working
    //Buffer(const Buffer &obj){
    Buffer(const Buffer<T, size> &obj){
        m_Top = obj.m_Top;
        for(int i = 0; i <= m_Top; ++i){
            m_Buffer[i] = obj.m_Buffer[i];
        }
    }

    void Push(const T value){
        m_Buffer[++m_Top] = value;
    }
    void Pop(void);
    T Top(void)const{
        return m_Buffer[m_Top];
    }
    bool isEmty(void){
        return m_Top == -1;
    }
    //short hand notation work just inside a class not outside
    static Buffer Create();
};

template<typename T, int size>
void Buffer<T, size>::Pop(void)
{
    --m_Top;
}
//here we have to use the long hand notation, outside. 
//class name with argument list
template<typename T, int size>
Buffer<T, size> Buffer<T, size>::Create()
{
    return Buffer<T, size>();
}

#ifdef PART_I

int main(void)
{
    //the type and the size have to define after class name
    Buffer<float, 300> buf = Buffer<float, 300>::Create();
    buf.Push(12.8);
    buf.Push(43.9);
    buf.Push(189);
    buf.Push(135);
    buf.Push(66.5);
    buf.Push(59);
    auto buf_copy(buf);
    while (!buf_copy.isEmty())
    {
        std::cout  << buf_copy.Top() << " ";
        buf_copy.Pop(); 
    }
    
    
    return 0;
}

#endif