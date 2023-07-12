/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:39:39 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/05/23 22:41:52 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Constructor called" << std::endl;
	return;
};

Serializer::Serializer( Serializer const &copy )
{
	*this = copy;
};

Serializer::~Serializer()
{
	std::cout << "Destructor called" << std::endl;
	return;
};

Serializer& Serializer::operator=( Serializer const & rhs )
{
	if (this != &rhs)
		*this = rhs;
	return (*this);
};

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
};

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
};