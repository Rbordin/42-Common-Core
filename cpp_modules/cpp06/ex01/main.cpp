/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:53:49 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/18 15:44:31 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Serializer	gino;
	Data		obj;
	obj.data = 42;
    std::cout << "Address of original object (obj): " << &obj << std::endl;
	uintptr_t ptrSer = gino.serialize(&obj);
	std::cout << "ptrSer: " << ptrSer << std::endl;
	Data* ptrDes = gino.deserialize(ptrSer);
	std::cout << "ptrDes: " << ptrDes << std::endl;
	return (0);
}