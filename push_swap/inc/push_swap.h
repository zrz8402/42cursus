/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:21:22 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/24 12:23:24 by ruzhang          ###   ########.fr       */
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
}	t_cb;

typedef struct s_data
{
	t_cb	a;
	t_cb	b;
	t_list	*ops;
}	t_data;

typedef enum e_ops
{
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	PA,
	PB
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
int	is_sorted(int *arr, int n);

// op_utils.c
void	swap(int *x, int *y);
int		is_full(t_cb *cb);
void	add_op(t_list *list, int op);
int	is_empty(t_cb *cb);

void	sa(t_data *data);
void	sb(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);

void	sort_three(t_data *data);
void	sort_five(t_data *data);
#endif