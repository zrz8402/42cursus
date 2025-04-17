/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:56:29 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/17 13:19:13 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Base * generate(void) {
	int	result = std::rand() % 3 + 1;

	if (result == 1) {
		std::cout << "Generate an A" << std::endl;
		return new A();
	} else if (result == 2) {
		std::cout << "Generate an B" << std::endl;
		return new B();
	} else {
		std::cout << "Generate an C" << std::endl;
		return new C();
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "Base* type confirmed as : A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "Base* type confirmed as : B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "Base* type confirmed as : C" << std::endl;
	} else {
		std::cout << "Can't identify Base* type" << std::endl;
	}
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Base& type confirmed as : A" << std::endl;
		return ;
	} catch (std::exception &e) {
		(void)e;
	}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Base& type confirmed as : B" << std::endl;
		return ;
	} catch (std::exception &e) {
		(void)e;
	}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Base& type confirmed as : C" << std::endl;
		return ;
	} catch (std::exception &e) {
		(void)e;
	}

	std::cout << "Can't identify Base& type" << std::endl;
}

int	main() {
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	for (int i = 0; i < 5; i++) {
		Base *b = generate();
		identify(b);
		identify(*b);
		delete b;
		std::cout << std::endl;
	}

	return 0;
}