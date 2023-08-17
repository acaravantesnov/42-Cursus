/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:09:36 by acaravan          #+#    #+#             */
/*   Updated: 2023/08/16 19:44:12 by acaravan         ###   ########.fr       */
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
        std::string	_date;
        float		_value;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &data);
        BitcoinExchange(const std::string date, const float value);
        ~BitcoinExchange();
        BitcoinExchange &operator=(BitcoinExchange &data);

        std::string   getDate() const;
        void          setDate(std::string date);
        float         getValue() const;
        void          setValue(float value);
};

#endif
