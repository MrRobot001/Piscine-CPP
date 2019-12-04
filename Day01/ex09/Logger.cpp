/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 21:17:56 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/04 22:06:26 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

Logger::Logger(std::string _file) : file(_file) {}
Logger::~Logger(void) {}

std::string		Logger::makeLogEntry(std::string const &msg)
{
	std::stringstream ss;
	time_t	t = time(NULL);
	tm*		time_ptr = localtime(&t);

	ss << "[" << std::setw(2) << std::right << std::setfill('0') << time_ptr->tm_mday << "/" \
	<< std::setw(2) << std::right << std::setfill('0') << time_ptr->tm_mon + 1 << "/" \
	<< std::setw(2) << std::right << std::setfill('0') << time_ptr->tm_year + 1900 << " " \
	<< std::setw(2) << std::right << std::setfill('0') << time_ptr->tm_hour<< ":" \
	<< std::setw(2) << std::right << std::setfill('0') << time_ptr->tm_min<< "] " \
	<< msg << std::endl;

	return ss.str();
}

void			Logger::logToConsole(std::string const &msg)
{
	std::cout << makeLogEntry(msg);
}

void			Logger::logToFile(std::string const &msg)
{
	std::ofstream of(this->file);

	of << makeLogEntry(msg);
}

typedef void(Logger:: *log_in) (std::string const &);

void			Logger::log(std::string const &dest, std::string const &message)
{
	std::string field[COUNT_FIELD] = {"console", "file"};

	log_in	actions[COUNT_FIELD] = {
		&Logger::logToConsole,
		&Logger::logToFile
	};

	for (int i = 0; i < COUNT_FIELD; i++)
	{
		if (field[i].compare(dest) == 0)
			(this->*actions[i])(message);
	}
}

