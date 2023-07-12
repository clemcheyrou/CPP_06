/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 22:52:50 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/05/23 23:11:56 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>

Base::~Base()
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Base*	Base::generate()
{
	srand(time(0));
	switch (rand() % 3)
	{
		case 0:
			return(new A());
		case 1:
			return(new B());
		case 2:
			return(new C());
		default:
			return (NULL);
	}
}

void	Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Le type est A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Le type est B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Le type est C" << std::endl;
	else
		std::cerr << "Le type est inconnu" << std::endl;
}

void	Base::identify(Base& p)
{
	identify(&p);
}