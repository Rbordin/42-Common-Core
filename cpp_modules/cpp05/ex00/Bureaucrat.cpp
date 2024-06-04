/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:26:32 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/18 12:21:35 by rbordin          ###   ########.fr       */
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
			throw (gradeTooHighException());
		else
			throw (gradeTooLowException());
	}
	catch (gradeTooHighException &e){
		std::cerr << e.what() << std::endl;
	}
	catch (gradeTooLowException &e){
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat distructor called" << std::endl;
}
std::string	Bureaucrat::getName() const
{
	return (this->name);
}

int			Bureaucrat::getGrade() const
{
	return (this->grade);
}

void		Bureaucrat::setGrade(int i)
{
	this->grade = i;
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat &first)
{
	os << first.getName() << ", bureaucrat grade is " << first.getGrade() << std::endl;
	return (os);
}

int Bureaucrat::operator++(int grade)
{
	try{
		if (grade <= 1)
			throw (gradeTooHighException());
		else{
			grade--;
			this->setGrade(grade);}
	}
	catch (gradeTooHighException &e){
		std::cerr << e.what() << std::endl;
	}
	return (0);
}

int Bureaucrat::operator--(int grade)
{
	try{
		if (grade >=150)
			throw (gradeTooLowException());
		else{
			grade++;
			this->setGrade(grade);}
	}
	catch (gradeTooLowException &e){
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
