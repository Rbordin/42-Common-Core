/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:24:31 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/18 15:52:02 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <math.h>
# include <iostream>
# include <ctime>

class Base
{
	public:
		virtual ~Base(){};
};

class A : public Base
{
	public:
		~A(){};		
};

class B : public Base
{
	public:
		~B(){};	
};

class C : public Base
{
	public:
		~C(){};
};

Base	*generate(void)
{
    int casual = rand() % 3 + 1;
		
	switch (casual)
	{
		case 1:
			return (new A);
		case 2:
			return (new B);
		case 3:
			return (new C);
		default:
			std::cerr << "something went wrong" << std::endl;
	}
	return (NULL);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*> (p))
		std::cout << "type A" << std::endl;
	else if (dynamic_cast<B*> (p))
		std::cout << "type B" << std::endl;
	else if (dynamic_cast<C*> (p))
		std::cout << "type C" << std::endl;
	else
		std::cout << "none of this type has beeen created" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "type A" << std::endl;
		(void)a;
	}
	catch(const std::exception& e){}
	try
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "type B" << std::endl;
		(void)b;
	}
	catch(const std::exception& e){}
	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "type C" << std::endl;
		(void)c;
	}
	catch(const std::exception& e){}
}


#endif