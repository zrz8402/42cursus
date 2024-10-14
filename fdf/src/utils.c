/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:48:32 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/14 16:56:07 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(char *message)
{
	ft_putstr_fd(message, 1);
	exit(1);
}

int	ft_atoi_hex(char *s)
{
	int	result;
	int	n;

	result = 0;
	if (!ft_strncmp(s, "0x", 2) || !ft_strncmp(s, "0X", 2))
		s += 2;
	else
		return (result);
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			n = *s - '0';
		else if (*s >= 'a' && *s <= 'f')
			n = *s + 10 - 'a';
		else if (*s >= 'A' && *s <= 'F')
			n = *s + 10 - 'A';
		else
			break ;
		result = result * 16 + n;
		s++;
	}
	return (result);
}

void	free_map(t_map	*map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	if (map->num_arr)
	{
		while (i < map->height)
		{
			free(map->num_arr[i]);
			i++;
		}
		free(map->num_arr);
	}
	i = 0;
	if (map->color_arr)
	{
		while (i < map->height)
		{
			free(map->color_arr[i]);
			i++;
		}
		free(map->color_arr);
	}
	free(map);
}

void	free_arr(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}
