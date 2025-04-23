/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:15:23 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/23 10:40:42 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

void    testList()
{
    std::list<int> rlist;

	rlist.push_back(5);
	rlist.push_back(17);
	std::cout << rlist.back() << std::endl;
	rlist.pop_back();
	std::cout << rlist.size() << std::endl;
	rlist.push_back(3);
	rlist.push_back(5);
	rlist.push_back(737);
	//[...]
	rlist.push_back(0);
	std::list<int>::iterator it = rlist.begin();
	std::list<int>::iterator ite = rlist.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(rlist);
}

int	main(int, char**) {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::const_iterator it = mstack.begin();
	MutantStack<int>::const_iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

    std::cout << "--------LIST---------" << std::endl;
    testList();
	return 0;
}
