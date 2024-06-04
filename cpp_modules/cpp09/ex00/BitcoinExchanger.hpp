/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchanger.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:42:15 by riccardobor       #+#    #+#             */
/*   Updated: 2023/10/30 13:42:31 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <utility>

class	BitcoinExchanger
{
	private:
    	std::map<std::string, float>    moltiplier;
	public:
		BitcoinExchanger(void);
		~BitcoinExchanger();
		BitcoinExchanger(const BitcoinExchanger &toCopy);
		std::map<std::string, float>	getMap();
		float	getValue(std::string date);
		BitcoinExchanger	&operator=(const BitcoinExchanger &toCopy);
		void	generateExchanger(void);
		void	checker(std::map<std::string, float> toCheck);
		class	badValueExecption : public std::exception
		{
			private:
				int _case;
			public:
				badValueExecption(int i): _case(i){};
				const char	*what(void) const throw()
				{
					switch (this->_case)
					{
						case 0:
							return ("Error: not a positive number");
						case 1:
							return ("Error: too large input");
						default:
							return ("something went wrong");
					}
				}
		};
		class	badInputException : public std::exception
		{
			public:
				const char	*what(void) const throw()
				{
					return ("Error: bad input");
				}
		};
};

#endif