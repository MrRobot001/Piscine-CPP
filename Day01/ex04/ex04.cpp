/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:28:36 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/04 16:32:28 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int		main(void)
{
	std::string str = "HI THIS IS BRAIN";

	std::string *strPtr = &str;
	std::string &strRef = str;

	std::cout << *strPtr << std::endl;
	std::cout << strRef << std::endl;

	return (0);
}
