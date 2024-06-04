/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:01:00 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/18 12:05:56 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "allforms.hpp"

int main()
{
	Bureaucrat test("jack", 3);
	PresidentialPardonForm prova("test");
	
	std::cout << test.getName() << " = " << test.getGrade() << std::endl;
	test.operator++(test.getGrade());
	std::cout << test.getName() << " = " << test.getGrade() << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << prova.getGradeToSign() << " = " << prova.getGradeToExecute() << std::endl;
	
	prova.beSigned(test);
	std::cout << "-------------------" << std::endl;
	prova.execute(test);
}