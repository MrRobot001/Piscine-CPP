/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 21:54:35 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/05 21:54:35 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

Fixed	parsing(std::string str, int &pos);

Fixed	parsing_numb(std::string str, int &pos)
{
	Fixed	number;

	while (str.at(pos) == ' ')
		pos++;
	if (str.at(pos) == '(')
	{
		pos++;
		number = parsing(str, pos);
		if (str.at(pos) == ')')
			pos++;
		return (number);
	}

	std::stringstream ss(str.substr(pos));
	float res;
	ss >> res;
	pos += ss.tellg();
	return (Fixed(res));
}

Fixed	parsing_fact(std::string str, int &pos)
{
	Fixed	number1;
	Fixed	number2;
	char	symb;

	number1 = parsing_numb(str, pos);
	while ((size_t)pos < str.size())
	{
		while (str.at(pos) == ' ')
			pos++;
		symb = str.at(pos);
		if (symb != '/' && symb != '*')
			return (number1);
		pos++;
		number2 = parsing_numb(str, pos);
		if (symb == '/')
			number1 = number1 / number2;
		else if (symb == '*')
			number1 = number1 * number2;
	}
	return (number1);
}

Fixed	parsing(std::string str, int &pos)
{
	Fixed	number1;
	Fixed	number2;
	char	symb;

	number1 = parsing_fact(str, pos);
	while ((size_t)pos < str.size())
	{
		while (str.at(pos) == ' ')
			pos++;
		symb = str.at(pos);
		if (symb != '+' && symb != '-')
			return (number1);
		pos++;
		number2 = parsing_fact(str, pos);
		if (symb == '+')
			number1 = number1 + number2;
		else if (symb == '-')
			number1 = number1 - number2;
	}
	return (number1);
}

int		main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cout << "Please input: ./eval_expr \"expression\"" << std::endl;
		return (1);
	}
	int pos = 0;
	std::cout << parsing(argv[1]/*str*/, pos) << std::endl;
	return(0);
}
