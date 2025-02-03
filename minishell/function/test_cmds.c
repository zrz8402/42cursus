/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:58:24 by ruzhang           #+#    #+#             */
/*   Updated: 2025/02/03 17:14:04 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

// see simple cases, test execve
// have: function(dir), cases(file), notes(file)....
int	main(void)
{

	// test ls
	// char	*cmd1[5] = {"/bin/ls", "-a", "-l", NULL};
	// execve(cmd1[0], cmd1, __environ);
	// char	*cmd2[5] = {"/bin/ls", "-a", "..", NULL};
	// execve(cmd2[0], cmd2, __environ);
	// char	*cmd3[5] = {"/bin/ls", "-al", "function", NULL};
	// execve(cmd3[0], cmd3, __environ);

	// test cat
	// char	*cmds[5] = {"/bin/cat", "notes", "cases", NULL};
	// execve(cmds[0], cmds, __environ);
	// char	*cmds[5] = {"/bin/cat", "-n", "cases", NULL};
	// execve(cmds[0], cmds, __environ);
	// invalid option case
	// char	*cmds[5] = {"/bin/cat", "-a", "cases", NULL};
	// execve(cmds[0], cmds, __environ);
	
	// built-in commands: may work differently
	// following won't work for unset
	// char	*cmds[4] = {"/bin/unset", "PATH", NULL};
	// execve(cmds[0], cmds, __environ);

	// however, pwd and env works
	// char	*cmds[5] = {"/bin/pwd", NULL};
	// execve(cmds[0], cmds, __environ);

	// char	*cmds[5] = {"/bin/env", NULL};
	// execve(cmds[0], cmds, __environ);
}
