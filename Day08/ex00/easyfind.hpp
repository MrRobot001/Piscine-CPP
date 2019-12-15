/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 20:24:11 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/14 20:27:39 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
#define EASYFIND_H

#include <algorithm>
#include <exception>

template<typename T> int	easyfind(T &obj, int i)
{
	typename T::iterator it = std::find(obj.begin(), obj.end(), i);

	if (it == obj.end())
		throw std::exception();

	return *it;
}

#endif
