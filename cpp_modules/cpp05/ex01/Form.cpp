/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:13:14 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/18 12:22:22 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	:gradeRequiredToExecute(0), gradeRequiredToSign(0)
{
	std::cout << "base constructor called" << std::endl;
}
Form::Form(std::string const &name, int const to_sign, int const to_exec)
	:name(name), is_signed(0), gradeRequiredToExecute(to_sign), gradeRequiredToSign(to_exec)
{
	std::cout << "Form constructor called" << std::endl;
	try
	{
		if (to_sign < 1)
			throw (gradeToHighException());
		else if (to_sign > 150)
			throw (gradeToLowException());
	}
	catch (gradeToHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (gradeToLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		if (to_exec < 1)
			throw (gradeToHighException());
		else if (to_exec > 150)
			throw (gradeToLowException());
	}
	catch (gradeToHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (gradeToLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Form::~Form()
{
	std::cout << "destructor called" << std::endl;
}

std::string	Form::getName() const
{
	return (this->name);
}

int			Form::getSigned()
{
	return (this->is_signed);
}

int			Form::getGradeToSign() const
{
	return (this->gradeRequiredToSign);
}

int			Form::getGradeToExecute() const
{
	return (this->gradeRequiredToExecute);
}

void		Form::beSigned(Bureaucrat designed)
{
	try{
	if (this->is_signed == 0 && this->gradeRequiredToSign > designed.getGrade())
		this->is_signed = 1;
	else
		throw (gradeToHighException());
	}
	catch (gradeToHighException &e){
		std::cerr << "form can't be signed cause his " << e.what() << std::endl;
	}
}

void		Form::setSigned()
{
	this->is_signed = 1;
}

Form	&Form::operator=(Form const &src)
{
	*this = src;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, Form &module)
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