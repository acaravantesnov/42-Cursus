/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:09:12 by acaravan          #+#    #+#             */
/*   Updated: 2023/08/17 00:06:44 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    PmergeMe pmergeme;

    if (argc <= 2)
    {
        std::cerr << "Error: Wrong number of arguments." << std::endl;
		return (1);
    }

    try
    {
        // Save args into stl1.
        for (int i = 1; i < argc; i++)
            pmergeme.pushStl1(std::stoi(std::string(argv[i])));
        //Check if they are already sorted.
        if (pmergeme.isSorted())
            throw(PmergeMe::AlreadySorted());
    }
    catch(const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }

    // 1. Before Stl1.
    std::cout << "Before stl1: "; pmergeme.displayStl1();
    pmergeme.mergeSortDeque(0, pmergeme.getStl1().size() - 1);
    // 2. After Stl1.
    std::cout << "After stl1: "; pmergeme.displayStl1();

    for (int i = 1; i < argc; i++)
        pmergeme.pushStl2(std::stoi(std::string(argv[i])));

    // 1. Before Stl2.
    std::cout << "Before stl2: "; pmergeme.displayStl2();
    pmergeme.mergeSortVector(0, pmergeme.getStl2().size() - 1);
    // 2. After Stl2.
    std::cout << "After stl2: "; pmergeme.displayStl2();

    // Time to..
    /*std::cout << "Time to process a range of " << argc - 1 << " elements with \
    std::deque : " << t1 << " us." << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with \
    std::list : " << t2 << " us." << std::endl;*/
    return (0);
}
