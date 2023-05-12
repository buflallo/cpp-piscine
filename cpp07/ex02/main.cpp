#include "Array.hpp"

int main()
{
    Array<int> arr(10);
    const Array<char> arr1(7); //checking the read only case
    Array<int> arr2;

    arr2 = arr;
    arr2[5] =30;
    // arr1[5] = 97;
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
        std::cout << arr2[i] << " ";
        try{
            std::cout << arr1[i] << " " << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    return 0;
}