/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:48:22 by acaravan          #+#    #+#             */
/*   Updated: 2023/08/15 18:04:43 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    RPN *rpn = new RPN;
	int a, b, result;

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

    std::string argv1 = std::string(argv[1]);
    char        *args = new char[argv1.size() - (argv1.size() / 2)];

    size_t  j = 0;
    for (size_t i = 0; i < argv1.size(); i++)
    {
        if (argv1[i] != ' ')
        {
            args[j] = argv1[i];
            j++;
        }
    }

    for (j = 0; j < argv1.size() - (argv1.size() / 2); j++)
    {
        if ((args[j] > 47) && (args[j] < 58))
            rpn->getSt()->push(args[j] - 48);
        else if (((args[j]) == '*') || ((args[j]) == '/') || \
        ((args[j]) == '+') || ((args[j]) == '-'))
        {
            b = rpn->getSt()->top(); rpn->getSt()->pop();
            a = rpn->getSt()->top(); rpn->getSt()->pop();
            if (args[j] == '*')
                result = a * b;
            else if (args[j] == '/')
                result = a / b;
            else if (args[j] == '+')
                result = a + b;
            else if (args[j] == '-')
                result = a - b;
            rpn->getSt()->push(result);
        }
    }

    std::cout << rpn->getSt()->top() << std::endl;
	
    delete(rpn);
    delete[](args);
	return (0);
}
