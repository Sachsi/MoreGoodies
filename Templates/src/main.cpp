#include <iostream>
#include <array>

int Add(int x, int y)
{
    return (x + y);
}

int ArraySum(const int *pArr, size_t arrSize)
{
    const int* pstart;
    pstart = pArr;
    int sum = 0;
    for( int i = 0; i < arrSize; i++ )
    {
        sum += *pArr;
        pArr++;
    }
    return sum;
}

int Max(const int* pArr, size_t arrSize)
{
    int max = *pArr;
    const int* ptemp = pArr;
    for(int i = 0; i < arrSize; i++)
    {
        max = *ptemp > max ? *ptemp : max;
        ptemp++;
    }
    return max;
}

std::pair<int, int> MinMax(const int* pArr, size_t arrSize)
{
    int max = 0;
    int min = *pArr;
    const int* ptemp = pArr;
    max = Max(pArr, arrSize);
    
    for(int i = 0; i < arrSize; i++)
    {
        min = *ptemp < min ? *ptemp : min;
        ptemp++;
    }

    return std::pair<int, int>(min, max);
}

int main(void)
{

    std::array<int, 3> arr{15, 22, -1};
    int* pArr = arr.begin();

    int sum = Add(19, 19);
    std::cout << "result " << sum << std::endl;

    int elements = ArraySum(pArr, arr.size());
    std::cout << "Num Elements: " << elements << std::endl;

    int max = Max(pArr, arr.size());
    std::cout << "Max value ist: " << max << std::endl;

    std::pair<int, int> a = MinMax(pArr, arr.size());
    std::cout << "Min value: " << a.first << " Max value: " << a.second << std::endl;

}