#ifndef PMERGEME_HPP_
#define PMERGEME_HPP_

#include <iostream>
#include <vector>
#include <list>
#include <sys/time.h>


typedef std::vector<int>::iterator Iterator;

void MergeAndInsert(std::vector<int>& arr, Iterator low, Iterator mid, Iterator high);
void MergeSort(std::vector<int>& arr, Iterator low, Iterator high);
void MergeAndInsert(std::list<int>& result, std::list<int>& left, std::list<int>& right);
void MergeSort(std::list<int>& inputList);
double GetTime();

// helpers

template <typename T>
void fill_container(T & container, int ac, char **av)
{
    for(int i = 1; i < ac; i++)
        container.push_back(atoi(av[i]));
}

template <typename T>
void print(T & container)
{
    typename T::iterator it = container.begin();
    typename T::iterator ite = container.end();
    while(it != ite)
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}

#endif