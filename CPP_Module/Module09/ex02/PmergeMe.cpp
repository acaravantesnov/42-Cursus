/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:09:09 by acaravan          #+#    #+#             */
/*   Updated: 2023/08/16 15:29:45 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _stl1(new std::deque<int>), _stl2(new std::list<int>)
{}

PmergeMe::PmergeMe(const PmergeMe &pmergeme)
{
    if (this != &pmergeme)
    {
        _stl1 = new std::deque<int>;
        (*_stl1) = *(pmergeme.getStl1());
        _stl2 = new std::list<int>;
        (*_stl2) = *(pmergeme.getStl2());
    }
}

PmergeMe::PmergeMe(std::deque<int> *stl1, std::list<int>  *stl2)
{
    _stl1 = new std::deque<int>;
    (*_stl1) = *(stl1);
    _stl2 = new std::list<int>;
    (*_stl2) = *(stl2);
}

PmergeMe::~PmergeMe()
{
    delete(this->_stl1);
    delete(this->_stl2);
}

PmergeMe &PmergeMe::operator=(PmergeMe &pmergeme)
{
    if (this != &pmergeme)
    {
        _stl1 = new std::deque<int>;
        (*_stl1) = *(pmergeme.getStl1());
        _stl2 = new std::list<int>;
        (*_stl2) = *(pmergeme.getStl2());
    }
    return (*this);
}

std::deque<int>    *PmergeMe::getStl1() const
{
    return (_stl1);
}

void        PmergeMe::setStl1(std::deque<int> *stl1)
{
    _stl1 = stl1;
}

std::list<int>    *PmergeMe::getStl2() const
{
    return (_stl2);
}

void        PmergeMe::setStl2(std::list<int>  *stl2)
{
    _stl2 = stl2;
}


const char *PmergeMe::AlreadySorted::what() const throw()
{
    return("Numbers already sorted.");
}

bool isSorted(const std::deque<int> &d)
{
    for (size_t i = 1; i < d.size(); i++)
    {
        if (d[i] < d[i - 1])
            return false;
    }
    return true;
}

void mergeSortDeque(std::deque<int> *stl1, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;

        mergeSortDeque(stl1, l, m);
        mergeSortDeque(stl1, m + 1, r);
        merge(stl1, l, m, r);
    }
}

void merge(std::deque<int> *stl1, int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int k = l;

    std::deque<int> temp;
    std::cout << "i = " << i << " j = " << j << " k = " << k << std::endl;
    while ((i <= m) && (j <= r))
    {
        if ((*stl1)[i] <= (*stl1)[j])
        {
            temp.push_back((*stl1)[i]);
            i++;
        }
        else
        {
            temp.push_back((*stl1)[j]);
            j++;
        }
    }
    while (i <= m)
    {
        temp.push_back((*stl1)[i]);
        i++;
    }
    while (j <= r)
    {
        temp.push_back((*stl1)[j]);
        j++;
    }
    for (int p = l; p <= r; p++)
        stl1->push_back(temp[p]);
}
