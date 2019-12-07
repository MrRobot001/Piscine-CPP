/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:33:27 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/07 20:19:33 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

# include <iostream>

# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
	public:
		AssaultTerminator(void);
		AssaultTerminator(const AssaultTerminator &src);

		~AssaultTerminator(void);

		AssaultTerminator		&operator= (const AssaultTerminator &rhs);

		virtual void			battleCry(void) const;
		virtual void			meleeAttack(void) const;
		virtual void			rangedAttack(void) const;
		virtual ISpaceMarine	*clone(void) const;
};

#endif
