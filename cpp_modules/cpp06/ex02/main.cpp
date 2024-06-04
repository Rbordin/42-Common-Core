/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:15:30 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/18 15:50:45 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

void	identify(Base *p);
void	identify(Base &p);



int	main()
{
	Base *one = generate();
	Base *two = generate();
	Base *three = generate();
	Base *four = generate();


	std::cout << "one * = "; identify(one);
	std::cout << "one & = "; identify(*one);

	std::cout << "two * = "; identify(two);
	std::cout << "two & = "; identify(*two);

	std::cout << "three * = "; identify(three);
	std::cout << "three & = "; identify(*three);

	std::cout << "four * = "; identify(four);
	std::cout << "four & = "; identify(*four);

	delete one;
	delete two;
	delete three;
	delete four;

}