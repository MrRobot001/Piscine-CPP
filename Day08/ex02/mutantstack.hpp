/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 21:01:16 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/14 21:07:00 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T> class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void): std::stack<T>() {}
		virtual ~MutantStack(void) {}

		MutantStack(std::stack<T> const &obj): std::stack<T>(obj) {}
		MutantStack(MutantStack const &obj): std::stack<T>(obj) {}

		using std::stack<T>::operator=;

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin(void)
		{
			return std::begin(std::stack<T>::c);
		}

		iterator end(void)
		{
			return std::end(std::stack<T>::c);
		}
};

#endif
