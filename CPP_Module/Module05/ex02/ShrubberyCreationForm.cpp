/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:51:59 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/12 23:54:38 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :\
Form(target, 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm \
&scf)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::ofstream	fileWrite;
	fileWrite.open(this->getName() + "_shrubbery", std::ios::out);
	/*std::string	ascii_tree = \
	R"(            .        +          .      .          .
		.            _        .                    .
	,              /;-._,-.____        ,-----.__
	((        .    (_:#::_.:::. `-._   /:, /-._, `._,
	`                 \   _|`=:_::.`.);  \ __/ /
						,    `./  \:. `.   )==-   .
		.      ., ,-=-.  ,\, +#./`   \:.  / /           .
	.           \/:/`-  , ,\  ` ` `   ): , /_  -o
		.    /:+- - + +- : :- + + -:   /(o-) \)     .
	.      ,= :  \    ` `/`   , , ,:  ` -- .-- ---._/`7
	`.   (    \: \,-._` ` +  \, ,    _,--._,--- :.__/
				\:  `  X` _| _,\/    .-
	.                :._:`\____  /:   /      .           .
						\::.  :\/:   /              +
	.                 `.:.  /:   }      .
			.           ):_(:;   \           .
						/:. _/ ,  |
					. (|::.     ,`                  .
		.                |::.    {\
						|::.\  \ `.
						|:::(\    |
				O       |:::/{ }  |                  (o
				)  ___/#\::`/ (O  ==._____   O, (O  /`
			~~~w/w~ ~~,\` `:/,-(~` ~~~~~~~~ ~o~\~/~w|/~
	dew   ~~~~~~~~~~~~~~~~~~~~~~~\\W~~~~~~~~~~~~\|/~~)";
	fileWrite << ascii_tree;
	fileWrite.close();*/
}
