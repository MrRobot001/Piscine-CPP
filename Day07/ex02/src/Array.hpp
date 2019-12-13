/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:15:33 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/13 18:37:26 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template <typename T>
class Array
{
	private:
		T *array;
		unsigned int n;
	public:
		Array(void) : array(NULL), n(0) {}
		Array(unsigned int _n) : array(new T[_n]()), n(_n) {}
		Array(Array const &obj) : array(NULL), n(0)
		{
			*this = obj;
		}
		~Array(void)
		{
			if (this->array)
				delete [] this->array;
		}

		Array const &operator=(Array const &arr)
		{
			if (&arr == this)
				return *this;
			if (this->size() != arr.size())
			{
				if (this->array)
					delete [] this->array;
				this->array = new T[arr.size()];
			}

			this->n = arr.size();
			for (size_t i = 0; i < arr.size(); i++)
				this->array[i] = arr.array[i];

			return *this;
		}

		T &operator[](size_t i)const
		{
			if (!this->array || i < 0 || i >= this->n)
				throw std::exception();

			return this->array[i];
		}

		unsigned int size(void) const
		{
			return this->n;
		}
};
