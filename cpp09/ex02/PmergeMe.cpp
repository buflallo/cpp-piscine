/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachkar <hlachkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:37:40 by hlachkar          #+#    #+#             */
/*   Updated: 2023/05/31 01:37:41 by hlachkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// start vector sort

void MergeAndInsert(std::vector<int>& result, std::vector<int> const & left, std::vector<int> const & right) {
    result.clear();
    result.reserve(left.size() + right.size());

    std::vector<int>::const_iterator leftIt = left.begin();
    std::vector<int>::const_iterator rightIt = right.begin();

    while (leftIt != left.end() && rightIt != right.end()) {
        if (*leftIt < *rightIt) {
            result.push_back(*leftIt++);
        } else {
            result.push_back(*rightIt++);
        }
    }

    result.insert(result.end(), leftIt, left.end());
    result.insert(result.end(), rightIt, right.end());
}

void insert_sort(std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void MergeSort(std::vector<int>& arr) {
    int threshold = 100;

    if (arr.size() > 1) {
        if ((int)arr.size() <= threshold) {
            insert_sort(arr);
        } 
        else{
            std::vector<int> left, right;

            size_t mid = arr.size() / 2;

            left.reserve(mid);
            right.reserve(arr.size() - mid);

            left.insert(left.end(), arr.begin(), arr.begin() + mid);
            right.insert(right.end(), arr.begin() + mid, arr.end());

            MergeSort(left);
            MergeSort(right);

            MergeAndInsert(arr, left, right);
        }
    }
    
}

// end vector sort

// start list sort

void MergeAndInsert(std::list<int>& result, std::list<int> const & left, std::list<int> const & right) {
    result.clear();
    
    std::list<int>::const_iterator leftIt = left.begin();
    std::list<int>::const_iterator rightIt = right.begin();

    while (leftIt != left.end() && rightIt != right.end()) {
        if (*leftIt < *rightIt) {
            result.push_back(*leftIt++);
        } else {
            result.push_back(*rightIt++);
        }
    }

    result.insert(result.end(), leftIt, left.end());
    result.insert(result.end(), rightIt, right.end());

}

void MergeSort(std::list<int>& arr) {
    
    if (arr.size() > 1)
    {
        std::list<int> left, right;

        std::list<int>::iterator it = arr.begin();
        std::advance(it, arr.size() / 2);

        left.insert(left.begin(), arr.begin(), it);
        right.insert(right.begin(), it, arr.end());

        MergeSort(left);
        MergeSort(right);

        MergeAndInsert(arr, left, right);
    }
}

// end list sort

//helpers

static void onlydigits(std::string str)
{
    size_t i = 0;
    if (str[i] == '+')
        i++;
    for (; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            throw std::exception();
    }
}

void fill_vector(std::vector<int>& arr, int ac, char **av)
{
    arr.reserve(ac - 1);
    for(int i = 1; i < ac; i++)
    {
        try
        {
            onlydigits(av[i]);
            arr.push_back(std::stoi(av[i]));
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error: only digits are accepted " << std::endl;
            exit(1);
        }
    }
}

void fill_list(std::list<int> &List, int ac, char **av)
{
    for(int i = 1; i < ac; i++)
    {
        try
        {
            onlydigits(av[i]);
            List.push_back(std::stoi(av[i]));
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error: only digits are accepted" << std::endl;
            exit(1);
        }
    }
}

double GetTime()
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000000 + time.tv_usec);
}
