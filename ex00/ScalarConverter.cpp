/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:26:05 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/05/23 13:27:28 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <float.h>
#include <limits.h>

ScalarConverter::ScalarConverter()
{
	std::cout << "Constructer called" << std::endl;
	return;
};

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
	*this = copy;
	return;
};

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
	return;
};

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return (*this);
};

bool ScalarConverter::isChar(std::string &type)
{
	std::istringstream iss(type);
	float tmp;
	if (!((iss >> tmp) && (iss.eof())) && type.length() == 1)
	{
		std::cout << "\033[1;34mIt's a char\033[0m" << std::endl;
		char c;
		std::istringstream oss(type);
		oss >> c;
		std::cout << "char : " << c << std::endl;
		std::cout << "int : " << static_cast<int>(c) << std::endl;
		std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double : " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
		return (true);
	}
	else
		return (false);
};

bool ScalarConverter::isInt(std::string &type)
{
	std::istringstream iss(type);
	int i;
	if ((iss >> i) && (iss.eof()))
	{
		std::cout << "\033[1;34mIt's an int\033[0m" << std::endl;
		if (static_cast<int>(i) > 31 && static_cast<int>(i) < 127)
			std::cout << "char : " << static_cast<char>(i) << std::endl;
		else if ((static_cast<int>(i) > -1 && static_cast<int>(i) < 32) || static_cast<int>(i) == 127)
			std::cout << "char : Non displayable" << std::endl;
		else
			std::cout << "char : impossible" << std::endl;
		std::cout << "int : " << i << std::endl;
		std::cout << "float : " << std::fixed << std::setprecision(2) << static_cast<float>(i) << "f" << std::endl;
		std::cout << "double : " << std::fixed << std::setprecision(2) << static_cast<double>(i) << std::endl;
		return (true);
	}
	else if ((i >= 2147483647 || i <= -2147483648) && type.find(".") == std::string::npos)
		return (std::cout << "overflow" << std::endl, true);
	else
		return (false);
};

bool ScalarConverter::isFloat(std::string &type)
{
	std::string tmp;
	tmp = type;
	if (tmp.substr(tmp.size() - 1) == "f" && tmp.find(".") != std::string::npos)
		type = type.substr(0, type.size() - 1);
	else
		return (false);
	std::istringstream iss(type);
	float f;
	if ((iss >> f) && (iss.eof()))
	{
		std::cout << "\033[1;34mIt's a float\033[0m" << std::endl;
		if (static_cast<int>(f) > 31 && static_cast<int>(f) < 127)
			std::cout << "char : " << static_cast<char>(f) << std::endl;
		else if ((static_cast<int>(f) > -1 && static_cast<int>(f) < 32) || static_cast<int>(f) == 127)
			std::cout << "char : Non displayable" << std::endl;
		else
			std::cout << "char : impossible" << std::endl;
		if (static_cast<int>(f) < INT_MIN || static_cast<int>(f) > INT_MAX)
			std::cout << "int : impossible" << std::endl;
		else
			std::cout << "int : " << static_cast<int>(f) << std::endl;
		std::cout << "float : " << std::fixed << std::setprecision(2) << f << "f" << std::endl;
		std::cout << "double : " << std::fixed << std::setprecision(2) << static_cast<double>(f) << std::endl;
		return (true);
	}
	else if (f < FLT_MAX || f > FLT_MIN)
		return (std::cout << "overflow" << std::endl, true);
	else
		return (false);
};

bool ScalarConverter::isDouble(std::string &type)
{
	if (type.find(".") == std::string::npos)
		return (false);
	std::istringstream iss(type);
	double d;
	if ((iss >> d) && (iss.eof()))
	{
		std::cout << "\033[1;34mIt's a double\033[0m" << std::endl;
		if (static_cast<int>(d) > 31 && static_cast<int>(d) < 127)
			std::cout << "char : " << static_cast<char>(d) << std::endl;
		else if ((static_cast<int>(d) > -1 && static_cast<int>(d) < 32) || static_cast<int>(d) == 127)
			std::cout << "char : Non displayable" << std::endl;
		else
			std::cout << "char : impossible" << std::endl;
		if (static_cast<int>(d) <= INT_MIN || static_cast<int>(d) >= INT_MAX)
			std::cout << "int : impossible" << std::endl;
		else
			std::cout << "int : " << static_cast<int>(d) << std::endl;
		if (static_cast<float>(d) <= FLT_MIN || static_cast<int>(d) >= FLT_MAX)
			std::cout << "float : impossible" << std::endl;
		else
			std::cout << "float : " << std::fixed << std::setprecision(2) << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double : " << std::fixed << std::setprecision(2) << d << std::endl;
		return (true);
	}
	else if (d < DBL_MAX || d > DBL_MIN)
		return (std::cout << "overflow" << std::endl, true);
	return (false);
};

bool ScalarConverter::isPseudoLit(std::string &type)
{
	if (type == "nan" || type == "-inf" || type == "+inf")
	{
		std::cout << "It's impossible" << std::endl;
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : " << type << "f" << std::endl;
		std::cout << "double : " << type << std::endl;
		return (true);
	}
	if (type == "nanf" || type == "-inff" || type == "+inff")
	{
		std::cout << "It's impossible" << std::endl;
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : " << type << std::endl;
		std::cout << "double : " << type.substr(0, type.size() - 1) << std::endl;
		return (true);
	}
	return (false);
};

void ScalarConverter::convert(std::string type)
{
	if (isPseudoLit(type))
		return;
	else if (isChar(type))
		return;
	else if (isInt(type))
		return;
	else if (isFloat(type))
		return;
	else if (isDouble(type))
		return;
	else
		return (std::cout << "Wrong input" << std::endl, (void)0);
};