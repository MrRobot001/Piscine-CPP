/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:50:28 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/12 21:12:04 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

#include "Base.hpp"

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate(void)
{
	int choice = std::rand() % 3;

	if (choice == 0) return new A();
	else if (choice == 1) return new B();
	else return new C();
}

void identify_from_pointer(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A";
	else if (dynamic_cast<B *>(p))
		std::cout << "B";
	else if (dynamic_cast<C *>(p))
		std::cout << "C";
}

void identify_from_reference(Base &b)
{
	Base tmp;
	try {
		tmp = dynamic_cast<A &>(b);
		std::cout << "A";
	} catch(std::bad_cast exp) {}
	try {
		tmp = dynamic_cast<B &>(b);
		std::cout << "B";
	} catch(std::bad_cast exp) {}
	try {
		tmp = dynamic_cast<C &>(b);
		std::cout << "C";
	} catch(std::bad_cast exp) {}
}

int main(void)
{
	std::srand(time(0));

	for (int i = 0; i < 10; i++)
	{
		Base *ptr = generate();

		std::cout << std::setw(2) << std::left << i + 1 << ": identify_from_pointer(";
		identify_from_pointer(ptr);
		std::cout << "), identify_from_reference(";
		identify_from_reference(*ptr);
		std::cout << ")" << std::endl;

		delete ptr;
	}

}
