/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:34:24 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/18 11:39:52 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout << "Base constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target+"_Shrubbery", 145, 137), target(target)
{
	std::cout << "Not base constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "destructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
        throw AForm::NotSigned();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::string filename = this->target + "_shrubbery";
    std::ofstream file(filename.c_str());

    if(file.is_open()){
             file << "   _-_     " << std::endl;
        file << " /~~    ~~     \\" << std::endl;
        file << "{               }" << std::endl;
        file << " \\  _-     -_  /" << std::endl;
        file << "      \\ \\ " << std::endl;
        file << "       | |" << std::endl;
        file << "       | |" << std::endl;
        file << "       |_|" << std::endl;

        file.close();
    }
    else
		std::cout << "Error: cannot open " << filename << std::endl;
}