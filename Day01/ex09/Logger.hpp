/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 21:17:55 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/04 22:03:17 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_CLASS_HPP
#define LOGGER_CLASS_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iomanip>
#define		COUNT_FIELD 2

class Logger
{
	private:
		std::string		file;
		void			logToConsole(std::string const &msg);
		void			logToFile(std::string const &msg);
		std::string		makeLogEntry(std::string const &msg);
	public:
		Logger(std::string _file);
		~Logger(void);

		void			log(std::string const &dest, std::string const &message);
};

#endif
