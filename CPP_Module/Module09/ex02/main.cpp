/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:09:12 by acaravan          #+#    #+#             */
/*   Updated: 2023/08/17 17:28:50 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    PmergeMe    pmergeme;

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
        pmergeme.checkIsSorted();
        //pmergeme.checkRepeatedNumbers();
    }
    catch(const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }

    // 1. Before.
    std::cout << "Before: "; pmergeme.displayStl1();
    clock_t start1 = clock();
    pmergeme.mergeSortDeque(0, pmergeme.getStl1().size() - 1);
    clock_t end1 = clock();
    // 2. After.
    std::cout << "After: "; pmergeme.displayStl1();

    for (int i = 1; i < argc; i++)
        pmergeme.pushStl2(std::stoi(std::string(argv[i])));

    clock_t start2 = clock();
    pmergeme.mergeSortVector(0, pmergeme.getStl2().size() - 1);
    clock_t end2 = clock();

    // Time to..
    std::cout << "Time to process a range of " << argc - 1 << \
    " elements with std::deque : " << \
    static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000000 << \
    " us." << std::endl;

    std::cout << "Time to process a range of " << argc - 1 << \
    " elements with std::list : " << \
    static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000000 << \
    " us." << std::endl;
    return (0);
}
