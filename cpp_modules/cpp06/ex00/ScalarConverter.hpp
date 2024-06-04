/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:06:07 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/18 14:49:58 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <cctype>
# include <cstring>
# include <limits>
# include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		static void convertChar(char c);
		static bool isSpecialType(const std::string& str);
		static void convertSpecialType(const std::string& str);
		static bool isValidNumber(const std::string& str);
		static void convertNumber(const std::string& str);
    
	public:
		ScalarConverter();
		~ScalarConverter();
		void convert(const std::string& str);
};

#endif