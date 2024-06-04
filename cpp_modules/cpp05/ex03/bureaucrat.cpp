/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:26:32 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/18 12:24:39 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Base Bureaucrat costructor called" << std::endl;
}
Bureaucrat::Bureaucrat(std::string name, int i)
	: name(name)
{
	std::cout << "Bureaucrat costructor called" << std::endl;
	try
	{
		if (i >= 1 && i <= 150)
			this->grade = i;
		else if (i < 1)
			throw(GradeTooHighException());
		else if (i > 150)
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

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat distructor called" << std::endl;
}
std::string Bureaucrat::getName() const
{
	return (this->name);
}
int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::setGrade(int i)
{
	this->grade = i;
}

void Bureaucrat::signForm(AForm &to_sign)
{
	if (this->grade < to_sign.getGradeToSign())
	{
		std::cout << this->name << " signed " << to_sign.getName() << std::endl;
		to_sign.setSigned();
	}
	else
		std::cout << this->name << " couldn't sign " << to_sign.getName() << " because is grade is not high enough" << std::endl;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &first)
{
	os << first.getName() << ", bureaucrat grade is " << first.getGrade() << std::endl;
	return (os);
}

int Bureaucrat::operator++(int grade)
{
	try{
		grade--;
		if (grade < 150)
			this->setGrade(grade);
		else
			throw (GradeTooLowException());
	}
	catch (GradeTooLowException &e){
		std::cerr << e.what() << std::endl;
	}
	return (0);
}

int Bureaucrat::operator--(int grade)
{
	try{
		grade++;
		if (grade > 1)
			this->setGrade(grade);
		else
			throw (GradeTooHighException());
	}
	catch (GradeTooHighException &e){
		std::cerr << e.what() << std::endl;
	}
	return (0);
}