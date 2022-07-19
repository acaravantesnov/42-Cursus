/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 02:53:05 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/19 03:49:54 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template<typename T>
class	MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		MutantStack();
		MutantStack(MutantStack const &mutantstack);
		~MutantStack();
		MutantStack<T>	&operator=(MutantStack<T> const &mutantstack);

		iterator				begin();
		const_iterator			begin() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;
};

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template<typename T>
MutantStack<T>::MutantStack(MutantStack const &mutantstack) {*this = mutantstack;}

template<typename T>
MutantStack<T>::~MutantStack() {}

template<typename T>
MutantStack<T>	&MutantStack<T>::operator=(MutantStack<T> const &mutantstack)
{
	if (this != &mutantstack)
		this->c = mutantstack.c;
	return (*this);
}

template<typename T>
typename MutantStack<T>::iterator				MutantStack<T>::begin()
{return (this->c.begin());}

template<typename T>
typename MutantStack<T>::const_iterator			MutantStack<T>::begin() const
{return (this->c.begin());}

template<typename T>
typename MutantStack<T>::reverse_iterator		MutantStack<T>::rbegin()
{return (this->c.rbegin());}

template<typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rbegin() const
{return (this->c.rbegin());}

template<typename T>
typename MutantStack<T>::iterator				MutantStack<T>::end()
{return (this->c.end());}

template<typename T>
typename MutantStack<T>::const_iterator			MutantStack<T>::end() const
{return (this->c.end());}

template<typename T>
typename MutantStack<T>::reverse_iterator		MutantStack<T>::rend()
{return (this->c.rend());}

template<typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rend() const
{return (this->c.rend());}

#endif
