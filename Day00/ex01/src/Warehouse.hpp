/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warehouse.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:40:48 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/03 13:41:24 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WAREHOUSE_HPP
#define WAREHOUSE_HPP
#include "PhoneContact.hpp"

class Warehouse
{
	private:
		int				count;
		PhoneContact	contacts[8];
	public:
		Warehouse(void);

		int				getCount(void) const;
		void			addContact(PhoneContact _contact);
		void			displayPhonebook(void) const;

		virtual			~Warehouse(void);
};

#endif
