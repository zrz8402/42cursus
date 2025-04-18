/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:49:17 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/18 19:19:22 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"

int main(void)
{

	Warlock richard("Richard", "the Titled");
	//Richard: This looks like another boring day.$

	Dummy bob;
	Fwoosh* fwoosh = new Fwoosh();

	richard.learnSpell(fwoosh);

	richard.introduce();
	// Richard: I am Richard, the Titled!$
	richard.launchSpell("Fwoosh", bob);
	// Target Practice Dummy has been fwooshed!$

	richard.forgetSpell("Fwoosh");
	richard.launchSpell("Fwoosh", bob);

	// Richard: My job here is done!$

	return (0);
}

// g++ -Wall -Wextra -Werror -std=c++98 ASpell.cpp ATarget.cpp Dummy.cpp Fwoosh.cpp Warlock.cpp main.cpp -o ex01