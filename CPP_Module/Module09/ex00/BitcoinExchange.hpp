/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:09:36 by acaravan          #+#    #+#             */
/*   Updated: 2023/08/18 20:07:21 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <list>
# include <algorithm>
# include <ctime>
# include <sstream>

class BitcoinExchange
{
    private:
        std::list<std::string>	_date;
        std::list<float>		_value;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &data);
        BitcoinExchange(const std::list<std::string> date, const std::list<float> value);
        ~BitcoinExchange();
        BitcoinExchange &operator=(BitcoinExchange &data);

        int     compareNext(int y2, int m2, int d2, int y3, int m3, int d3);
        void    pushData(std::string date, float value);
        void    processDataFile(int argc);
        void    processInputFile(std::string argv1);

        std::list<std::string>  getDate() const;
        void                    setDate(std::list<std::string> date);
        std::list<float>        getValue() const;
        void                    setValue(std::list<float> value);

        class   InvalidNumberofArgs : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

        class   DataFileMissing : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class	InputFileMissing : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
