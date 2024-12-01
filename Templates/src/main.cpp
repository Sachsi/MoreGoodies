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
    int max = 0;
    const int* ptemp = pArr;
    for(int i = 0; i < arrSize; i++)
    {
        
    }
    return max;
}

std::pair<int, int> MinMax(const int* pArr, size_t arrSize)
{

}

int main(void)
{

    std::array<int, 3> arr{15, 16, 19};
    int* pArr = arr.begin();

    int sum = Add(19, 19);
    std::cout << "result " << sum << std::endl;

    int elements = ArraySum(pArr, arr.size());
    std::cout << "Num Elements: " << elements << std::endl;
}