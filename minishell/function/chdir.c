/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:41:58 by ruzhang           #+#    #+#             */
/*   Updated: 2024/11/17 14:48:44 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd)
	{
		printf("Current working directory: %s\n", cwd);
		free(cwd);
	}
	else
		perror("getcwd failed");

	if (chdir("/home/ruzhang") == 0)
	{
		printf("Directory changed successfully.\n");
		cwd = getcwd(NULL, 0);
		if (cwd)
		{
			printf("New working directory: %s\n", cwd);
			free(cwd);
		}
		else
			perror("getcwd failed");
	}
	else
		perror("chdir failed");
	return (0);
}