/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:09:12 by acaravan          #+#    #+#             */
/*   Updated: 2023/08/16 15:11:31 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    PmergeMe *pmergeme = new PmergeMe;

    if (argc <= 2)
    {
        std::cerr << "Error: Wrong number of arguments." << std::endl;
        delete (pmergeme);
		return (1);
    }

    try
    {
        // Save args into stl1.
        for (int i = 1; i < argc; i++)
            pmergeme->getStl1()->push_back(std::stoi(std::string(argv[i])));
        //Check if they are already sorted.
        if (isSorted(*pmergeme->getStl1()))
            throw(PmergeMe::AlreadySorted());
    }
    catch(const std::exception &e)
    {
        delete (pmergeme);
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }

    // 1. Before. Also copy contents of stl1 into stl2.
    std::cout << "Before: ";
    for (size_t i = 0; i < pmergeme->getStl1()->size(); i++)
    {
        std::cout << (*pmergeme->getStl1())[i] << " ";
        pmergeme->getStl2()->push_back((*pmergeme->getStl1())[i]);
    }
    std::cout << std::endl;

    // Merge Sort Algorithm
    mergeSortDeque(pmergeme->getStl1(), 0, pmergeme->getStl1()->size());

    // 2. After.
    std::cout << "After: ";
    for (size_t i = 0; i < pmergeme->getStl1()->size(); i++)
        std::cout << (*pmergeme->getStl1())[i] << " ";
    std::cout << std::endl;

    // Time to..
    /*std::cout << "Time to process a range of " << argc - 1 << " elements with \
    std::deque : " << t1 << " us." << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with \
    std::list : " << t2 << " us." << std::endl;*/
    return (0);
}
