/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:12:06 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/02 16:24:04 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string	uppercase(std::string str)
{
	size_t	i;

	i = -1;
	while (++i < str.size())
		str.at(i) = std::toupper(str.at(i));
	return (str);
}

int		main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	while (++i < argc)
		std::cout << uppercase(argv[i]);
	std::cout << std::endl;
	return (0);
}
