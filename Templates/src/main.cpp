#include <iostream>
#include <array>


template<typename T>
T Add(T x, T y)
{
    return (x + y);
}

template<typename T, int size>
T ArraySum(T (&x)[size])
//int ArraySum(const int *pArr, size_t arrSize)
{
    T sum;
    std::cout << "sum id: " << typeid(x).name() << std::endl;

    for( int i = 0; i < size; i++ )
    {
        sum = Add(x[i], sum);
    }
    return sum;
}
/**
 * @brief 
 * 
 * @tparam T 
 * @tparam size 
 * @return T 
 */
template<typename T, int size>
T Max(T (&x)[size])
// int Max(const int* pArr, size_t arrSize)
{
    T max = x[0];
    for(int i = 0; i < size; i++)
    {
        max = max > x[i] ? max : x[i];
    }
    return max;
}
template<typename T, int size>
std::pair<T, T> MinMax(T (&x)[size])
{
    T result_Min = x[0];
    T result_Max = Max(x);     

    for(int i = 0; i < size; i++)
    {
        result_Min = result_Min < x[i] ? result_Min : x[i];
    }
    return std::pair<T, T>(result_Min, result_Max);
}

#ifdef ASSIGNMENT

int main(void)
{
    std::array<int, 3> arr{15, 22, -1};
    int array[] = {12,5,9,6, 56};
    int* pArr = nullptr;
    int (&ref)[5] = array;
    int sum = Add(19, 19);
    std::cout << "result " << sum << std::endl;

    int elements = ArraySum(ref);
    //std::cout << "Sum Elements: " << elements << std::endl;
    
    auto max = Max(ref);
    std::cout << "Max value ist: " << max << std::endl;

    auto a = MinMax(ref);
    std::cout << "Min value: " << a.first << " Max value: " << a.second << std::endl;

}

#endif //ASSIGNMENT