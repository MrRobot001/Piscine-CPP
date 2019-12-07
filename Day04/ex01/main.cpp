/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:31:44 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/07 20:19:33 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Character.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"

int	main(void)
{
	Character *charact = new Character("charact");
	std::cout << *charact;
	Enemy *b = new RadScorpion();
	Enemy *c = new RadScorpion();
	Enemy *d = new RadScorpion();
	AWeapon *pr = new PlasmaRifle();
	AWeapon *pf = new PowerFist();

	charact->equip(pr);
	std::cout << *charact;
	charact->equip(pf);
	charact->attack(b);
	std::cout << *charact;
	charact->equip(pr);
	std::cout << *charact;
	charact->attack(b);
	std::cout << *charact;
	charact->attack(b);
	std::cout << *charact;

	charact->attack(c);
	std::cout << *charact;
	charact->attack(c);
	std::cout << *charact;
	charact->attack(c);
	std::cout << *charact;
	charact->attack(c);
	std::cout << *charact;
	charact->attack(d);
	std::cout << *charact;
	charact->attack(d);
	std::cout << *charact;
	charact->attack(d);
	std::cout << *charact;

	return (0);
}
