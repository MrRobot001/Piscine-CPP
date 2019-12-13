/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:50:29 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/13 17:55:24 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define	LEN_ARR 3

template <typename T> inline void iter(T *arr, size_t len, void (*f)(T const &))
{
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

void	display(const int &val)
{
	std::cout << val << std::endl;
}

int		main(void)
{
	int arr[LEN_ARR] = {5, 6, 7};
	iter(arr, LEN_ARR, display);
}
