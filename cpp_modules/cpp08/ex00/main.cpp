/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:02:33 by riccardobor       #+#    #+#             */
/*   Updated: 2023/09/23 13:06:25 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> test;

	test.resize(10);
	for (int i = 0; i < 20; i++)
	{
		if (i % 2 == 0)
			test.insert(test.begin() + i, i);
	}
	easyfind(test, 4);
	easyfind(test, 15);
}