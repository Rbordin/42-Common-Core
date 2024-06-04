/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:51:27 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/18 16:13:17 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.hpp"

int main()
{
	int n = 10;
	Array< int > intArray( n );
	Array< int > intArray2( n - 5 );
	Array <char> CharArray(5);

	CharArray[0]='c';
	CharArray[1]='a';
	CharArray[2]='c';
	CharArray[3]='c';
	CharArray[4]='a';

	for ( unsigned int i = 0; i < intArray.size(); i++ )
		intArray[i] = i;
	for ( unsigned int i = 0; i < intArray2.size(); i++ )
		intArray2[i] = (i*3);

	std::cout << "\nInt Array 1: " << intArray << std::endl;
	std::cout << "Int Array 2: " << intArray2 << std::endl;

	intArray2 = intArray;
	std::cout << "Int Array 2: " << intArray2 << std::endl;
	std::cout << "Char Array: " << CharArray << std::endl;
	try
	{
		std::cout << "Accessing a valid index: " << intArray[6] << std::endl;
		std::cout << "Accessing an invalid index: " << intArray2[n] << std::endl;
	}
	catch ( const std::exception &e )
	{
	   std::cerr << "\n\033[31m" << "Error: "  << e.what() << "\033[0m" << std::endl;
	}
	return ( 0 );
}
