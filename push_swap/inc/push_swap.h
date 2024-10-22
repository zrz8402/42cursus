/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:21:22 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/21 18:15:15 by ruzhang          ###   ########.fr       */
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

typedef struct s_data
{
	t_cb	a;
	t_cb	b;
	t_list	*ops;
}	t_data;

typedef enum e_ops
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}	t_ops;

// parse.c
char	*join_str(char *s1, char *s2);
char	**get_strs(char **av);
int		is_valid(char *s);
int		check_duplicates(int *arr, int size);
int		*transform(int *arr, int n);

// utils.c
void	ft_error(void);
int		ft_isempty(char *s);
int		array_size(char **s);
void	free_arr(char **arr);
void	free_data(t_data *data);

// stack.c
t_cb	get_stack_a(char **av);
void	init_data(t_cb a, t_data *data);
#endif