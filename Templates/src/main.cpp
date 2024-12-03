#include <iostream>
#include <array>


template<typename T>
T Add(T x, T y)
{
    return (x + y);
}

template<typename T, typename S>
int ArraySum(T x, S y)
//int ArraySum(const int *pArr, size_t arrSize)
{
    T pstart = x;
    int sum = 0;
    std::cout << "sum id: " << typeid(x).name() << std::endl;

    for( int i = 0; i < y; i++ )
    {
        sum = Add(*pstart, sum);
        pstart++;
    }
    return sum;
}
template<typename T, typename S>
int Max(T x, S y)
// int Max(const int* pArr, size_t arrSize)
{
    int max = *x;
    const int* ptemp = x;
    for(int i = 0; i < y; i++)
    {
        max = *ptemp > max ? *ptemp : max;
        ptemp++;
    }
    return max;
}
template<typename T, typename S>
std::pair<int, int> MinMax(T x, S y)
{
    int result_Min = *x;
    T ptemp = x;
    int result = Max(x, y);
    
    for(int i = 0; i < y; i++)
    {
        result_Min = *ptemp < result_Min ? *ptemp : result_Min;
        ptemp++;
    }
    return std::pair<int, int>(result_Min, result);
}

int main(void)
{

    std::array<int, 3> arr{15, 22, -1};
    int* pArr = nullptr;
    
    int sum = Add(19, 19);
    std::cout << "result " << sum << std::endl;

    int elements = ArraySum(arr.data(), arr.size());
    std::cout << "Sum Elements: " << elements << std::endl;
    
    auto max = Max(arr.data(), arr.size());
    std::cout << "Max value ist: " << max << std::endl;

    std::pair<int, int> a = MinMax(arr.data(), arr.size());
    std::cout << "Min value: " << a.first << " Max value: " << a.second << std::endl;

}