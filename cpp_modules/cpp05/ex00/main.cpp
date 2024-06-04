/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:01:00 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/18 12:21:40 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat test("jack", 1);
	Bureaucrat test2("riccardo", 6);
	
	std::cout << test.getName() << " = " << test.getGrade() << std::endl;
	std::cout << test2.getName() << " = " << test2.getGrade() << std::endl;
	test2.operator--(test2.getGrade());
	std::cout << test2.getName() << " = " << test2.getGrade() << std::endl;
	test.operator++(test.getGrade());
}