/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:48:22 by acaravan          #+#    #+#             */
/*   Updated: 2023/08/15 15:24:59 by acaravan         ###   ########.fr       */
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


int main(int argc, char **argv)
{
	int				a, b;
    char            op;
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
            st.push(args[j]);
        else if (((args[j]) == 42) || ((args[j]) == 47) || ((args[j]) == 43) || \
                ((args[j]) == 45))
            b = st.top(); st.pop();
            a = st.top(); st.pop(); 
    }
	
    delete[](args);
	return (0);
}
