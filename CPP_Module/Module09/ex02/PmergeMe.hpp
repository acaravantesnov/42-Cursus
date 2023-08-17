/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:09:06 by acaravan          #+#    #+#             */
/*   Updated: 2023/08/17 17:21:38 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <deque>
# include <vector>
# include <ctime>

class PmergeMe
{
    private:
        std::deque<int>     _stl1;
        std::vector<int>    _stl2;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &pmergeme);
        PmergeMe(std::deque<int> stl1, std::vector<int> stl2);
        ~PmergeMe();
        PmergeMe &operator=(PmergeMe &pmergeme);

        void checkIsSorted();
        void checkRepeatedNumbers();
        void mergeSortDeque(int l, int r);
        void mergeDeque(int l, int m, int r);
        void mergeSortVector(int l, int r);
        void mergeVector(int l, int m, int r);
        void pushStl1(int n);
        void pushStl2(int n);
        void displayStl1();
        void displayStl2();

        std::deque<int>             getStl1() const;
        void                        setStl1(std::deque<int> stl1);
        std::vector<int>            getStl2() const;
        void                        setStl2(std::vector<int>  stl2);

        class	AlreadySorted : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

        class	RepeatedNumbers : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

# endif
