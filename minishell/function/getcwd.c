/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:23:19 by ruzhang           #+#    #+#             */
/*   Updated: 2024/11/17 14:39:14 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	// dynatically allocate memory for cwd
	// needs to free it
	char	*cwd1;

	cwd1 = getcwd(NULL, 0);
	if (cwd1)
	{
		printf("%s\n", cwd1);
		free(cwd1);	
	}
	else
		perror("getcwd failed");
	
	// using a fixed-size buffer
	char	cwd[1024];

	printf("%lu\n", sizeof(cwd));
	if (getcwd(cwd, sizeof(cwd)))
		printf("%s\n", cwd);
	else
		perror("getcwd failed");
}
