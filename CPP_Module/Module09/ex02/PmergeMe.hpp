/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:09:06 by acaravan          #+#    #+#             */
/*   Updated: 2023/08/15 20:42:39 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <deque>
# include <list>

class PmergeMe
{
    private:
        std::deque<int> *_stl1;
        std::list<int>  *_stl2;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &pmergeme);
        PmergeMe(std::deque<int> *stl1, std::list<int>  *stl2);
        ~PmergeMe();
        PmergeMe &operator=(PmergeMe &pmergeme);

        std::deque<int> *getStl1() const;
        void            setStl1(std::deque<int> *stl1);
        std::list<int>  *getStl2() const;
        void             setStl2(std::list<int>  *stl2);

        class	AlreadySorted : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

bool isSorted(const std::deque<int> &d);
void mergeSortDeque(std::deque<int> &stl1, int left, int right);
void merge(std::deque<int> &stl1, int left, int middle, int right);

# endif
