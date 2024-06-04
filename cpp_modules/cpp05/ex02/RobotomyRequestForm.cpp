/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:40:18 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/18 11:32:48 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
	;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &name) : AForm(name + "Robotomize", 72, 45), target(name)
{
	;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else
	{
		if (rand() % 2 == 0)
			std::cout << target << " has been robotomized!" << std::endl;
		else
			std::cout << "Robotomy failed! " << target<< std::endl;
	}
}
