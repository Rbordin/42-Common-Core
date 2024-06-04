/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:48:57 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/18 11:37:55 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "allforms.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
	;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 25, 2)
{
	;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if ( executor.getGrade() > this->getGradeToExecute() )
		throw AForm::NotSigned();
	else
		std::cout << "Dear " + this->getName() + ". We are glad to announce that you have been pardoned by Zaphod Beeblebrox." << std::endl;
}