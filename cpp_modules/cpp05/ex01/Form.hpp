/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:06:11 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/18 12:22:41 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const		std::string name;
		int			is_signed;
		const int	gradeRequiredToExecute;
		const int	gradeRequiredToSign;
	
	public:
		Form();
		Form(std::string const &name, int const to_sign, int const to_exec);
		~Form();
		Form		&operator=(Form const &src);
		std::string	getName() const;
		int			getSigned();
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		void		setSigned();
		void		beSigned(Bureaucrat designed);
		class gradeToHighException : public std::exception
		{
			public:
				const char	*what(void) const throw()
				{
					return ("grade is too high");
				}
		};
		class gradeToLowException : public std::exception
		{
			public:
				const char	*what(void) const throw()
				{
					return ("grade is too low");
				}
		};

};

std::ostream	&operator<<(std::ostream &os, Form &module);
#endif