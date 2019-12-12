/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:50:16 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/12 20:51:48 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <cfloat>
#include <iomanip>

#define MIN_INT		-2147483648
#define MAX_INT		2147483647
#define MIN_FL		-2147483648.0
#define MAX_FL		2147483647.0
#define MIN_DBL		-9223372036854775808.0
#define MAX_DBL		9223372036854775807.0

int		main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cout << "use ./convert \"str\"" << std::endl;
		return (1);
	}

	std::string str = argv[1];

	for (size_t i = 0; i < str.length(); i++)
		str.at(i) = std::tolower(str.at(i));

	bool isHex = (str.compare(0, 2, "0x") == 0);
	bool isInf = (str.compare(0, str.length(), "inf") == 0 ||
				str.compare(0, str.length(), "-inf") == 0 ||
				str.compare(0, str.length(), "+inf") == 0);
	bool isPoint = (str.find(".") != std::string::npos);
	bool isOctal = (!isHex && !isPoint && str.compare(0, 1, "O") == 0);

	if (!isHex && !isInf && str.at(str.length() - 1) == 'f')
		str = str.substr(0, str.length() - 1);

	long double val;

	if (str.length() == 3 && str.at(0) == '\'' && str.at(2) == '\'')
		val = static_cast<int>(str.at(1));
	else
	{
		std::istringstream ss(str);
		if (isOctal)
		{
			long octal;
			ss >> std::oct >> octal;
			val = octal;
		}
		else
			ss >> val;
	}
	if (isinf(val) || isnan(val) || val < MIN_INT || val > MAX_INT)
		std::cout << "char: Impossible" << std::endl;
	else if (std::isprint(static_cast<char>(val)))
		std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
	else
		std::cout << "char: Not displayable" << std::endl;

	if (isinf(val) || isnan(val) || val < INT_MIN || val > INT_MAX)
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(val) << std::endl;


	if (!(isinf(val) || isnan(val)) && (val < MIN_FL || val > MAX_FL))
		std::cout << "float: Impossible" << std::endl;
	else
		std::cout << "float: " << std::setprecision(1) << std::fixed
			<< static_cast<float>(val) << "f" << std::endl;


	if (!(isinf(val) || isnan(val)) && (val < MIN_DBL || val > MAX_DBL))
		std::cout << "double: Impossible" << std::endl;
	else
		std::cout << "double: " << std::setprecision(1) << std::fixed
			<< static_cast<double>(val) << std::endl;

	return (0);
}
