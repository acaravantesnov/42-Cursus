/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:23:44 by acaravan          #+#    #+#             */
/*   Updated: 2023/03/20 21:43:32 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	check_args(std::string argv1)
{
	if ((argv1.length() < 1) || (argv1[0] == ' ') || \
	(argv1[argv1.length() - 1] == ' '))
		return (false);
	return (true);
}

bool	isNumber(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		if (std::isdigit(str[i]) == 0)
			return (false);
	return (true);
}

bool	isOperator(const std::string &str)
{
	if (str.length() != 1)
		return (false);
	if ((str[0] != '+') && (str[0] != '-') && (str[0] != '*') && \
	(str[0] != '/'))
		return (false);
	return (true);
}

int	computeResult(char op, int a, int b)
{
	if (op == '+')
		return (b + a);
	else if (op == '-')
		return (b - a);
	else if (op == '*')
		return (b * a);
	else if (op == '/')
		return (b / a);
	return (0);
}

int main(int argc, char **argv)
{
	int				a, b;
	std::stack<int>	st;

	if (argc != 2)
	{
		std::cout << "Error: Wrong number of arguments." << std::endl;
		return (1);
	}
	else if(!check_args(std::string(argv[1])))
	{
		std::cout << "Error: Wrong input format." << std::endl;
		return (1);
	}

	int			i = 0;
	int			nOperands = 0;
	std::string	s;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] != ' ') // Add character to token.
			s += argv[1][i];
		else
		{
			if (isNumber(s)) // If it is a number
			{
				if (nOperands >= 10)
				{
					std::cout << "Error: Too many operands." << std::endl;
					return (1);
				}
				st.push(stoi(s)); std::cout << "Pushed " << stoi(s) << std::endl;
				nOperands++;
			}
			else if (isOperator(s)) // If it is an operator
			{
				a = st.top(); std::cout << "Popped " << a << std::endl;
				st.pop();
				b = st.top(); std::cout << "Popped " << b << std::endl;
				st.pop();
				st.push(computeResult(s[0], a, b)); std::cout << "Pushed " << computeResult(s[0], a, b) << std::endl;
				std::cout << "Operator " << s[0] << " result " << computeResult(s[0], a, b) << std::endl;
			}
			else
			{
				std::cout << "Error: Invalid character." << std::endl;
				return (1);
			}
			s.clear();
		}
		i++;
	}
	std::cout << st.top() << std::endl;
	return (0);
}
