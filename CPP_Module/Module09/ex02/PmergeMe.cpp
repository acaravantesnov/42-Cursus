/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:09:09 by acaravan          #+#    #+#             */
/*   Updated: 2023/08/15 20:42:24 by acaravan         ###   ########.fr       */
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

void merge(std::deque<int> &stl1, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;
    std::deque<int> Left(n1);
    std::deque<int> Right(n2);

    for (size_t i = 0; i < Left.size(); i++)
        Left[i] = stl1[left + i];
    for(size_t j = 0; j < Right.size(); j++)
        Right[j] = stl1[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (Left[i] <= Right[j]) {
            stl1[k] = Left[i];
            i++;
        } else {
            stl1[k] = Right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        stl1[k] = Left[i];
        i++;
        k++;
    }

    while (j < n2) {
        stl1[k] = Right[j];
        j++;
        k++;
    }
}

void mergeSortDeque(std::deque<int> &stl1, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        mergeSortDeque(stl1, left, middle);
        mergeSortDeque(stl1, middle + 1, right);
        merge(stl1, left, middle, right);
    }
}
