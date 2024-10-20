/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:21:22 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/20 18:45:53 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "libft.h"
// delte it later
# include <stdio.h>

typedef struct s_cb
{
	int	*stack;
	int	size;
	int	head;
	int	tail;
	int	count;
}	t_cb;

typedef enum e_error
{
	SUCCESS,
	NOT_INT,
	OUT_OF_BOUNDS,
}	t_error;

// parse.c
int		stoi(char *s, int *error);
char	*join_str(char *s1, char *s2);
char	**get_strs(char **av);
t_cb	get_stack(char	**av);
void	init_stack(t_cb *cb, int size);

void	ft_error(void);
int		ft_isspace(char c);
int	ft_isempty(char *s);
int	array_size(char **s);
void	free_arr(char **arr);
#endif