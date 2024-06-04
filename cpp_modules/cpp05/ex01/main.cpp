/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:01:00 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/18 12:22:48 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat test("jack", 14);
	Form		prova("prova", 1, 149);
	Form		prova2("prova2", 15, 50);
	
	std::cout << test.getName() << " = " << test.getGrade() << std::endl;
	test.operator++(test.getGrade());
	std::cout << test.getName() << " = " << test.getGrade() << std::endl;
	std::cout << prova << std::endl;
	std::cout << "-------------------" << std::endl;
	
	prova.beSigned(test);
	prova2.beSigned(test);
	std::cout << prova << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << prova2 << std::endl;
}