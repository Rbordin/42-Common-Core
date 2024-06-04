/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:13:14 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/18 12:23:16 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
	:gradeRequiredToExecute(0), gradeRequiredToSign(0)
{
	std::cout << "AForm base constructor called" << std::endl;
}
AForm::AForm(std::string name, int to_sign, int to_exec)
	:name(name), is_signed(0), gradeRequiredToExecute(to_exec), gradeRequiredToSign(to_sign)
{
	std::cout << "Form constructor called" << std::endl;
	try
	{
		if (to_sign < 1)
			throw (GradeTooHighException());
		else if (to_sign > 150)
			throw (GradeTooLowException());
	}
	catch (GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		if (to_exec < 1)
			throw (GradeTooHighException());
		else if (to_exec > 150)
			throw (GradeTooLowException());
	}
	catch (GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

AForm::~AForm()
{
	std::cout << "destructor called" << std::endl;
}

std::string	AForm::getName() const
{
	return (this->name);
}

int			AForm::getSigned() const
{
	return (this->is_signed);
}

int			AForm::getGradeToSign() const
{
	return (this->gradeRequiredToSign);
}

int			AForm::getGradeToExecute() const
{
	return (this->gradeRequiredToExecute);
}

void		AForm::beSigned(Bureaucrat &designed)
{
	if (this->is_signed == 0 && this->gradeRequiredToSign > designed.getGrade())
		this->is_signed = 1;
	else
		GradeTooLowException();
	std::cout << this->is_signed;
}

void		AForm::setSigned()
{
	this->is_signed = 1;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (this->is_signed == 0)
	{
		std::cout << "can't execute cause it's not signed" << std::endl;
	}
	try
	{
		if (executor.getGrade() > this->getGradeToExecute())
			throw GradeTooLowException();
	}
	catch (GradeTooLowException &e)
	{
		std::cout << e.what() << "Form could not be executed by " << executor.getName() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &os, AForm &module)
{
	os << "form name: " + module.getName() << std::endl;
	if (module.getSigned() == 1)
		os << "form is already signed" << std::endl;
	else
		os << "form is yet to sign" << std::endl;
	os << "form minimum grade to sign is: " << module.getGradeToSign() << std::endl;
	os << "form minimum grade to execute is: " << module.getGradeToExecute() << std::endl;

	return (os);
}