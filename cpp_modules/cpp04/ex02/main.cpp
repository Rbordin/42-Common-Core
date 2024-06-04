/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:45:04 by riccardobor       #+#    #+#             */
/*   Updated: 2023/09/15 12:02:56 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"

int main()
{
	const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };

	for ( int i = 0; i < 4; i++ )
		animals[i]->makeSound();
	for ( int i = 0; i < 4; i++ )
		delete (animals[i]);
	return (0);
}