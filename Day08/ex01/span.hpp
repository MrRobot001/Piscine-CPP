/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 20:34:46 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/14 20:45:35 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_CLASS_HPP
#define SPAN_CLASS_HPP

#include <vector>

class Span
{
private:
	unsigned int n;
	std::vector<int> v;
public:
	Span(unsigned int _n);
	Span(const Span &obj);
	Span const &operator=(Span const &obj);
	~Span(void);

	void	addNumber(int numb);
	void	addVector(std::vector<int> &_v);

	long	shortestSpan(void);
	long	longestSpan(void);
};

#endif
