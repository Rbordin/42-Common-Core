/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:19:26 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/18 12:13:25 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	;
}

Intern::~Intern()
{
	;
}

AForm	*Intern::makeForm(std::string form, std::string target)
{
	char temp;
	int flag = 0;
	AForm	*res = NULL;
	std::string	formNames[3] = {"Robotomy", "Shrubbery", "Presidential"};
	
	for (int i = 0; i < 3; i++)
	{
		for (unsigned long j = 0; j < form.size(); j++)
		{
			if (std::toupper(form[j]) == std::toupper(formNames[i][j]))
				flag = 1;
		}
	}
	if (flag == 1)
		temp = std::toupper(form[0]);
	switch (temp)
	{
		case 'R':
			res = new RobotomyRequestForm(target);
			break;
		case 'S':
			res = new ShrubberyCreationForm(target);
			break;
		case 'P':
			res = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << "can't find any actual form called " + form << std::endl;
			break;
	}
	if (res != NULL)
		std::cout << "Intern creates " + form << std::endl;
	return (res);
}
