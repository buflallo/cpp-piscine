#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if(ac <= 1)
    {
        std::cout << "Error :two args or more" << std::endl;
        return(1);
    }
    std::vector <int> vec;
    fill_container(vec, ac, av);
    std::vector <int>vector(vec);
    std::cout << "before : ";
    print(vector);
    double start = GetTime();
    MergeSort(vector, vector.begin(), vector.end() - 1);
    double end = GetTime();
    double time = end - start ;
    std::cout << "after : ";
    print(vector);
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << time << " us\n";


    std::list <int> List;
    fill_container(List, ac, av);
    std::cout << "before : ";
    print(List);
    start = GetTime();
    MergeSort(List);
    end = GetTime();
    time = end - start ;
    std::cout << "after : ";
    print(List);
    std::cout << "Time to process a range of " << List.size() << " elements with std::deque: " << time << " us\n";
}