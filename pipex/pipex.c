/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:32:52 by ruzhang           #+#    #+#             */
/*   Updated: 2024/11/02 17:09:05 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	int		pipefd[2];
	pid_t	pid;
	char	*argv_in;
	char	*argv_out;

	if (ac < 5)
		return (0);
	pipefd[0] = open(av[1], O_RDONLY);
	if (pipefd[0] < 0)
		perror("Error opening file");
	pipefd[1] = open(av[ac - 1], O_WRONLY|O_CREAT);
	argv_in = ft_split(av[2], " ");
	argv_out = ft_split(av[3], " ");
	
}