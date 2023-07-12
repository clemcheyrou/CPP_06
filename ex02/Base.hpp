/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 22:46:48 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/05/23 22:49:52 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

# include <iostream>

class Base
{
private:

public:

	virtual ~Base( void );

	static Base	*generate(void);
	static void	identify(Base* p);
	static void	identify(Base& p);

};

#endif