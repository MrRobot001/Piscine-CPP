/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:50:22 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/12 20:59:11 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

void *serialize(void)
{
	std::srand(time(0));

	char *str = new char[16 + sizeof(int)];
	char alnum[63] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXY\
Z0123456789";

	for(int i = 0; i < 8; i++)
		str[i] = alnum[std::rand() % 62];

	*reinterpret_cast<int *>(str + 8) = std::rand();

	for(int i = 0; i < 8; i++)
		str[i + 8 + sizeof(int)] = alnum[std::rand() % 62];

	return str;
}

struct Data *deserialize(void *raw)
{
	Data *data = new Data();

	char *str = reinterpret_cast<char *>(raw);

	data->s1 = std::string(str, 8);
	data->n = *reinterpret_cast<int *>(str + 8);
	data->s2 = std::string(str + 8 + sizeof(int), 8);

	return data;
}

int main(void)
{
	void *raw = serialize();

	if (raw == NULL)
	{
		std::cout << "Failed to allocate memory" << std::endl;
		return (1);
	}

	Data *data = deserialize(raw);

	unsigned char *str = reinterpret_cast<unsigned char *>(raw);

	std::cout << "Raw bytes:" << std::endl;
	for (size_t i = 0; i < 16 + sizeof(int); i++)
		std::cout << std::hex << std::showbase << +str[i] << " ";
	std::cout << std::endl << std::endl;


	std::cout << "Deserialized data:" << std::endl;
	std::cout << "s1: \"" << data->s1 << "\"" << std::endl;
	std::cout << "n:  " << std::dec << data->n << std::endl;
	std::cout << "s2: \"" << data->s2 << "\"" << std::endl;

	delete data;
	delete str;

	return 0;
}
