/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:02:23 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/18 12:24:44 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	protected:
		const	std::string name;
		int		grade;
	
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int i);
		~Bureaucrat();
		std::string	getName() const;
		int			getGrade() const;
		void		setGrade(int i);
		class	GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(void) {}
				virtual const char	*what() const throw() {
									return ("Error: Grade too high\n"); }
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(void) {}
				virtual const char	*what() const throw() {
									return ("Error: Grade too low\n"); }
		};
		int			operator++(int grade);
		int			operator--(int grade);
		void		signForm(AForm &to_sign);

};

std::ostream	&operator<<(std::ostream os, const Bureaucrat &first);
#endif