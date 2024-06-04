/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:06:11 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/18 12:24:34 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const		std::string name;
		int			is_signed;
		const int	gradeRequiredToExecute;
		const int	gradeRequiredToSign;
	
	public:
		AForm();
		AForm(std::string name, int to_sign, int to_exec);
		virtual ~AForm();
		std::string		getName() const;
		int				getSigned() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;
		void			setSigned();
		void			beSigned(Bureaucrat &designed);
		virtual void	execute(Bureaucrat const &executor) const = 0;
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw() {
									return ("Error: Grade too high\n"); }
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw() {
									return ("Error: Grade too low\n"); }
		};
		class	NotSigned : public std::exception
		{
			public:
				virtual const char	*what() const throw() {
									return ("Error: form not signed\n"); }
		};
};

std::ostream	&operator<<(std::ostream &os, AForm &module);
#endif