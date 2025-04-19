/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 10:55:46 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/19 11:17:22 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <vector>
# include "ATarget.hpp"

class TargetGenerator {

private:
	std::vector<ATarget*> types;

public:
	TargetGenerator();
	virtual ~TargetGenerator();

	void	learnTargetType(ATarget *type);
	void	forgetTargetType(std::string const &name);
	ATarget	*createTarget(std::string const &name);
};

#endif