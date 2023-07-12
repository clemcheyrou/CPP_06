/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:22:50 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/05/23 13:25:11 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

class ScalarConverter
{
private:

public:

	ScalarConverter( void );
	ScalarConverter( ScalarConverter const &copy );
	~ScalarConverter( void );

	ScalarConverter& operator=( ScalarConverter const & rhs );
	
	static bool isChar( std::string & type );
	static bool isInt( std::string & type );
	static bool isFloat( std::string & type );
	static bool isDouble( std::string & type );
	static bool	isPseudoLit( std::string & type );

	static void convert( std::string type );

};

#endif