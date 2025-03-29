/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:58:38 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/29 20:45:08 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sys/stat.h>

bool	fileExists(const std::string& filename) {
	struct stat buffer;
	return (stat(filename.c_str(), &buffer) == 0);
}

int	main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "Usage: ./program filename s1 s2" << std::endl;
		return 0;
	}

	std::string		in_fn = av[1];
	std::string		out_fn = in_fn + ".replace";

	if (!fileExists(in_fn)) {
		std::cerr << "Error: " << in_fn << " does not exist." << std::endl;
		return 1;
	}

	std::ifstream	infile(in_fn.c_str());
	if (!infile.is_open()){
		std::cerr << "Unable to open file: " << in_fn << std::endl;
		return 1;
	}
	
	std::ofstream	outfile(out_fn.c_str());
	if (!outfile.is_open()) {
		std::cerr << "Unable to open file: " << out_fn << std::endl;
		infile.close();
		return 1;
	}

	std::string	line;
	std::string	content;
	std::string	toReplace = av[2];
	std::string	replacement = av[3];
	if (toReplace.empty())
	{
		while (std::getline(infile, line)) {
			outfile << line << std::endl;
		}
	} else {
		while (std::getline(infile, line)) {
			content = line + "\n";
			std::size_t	pos = 0;
			while ((pos = content.find(toReplace, pos)) != std::string::npos) {
				content.erase(pos, toReplace.length());
				content.insert(pos, replacement);
				pos += replacement.length();
			}
			outfile << content;
		}
	}

	infile.close();
	outfile.close();

	return 0;
}

/*
find()
	returns the position of the first occurrence of toReplace,
	starting the search from the index specified by pos.

	If the substring is not found, find returns std::string::npos,
	which indicates the end of the search.

std::string::npos
	type std::string::size_type
	an unsigned integral type
	represent the maximum size of a string
*/