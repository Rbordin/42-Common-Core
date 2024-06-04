/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:51:50 by riccardobor       #+#    #+#             */
/*   Updated: 2023/10/03 10:44:39 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char	**argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int x = 1; argv[x]; x++)
		{
			for (int y = 0; argv[x][y]; y++)
				std::cout << (char)std::toupper(argv[x][y]);
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}