/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:58:38 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/03 15:20:16 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "Usage: ./program filename s1 s2" << std::endl;
		return 0;
	}

	std::string		in_fn = av[1];
	std::string		out_fn = in_fn + ".replace";

	std::ifstream	infile(in_fn.c_str());
	if (!infile.is_open()){
		std::cerr << "Unable to open file " << in_fn << std::endl;
		return 1;
	}
	
	std::ofstream	outfile(out_fn.c_str());
	if (!outfile.is_open()) {
		std::cerr << "Unable to open file " << out_fn << std::endl;
		return 1;
	}

	std::string	line;
	std::string	toReplace = av[2];
	std::string	replacement = av[3];
	while (std::getline(infile, line)) {
		std::size_t	pos = 0;
		while ((pos = line.find(toReplace, pos)) != std::string::npos) {
			line.erase(pos, toReplace.length());
			line.insert(pos, replacement);
			pos += replacement.length();
		}
		outfile << line << std::endl;
	}

	infile.close();
	outfile.close();

	return 0;
}