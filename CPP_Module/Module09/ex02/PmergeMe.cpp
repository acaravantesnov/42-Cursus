/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:09:09 by acaravan          #+#    #+#             */
/*   Updated: 2023/08/17 17:24:26 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &pmergeme)
{
    if (this != &pmergeme)
    {
        _stl1 = pmergeme.getStl1();
        _stl2 = pmergeme.getStl2();
    }
}

PmergeMe::PmergeMe(std::deque<int> stl1, std::vector<int>  stl2)
{
    _stl1 = stl1;
    _stl2 = stl2;
}

PmergeMe::~PmergeMe()
{}

PmergeMe &PmergeMe::operator=(PmergeMe &pmergeme)
{
    if (this != &pmergeme)
    {
        _stl1 = pmergeme.getStl1();
        _stl2 = pmergeme.getStl2();
    }
    return (*this);
}


void PmergeMe::checkIsSorted()
{
    size_t i;
    for (i = 1; i < _stl1.size(); i++)
    {
        if (_stl1[i] < _stl1[i - 1])
            break;
    }
    if (i == _stl1.size())
        throw (AlreadySorted());
}

void PmergeMe::checkRepeatedNumbers()
{
    std::deque<int> seenNumbers;

    for (std::deque<int>::iterator it = _stl1.begin(); it != _stl1.end(); ++it) {
        if (std::find(seenNumbers.begin(), seenNumbers.end(), *it) != seenNumbers.end()) {
            throw (RepeatedNumbers());
        }
        seenNumbers.push_back(*it);
    }
}

void PmergeMe::mergeSortDeque(int l, int r)
{
    if (l < r)
    {
        // Division
        int m = (l + r) / 2;

        // Recursion
        mergeSortDeque(l, m);
        mergeSortDeque(m + 1, r);
        
        // Merging
        mergeDeque(l, m, r);
    }
}

void PmergeMe::mergeDeque(int l, int m, int r)
{
    int i = l;
    int j = m + 1;

    std::vector<int> temp;
    while ((i <= m) && (j <= r))
    {
        if (_stl1[i] <= _stl1[j])
        {
            temp.push_back(_stl1[i]);
            i++;
        }
        else
        {
            temp.push_back(_stl1[j]);
            j++;
        }
    }
    while (i <= m)
    {
        temp.push_back(_stl1[i]);
        i++;
    }
    while (j <= r)
    {
        temp.push_back(_stl1[j]);
        j++;
    }

    for (int p = l; p <= r; p++)
        _stl1.at(p) = temp[p - l];
}

void PmergeMe::mergeSortVector(int l, int r)
{
    if (l < r)
    {
        // Division
        int m = (l + r) / 2;

        // Recursion
        mergeSortVector(l, m);
        mergeSortVector(m + 1, r);

        // Merging
        mergeVector(l, m, r);
    }
}

void PmergeMe::mergeVector(int l, int m, int r)
{
    int i = l;
    int j = m + 1;

    std::vector<int> temp;
    while ((i <= m) && (j <= r))
    {
        if (_stl2[i] <= _stl2[j])
        {
            temp.push_back( _stl2[i]);
            i++;
        }
        else
        {
            temp.push_back( _stl2[j]);
            j++;
        }
    }
    while (i <= m)
    {
        temp.push_back( _stl2[i]);
        i++;
    }
    while (j <= r)
    {
        temp.push_back( _stl2[i]);
        j++;
    }

    for (int p = l; p <= r; p++)
        _stl2[p] = temp[p - l];
}

void PmergeMe::pushStl1(int n)
{
    _stl1.push_back(n);
}

void PmergeMe::pushStl2(int n)
{
    _stl2.push_back(n);
}

void PmergeMe::displayStl1()
{
    for (size_t i = 0; i < _stl1.size(); i++)
        std::cout << _stl1[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::displayStl2()
{
    for (std::vector<int>::iterator it = _stl2.begin(); it != _stl2.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

std::deque<int>    PmergeMe::getStl1() const
{
    return (_stl1);
}

void        PmergeMe::setStl1(std::deque<int> stl1)
{
    _stl1 = stl1;
}

std::vector<int>    PmergeMe::getStl2() const
{
    return (_stl2);
}

void        PmergeMe::setStl2(std::vector<int>  stl2)
{
    _stl2 = stl2;
}

const char *PmergeMe::AlreadySorted::what() const throw()
{
    return("Numbers already sorted.");
}

const char *PmergeMe::RepeatedNumbers::what() const throw()
{
    return("Repeated numbers in the set.");
}
