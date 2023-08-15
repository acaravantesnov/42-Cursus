/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:09:55 by acaravan          #+#    #+#             */
/*   Updated: 2023/08/15 19:00:31 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _st(new std::stack<int>)
{}

RPN::RPN(const RPN &rpn)
{
    if (this != &rpn)
    {
        _st = new std::stack<int>;
        (*_st) = *(rpn.getSt());
    }
}

RPN::RPN(std::stack<int> *st)
{
    _st = new std::stack<int>;
    (*_st) = (*st);
}

RPN::~RPN()
{
    delete (this->_st);
}

RPN &RPN::operator=(RPN &rpn)
{
    if (this != &rpn)
    {
        _st = new std::stack<int>;
        (*_st) = *(rpn.getSt());
    }
    return (*this);
}

std::stack<int> *RPN::getSt() const
{
    return (_st);
}

void RPN::setSt(std::stack<int> *st)
{
    this->_st = st;
}

bool	check_args(std::string argv1)
{
	if ((argv1.size() < 1) || (argv1[0] == ' ') || (argv1[argv1.size() - 1] == ' '))
		return (false);
    for (size_t i = 0; i < argv1.size(); i++)
    {
        if (((argv1[i] < 48) || (argv1[i] > 57)) && \
        (argv1[i] != '*') && (argv1[i] != '/') && (argv1[i] != '+') && \
        (argv1[i] != '-') && (argv1[i] != ' '))
            return (false);
    }
	return (true);
}
