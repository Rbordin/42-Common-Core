/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:45:04 by riccardobor       #+#    #+#             */
/*   Updated: 2023/09/15 10:52:01 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	Animal *zoo[50];
	for (int i = 0; i < 50; i++)
	{
		if (i % 2 == 0)
			zoo[i] = new Dog();
		else
			zoo[i] = new Cat();
	}
	
	delete j;//should not create a leak
	delete i;

	for (int i = 0; i < 50; i++)
	{
		if (i % 2 == 0)
			delete (zoo[i]);
		else
			delete (zoo[i]);
	}
	return 0;
}