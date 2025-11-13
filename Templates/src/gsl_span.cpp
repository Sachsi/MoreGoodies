#include <algorithm>
#include <cstddef>
#include <iostream>
#include <gsl/span>

int main(void)
{
    // Create a span from an array
    int arr[] = {1, 2, 3, 4, 5};
    gsl::span<int> span(arr);

    // Print the elements of the span
    std::cout << "Elements in the span: ";
    for (auto& elem : span) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Modify an element in the span
    span[2] = 10;
    
    // Print the modified array
    std::cout << "Modified array: ";
    for (auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}