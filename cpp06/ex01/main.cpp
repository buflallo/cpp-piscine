/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bufallo <bufallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:05:35 by hlachkar          #+#    #+#             */
/*   Updated: 2023/05/08 19:46:10 by bufallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data d; // to serialaze
    Serializer test; // object with method to do job
    uintptr_t p; // holder of the data

    d.i = 5;
    
    std::cout << "SERIALIIIIZE : " << &d << std::endl;
    std::cout << d.i << std::endl;
    
    p = test.serialize(&d);
    
    std::cout << "DESERIALIIIZE : " << p << std::endl;
    
    Data *l = test.deserialize(p);
    std::cout << "l address : " << l << std::endl;
    
    std::cout << "d address : " << &d << std::endl;

}