/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 22:13:37 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/04 22:34:28 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<string>
#include	<iostream>
#include	<fstream>

void	wr_pipe_stream(std::istream &input)
{
	std::cout << input.rdbuf();
}

int		main(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && std::string(argv[1]).compare("--") == 0))
	{
		wr_pipe_stream(std::cin);
		return (0);
	}

	for (int i = 1; i < argc; i++)
	{
		std::string arg = argv[i];
		if (i == 1 && arg.compare("--") == 0)
			continue;
		if (arg.compare("-") == 0)
			wr_pipe_stream(std::cin);
		else
		{
			std::ifstream fs(arg);

			if (fs.good())
				wr_pipe_stream(fs);
			else
				std::cerr << argv[0] << ": " << arg << ": "
					<< strerror(errno) << std::endl;
		}
	}
	return (0);
}
