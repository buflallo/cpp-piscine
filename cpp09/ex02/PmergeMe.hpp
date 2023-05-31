/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachkar <hlachkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:37:43 by hlachkar          #+#    #+#             */
/*   Updated: 2023/05/31 01:37:44 by hlachkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP_
#define PMERGEME_HPP_

#include <iostream>
#include <vector>
#include <list>
#include <sys/time.h>


void MergeAndInsert(std::vector<int>& result, std::vector<int> const & left, std::vector<int> const & right);
void MergeSort(std::vector<int>& arr);
void MergeAndInsert(std::list<int>& result, std::list<int> const & left, std::list<int> const & right);
void MergeSort(std::list<int>& inputList);

// helpers

double GetTime();

template <typename T>
void print(T & container)
{
    typename T::iterator it = container.begin();
    typename T::iterator ite = it;
    std::advance(ite, 6);
    while(it != ite)
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << "[...]" << std::endl;
}

void fill_vector(std::vector<int>& arr, int ac, char **av);
void fill_list(std::list<int> &List, int ac, char **av);

#endif
