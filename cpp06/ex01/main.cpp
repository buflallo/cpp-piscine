/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachkar <hlachkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:05:35 by hlachkar          #+#    #+#             */
/*   Updated: 2023/02/15 19:05:36 by hlachkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

typedef struct Data{
    int i;
}Data;

uintptr_t serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

int main()
{
    Data d;

    uintptr_t p;

    d.i = 5;
    
    std::cout << "SERIALIIIIZE : " << &d << std::endl;
    std::cout << d.i << std::endl;
    
    p = serialize(&d);
    
    std::cout << "DESERIALIIIZE : " << p << std::endl;
    
    Data *l = deserialize(p);
    std::cout << "l address : " << l << std::endl;
    
    std::cout << "d address : " << &d << std::endl;

}