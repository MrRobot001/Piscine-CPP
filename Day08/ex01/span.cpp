/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 20:34:48 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/14 20:57:20 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(unsigned int _n) : n(_n)
{
	v.reserve(n);
}

Span::Span(const Span &obj)
{
	*this = obj;
}

Span::~Span(void)
{
	std::vector<int>().swap(this->v);
}

Span const &Span::operator=(Span const &obj)
{
	if (this->v == obj.v)
		return *this;

	this->v = obj.v;
	this->n = obj.n;

	return *this;
}

void	Span::addNumber(int numb)
{
	if (this->v.size() == this->n)
		throw std::exception();
	this->v.push_back(numb);
}

void	Span::addVector(std::vector<int> &_v)
{
	if (v.size() + this->v.size() > this->n)
		throw std::exception();
	this->v.insert(this->v.end(), _v.begin(), _v.end());
}

long	Span::shortestSpan(void)
{
	long	minDiff = LONG_MAX;
	long	diff;

	std::vector<int> cpy = this->v;
	std::sort(cpy.begin(), cpy.end());

	std::vector<int>::iterator last = cpy.begin();
	for (std::vector<int>::iterator it = cpy.begin() + 1; it != cpy.end(); it++)
	{
		diff = std::abs(static_cast<long>(*it) - static_cast<long>(*last));
		if (diff < minDiff)
			minDiff = diff;
		last = it;
	}

	return minDiff;
}

long	Span::longestSpan(void)
{
	return (static_cast<long>(*std::max_element(this->v.begin(), this->v.end())) -
			static_cast<long>(*std::min_element(this->v.begin(), this->v.end())));
}
