/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:37:46 by ruzhang           #+#    #+#             */
/*   Updated: 2024/11/06 14:44:41 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ferror(t_data *data, char *arr)
{
	if (arr)
		free(arr);
	if (data)
		free_data(data);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	process_op(char *op, t_data *data)
{
	if (!ft_strncmp(op, "sa\n", 3))
		sa(data);
	else if (!ft_strncmp(op, "sb\n", 3))
		sb(data);
	else if (!ft_strncmp(op, "ss\n", 3))
		ss(data);
	else if (!ft_strncmp(op, "ra\n", 3))
		ra(data);
	else if (!ft_strncmp(op, "rb\n", 3))
		rb(data);
	else if (!ft_strncmp(op, "rr\n", 3))
		rr(data);
	else if (!ft_strncmp(op, "rra\n", 4))
		rra(data);
	else if (!ft_strncmp(op, "rrb\n", 4))
		rrb(data);
	else if (!ft_strncmp(op, "rrr\n", 4))
		rrr(data);
	else if (!ft_strncmp(op, "pa\n", 3))
		pa(data);
	else if (!ft_strncmp(op, "pb\n", 3))
		pb(data);
	else
		ferror(data, op);
}

int	main(int ac, char **av)
{
	t_data	data;
	char	*op;

	if (ac < 2)
		return (1);
	init_data(av, &data);
	data.write = 0;
	op = get_next_line(0);
	while (op)
	{
		process_op(op, &data);
		free(op);
		op = get_next_line(0);
	}
	if (is_sorted(data.a.stack, data.a.size))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_data(&data);
	free(op);
}
