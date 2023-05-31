/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachkar <hlachkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:37:37 by hlachkar          #+#    #+#             */
/*   Updated: 2023/05/31 01:37:38 by hlachkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if(ac <= 1)
    {
        std::cout << "Error :two args or more" << std::endl;
        return(1);
    }
    double start;
    double end;
    double time;
    std::vector <int> vector;
    fill_vector(vector, ac, av);
    std::cout << "before : ";
    print(vector);
    start = GetTime();
    MergeSort(vector);
    end = GetTime();
    time = end - start ;
    std::cout << "after : ";
    print(vector);
    std::cout << "Time to process a range of " << vector.size() << " elements with std::vector: " << time << " us\n";


    std::list <int> List;
    fill_list(List, ac, av);
    std::cout << "before : ";
    print(List);
    start = GetTime();
    MergeSort(List);
    end = GetTime();
    time = end - start ;
    std::cout << "after : ";
    print(List);
    std::cout << "Time to process a range of " << List.size() << " elements with std::list: " << time << " us\n";
}
