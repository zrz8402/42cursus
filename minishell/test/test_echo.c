/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:35:25 by ruzhang           #+#    #+#             */
/*   Updated: 2025/02/24 17:36:16 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	with_option(char *s)
{
	int	i;

	if (s[0] != '-')
		return (0);
	i = 1;
	while (s[i])
	{
		if (s[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	builtin_echo(char **args)
{
	int	i;
	int	option;

	i = 1;
	option = 0;
	while (args[i] && with_option(args[i]))
	{
		option = 1;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (option == 0)
		ft_putstr_fd("\n", 1);
	return (0);
}

// with -n
// int	main(void)
// {
	// // Case 1: echo -n -n -nnnn -nnnnm
	// char *args1[] = {"echo", "-n", "-n", "-nnnn", "-nnnnm", NULL};
	// builtin_echo(args1);

	// // Case 2: echo -n simple
	// char *args2[] = {"echo", "-n", "simple", NULL};
	// builtin_echo(args2);

	// // Case 3: echo -n bonjour
	// char *args3[] = {"echo", "-n", "bonjour", NULL};
	// builtin_echo(args3);

	// // Case 4: echo -nn bonjour
	// char *args4[] = {"echo", "-nn", "bonjour", NULL};
	// builtin_echo(args4);

	// // Case 5: echo -n -n -n bonjour
	// char *args5[] = {"echo", "-n", "-n", "-n", "bonjour", NULL};
	// builtin_echo(args5);

	// // Case 6: echo "-n" bonjour
	// char *args6[] = {"echo", "-n", "bonjour", NULL};
	// builtin_echo(args6);

	// // Case 7: echo "-nnnn" bonjour
	// char *args7[] = {"echo", "-nnnn", "bonjour", NULL};
	// builtin_echo(args7);

	// // Case 8: echo "-nnnn" -n bonjour
	// char *args8[] = {"echo", "-nnnn", "-n", "bonjour", NULL};
	// builtin_echo(args8);

// 	return 0;
// }

// int	main(void)
// {
	// // Case 1: echo -n"-n" bonjour
	// char *args1[] = {"echo", "-n-n", "bonjour", NULL};
	// builtin_echo(args1);

	// // Case 2: echo "-n -n -n"-n bonjour
	// char *args2[] = {"echo", "-n -n -n-n", "bonjour", NULL};
	// builtin_echo(args2);

	// // Case 3: echo "-n '-n'" bonjour
	// char *args3[] = {"echo", "-n '-n'", "bonjour", NULL};
	// builtin_echo(args3);

// 	return 0;
// }

int	main(void)
{
	// // Case 1: echo test > file test1
	// char *args1[] = {"echo", "test", ">", "file", "test1", NULL};
	// builtin_echo(args1);

	// // Case 2: echo 2 >> out1 > out2
	// char *args2[] = {"echo", "2", ">>", "out1", ">", "out2", NULL};
	// builtin_echo(args2);

	// // Case 3: echo 2 > out1 >> out2
	// char *args3[] = {"echo", "2", ">", "out1", ">>", "out2", NULL};
	// builtin_echo(args3);

	// // Case 4: > log echo coucou
	// char *args4[] = {">", "log", "echo", "coucou", NULL};
	// builtin_echo(args4);

	// Case 8: echo
	char *args8[] = {"echo", NULL};
	builtin_echo(args8);

	// Case 9: echo simple
	char *args9[] = {"echo", "simple", NULL};
	builtin_echo(args9);

	// Case 10: echo ''
	char *args10[] = {"echo", "", NULL};
	builtin_echo(args10);

	// Case 11: echo ""
	char *args11[] = {"echo", "", NULL};
	builtin_echo(args11);

	// Case 12: echo "\n \n \n"
	char *args12[] = {"echo", "\\n \\n \\n", NULL};
	builtin_echo(args12);

	// Case 13: echo "\"
	char *args13[] = {"echo", "\\", NULL};  // Not seeing it as special
	builtin_echo(args13);

	// Case 14: echo "\n \n \\n"  // How bash handles it vs our minishell
	char *args14[] = {"echo", "\\n \\n \\\\n", NULL};
	builtin_echo(args14);

	// // Case 15: echo > a Hello World!
	// char *args15[] = {"echo", ">", "a", "Hello", "World!", NULL};
	// builtin_echo(args15);

	// // Case 16: > a echo Hello World!
	// char *args16[] = {">", "a", "echo", "Hello", "World!", NULL};
	// builtin_echo(args16);

	// Case 17: echo echo
	char *args17[] = {"echo", "echo", NULL};
	builtin_echo(args17);

	// Case 18: echo $
	char *args18[] = {"echo", "$", NULL};
	builtin_echo(args18);

	// Case 19: echo $ $
	char *args19[] = {"echo", "$", "$", NULL};
	builtin_echo(args19);

	// Case 20: echo rhobebou
	char *args20[] = {"echo", "rhobebou", NULL};
	builtin_echo(args20);

	// Case 21: echo stop barking
	char *args21[] = {"echo", "stop", "barking", NULL};
	builtin_echo(args21);

	// Case 22: echo "bonjour"
	char *args22[] = {"echo", "bonjour", NULL};
	builtin_echo(args22);

	// Case 23: echo bonjour
	char *args23[] = {"echo", "bonjour", NULL};
	builtin_echo(args23);

	// Case 24: echo 'bonjour'
	char *args24[] = {"echo", "bonjour", NULL};
	builtin_echo(args24);

	return (0);
}