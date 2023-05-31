/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachkar <hlachkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:38:12 by hlachkar          #+#    #+#             */
/*   Updated: 2023/05/31 01:38:13 by hlachkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int is_operator(char ex)
{
    if (ex == '+' || ex == '-'|| ex == '*' || ex == '/')
        return (1);
    return (0);
    
}

int is_valid_rpn(std::string exp)
{
    int count = 0;
    for(size_t i = 0; i < exp.length(); i++)
    {
        if (isblank(exp[i]))
            continue ;
        else if (isdigit(exp[i]))
        {
            count++;
            continue ;
        }
        else if (is_operator(exp[i]))
        {
            if (count < 2)
                return (0);
            count--;
        }
        else
            return (0);
    }
    if (count == 1)
        return (1);
    return (0);
}

int calcul_rpn(std::string exp)
{
    std::stack<int> stack;
    int num1, num2;
    for (size_t i = 0; i < exp.length(); i++) {
        if (isdigit(exp[i]))
        {
            stack.push(exp[i] - '0');
        }
        else if (is_operator(exp[i])) 
        {
            num2 = stack.top();
            stack.pop();
            num1 = stack.top();
            stack.pop();

            switch (exp[i])
            {
                case '+':
                {
                    stack.push(num1 + num2);
                    break;
                }
                case '-':
                {
                    stack.push(num1 - num2);
                    break;
                }
                case '*':
                {
                    stack.push(num1 * num2);
                    break;
                }
                case '/':
                {
                    stack.push(num1 / num2);
                    break; 
                }
            }
        }
    }
    return stack.top();
}
