/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachkar <hlachkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:05:35 by hlachkar          #+#    #+#             */
/*   Updated: 2023/04/15 01:01:43 by hlachkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data d;
    Serializer test;
    uintptr_t p;

    d.i = 5;
    
    std::cout << "SERIALIIIIZE : " << &d << std::endl;
    std::cout << d.i << std::endl;
    
    p = test.serialize(&d);
    
    std::cout << "DESERIALIIIZE : " << p << std::endl;
    
    Data *l = test.deserialize(p);
    std::cout << "l address : " << l << std::endl;
    
    std::cout << "d address : " << &d << std::endl;

}