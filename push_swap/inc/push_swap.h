/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:21:22 by ruzhang           #+#    #+#             */
/*   Updated: 2024/11/06 14:56:45 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "libft.h"

typedef struct s_cb
{
	int	*stack;
	int	size;
	int	count;
}	t_cb;

typedef struct s_data
{
	t_cb	a;
	t_cb	b;
	int		write;
}	t_data;

typedef struct s_move
{
	int	pos_a;
	int	pos_b;
	int	min;
}	t_move;

// parse.c
char	*join_str(char *s1, char *s2);
char	**get_strs(char **av, t_data *data);
int		is_valid(char *s);
int		check_duplicates(int *arr, int size);

// stack.c
int		*transform(t_data *data, int *arr);
void	get_stack_a(char **av, t_data *data);
void	init_data(char **av, t_data *data);

// utils.c
void	ft_error(t_data *data);
void	f_error(t_data *data, char **arr);
void	free_arr(char **arr);
void	free_data(t_data *data);

// sort.c
int		is_sorted(int *arr, int n);
void	sort_two(t_data *data);
void	sort_three(t_data *data);
void	sort_five(t_data *data);

// sortn.c
void	ft_move_to_b(t_data *data);
void	ft_move_to_a(t_data *data);
void	sortn(t_data *data);

// lis.c
int		*get_lis(t_data *data, int *len);

// sortn_utils.c
int		get_pos_a(int n, t_cb cb);
int		calculate_move(int a, int b);
int		min_move_index(t_move *moves, int size);

// move.c
void	move(t_data *data, t_move *moves, int i);

//ops
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);

void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);

void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

void	pa(t_data *data);
void	pb(t_data *data);

#endif