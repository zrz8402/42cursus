/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:35:43 by ruzhang           #+#    #+#             */
/*   Updated: 2025/02/24 18:04:34 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	builtin_pwd(void)
{
	char	*cwd;
	char	buf[1024];

	cwd = getcwd(buf, sizeof(buf));
	if (!cwd)
	{
		perror("getcwd failed");
		return (1);
	}
	ft_putstr_fd(cwd, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}

int	main(void)
{
	// Case 1: pwd a
	char *args1[] = {"pwd", "a", NULL};
	builtin_pwd();

	// Case 2: pwd a b c d
	char *args2[] = {"pwd", "a", "b", "c", "d", NULL};
	builtin_pwd();

	return 0;
}
