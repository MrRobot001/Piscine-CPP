/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 19:22:30 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/04 20:12:15 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

int		main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Bad input. Use: ./replace [file] [s1] [s2]" << std::endl;
		return (1);
	}

	std::string		file = argv[1];
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];

	std::ifstream	fs(file);
	if (!fs.good())
	{
		std::cout << "\"" << file << "\" could not open" << std::endl;
		return (1);
	}

	if (s1.empty())
	{
		std::cout << "Error: " << s1 << " is empty" << std::endl;
		return (1);
	}

	if (s2.empty())
	{
		std::cout << "Error: " << s2 << " is empty" << std::endl;
		return (1);
	}

	std::stringstream	_buf;
	std::string			content;

	_buf << fs.rdbuf();
	content = _buf.str();

	size_t		finder;
	while ((finder = content.find(s1)) != std::string::npos)
		content.replace(finder, s1.length(), s2);

	std::ofstream of(file + ".replace");

	if (!of.good())
	{
		std::cout << "\"" << file << ".replace\" could not open" << std::endl;
		return (1);
	}

	of << content;
	of.close();
	return (0);
}
