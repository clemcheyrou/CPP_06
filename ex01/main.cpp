/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:44:44 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/05/23 22:44:36 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"

int main()
{
	Data *ptr = new Data;
	Data *tmp;
	uintptr_t	raw;

	ptr->nb = 2;
	raw = Serializer().serialize(ptr);
	tmp = Serializer().deserialize(raw);
	std::cout << "ptr = " << ptr->nb << std::endl;
	std::cout << "tmp = " << ptr->nb << std::endl;
	delete ptr;
}

