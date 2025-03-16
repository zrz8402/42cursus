/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:13:14 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/16 15:14:16 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	free_arr(char **arr)
{
	char	**tmp;

	tmp = arr;
	if (arr)
	{
		while (*arr)
		{
			free(*arr);
			arr++;
		}
		free(tmp);
	}
}

void	free_envlst(t_env *envlst)
{
	t_env	*tmp;

	while (envlst)
	{
		tmp = envlst;
		envlst = envlst->next;
		if (tmp->key)
			free(tmp->key);
		if (tmp->value)
			free(tmp->value);
		free(tmp);
	}
}

void	free_program(t_program *minishell)
{
	free_arr(minishell->envp);
	free_envlst(minishell->envlst);
}

// void	print_arr(char **arr)
// {
// 	if (arr == NULL)
// 		return;
// 	while (*arr) 
// 	{
// 		printf("%s\n", *arr);
// 		arr++;
// 	}
// }
