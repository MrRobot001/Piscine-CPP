/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:30:47 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/11 20:35:32 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CENTRALBUREAUCRACY_CLASS_H
# define CENTRALBUREAUCRACY_CLASS_H

# include "Bureaucrat.hpp"
# include "OfficeBlock.hpp"

class CentralBureaucracy
{
	public:
		CentralBureaucracy(void);
		CentralBureaucracy(CentralBureaucracy& rhs);
		~CentralBureaucracy(void);

		CentralBureaucracy& operator=(CentralBureaucracy& rhs);

		void hire(Bureaucrat *b);
		void queueUp(std::string target);
		void doBureaucracy(void);
	private:
		OfficeBlock _blocks[20];
		std::string _queue[50];
};

#endif
