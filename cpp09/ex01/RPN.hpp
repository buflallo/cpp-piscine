/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachkar <hlachkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:38:49 by hlachkar          #+#    #+#             */
/*   Updated: 2023/05/31 01:38:50 by hlachkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP_ 
#define RPN_HPP_

#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>

int is_operator(char ex);
int is_valid_rpn(std::string exp);
int calcul_rpn(std::string exp);

#endif