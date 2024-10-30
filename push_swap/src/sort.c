/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:26:55 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/30 11:51:07 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_data *data)
{
	int	first;
	int	second;
	int	third;

	first = data->a.stack[0];
	second = data->a.stack[1];
	third = data->a.stack[2];
	if (is_sorted(data->a.stack, data->a.count)) // 123
		return ;
	else if (first > second && second < third && first < third) //213
		sa(data);
	else if (first > second && second < third && first > third) //312
		ra(data);
	else if (first < second && second > third && first > third) //231
		rra(data);
	else if (first < second && second > third && first < third) //132
	{
		sa(data);
		ra(data);
	}
	else //321 first > second && second > third
	{
		sa(data);
		rra(data);
	}
}

void	sort_five(t_data *data)
{
	int	count;

	count = 0;
	if (is_sorted(data->a.stack, data->a.size))
		return ;
	while (count < 2)
	{
		if (data->a.stack[0] == 1 || data->a.stack[0] == 2)
		{
			pb(data);
			count++;
		}
		else
			ra(data);
	}
	sort_three(data);
	if (data->b.stack[0] < data->b.stack[1])
		sb(data);
	pa(data);
	pa(data);
}

// void	turk_sort(t_data *data)
// {
// 	pb(data);
// 	pb(data);
	
// 	int	pos_a;
// 	int	pos_b;
// 	int	*move;
// 	move = malloc(data->a.count * sizeof(int));
// 	for (int i = 0; i < data->a.count; i++)
// 	{
// 		if (i <= data->a.count / 2)
// 			pos_a = i;
// 		else
// 			pos_a = data->a.count - i;
// 		move[i] = pos_a + pos_b;
// 		printf("(%d)", pos_a);
// 	}
// }

// int	get_pos_b(int n, t_cb cb)
// {
// 	int step;

// 	step = 0;
// 	if (n > cb.stack[cb.start]
// 		&& n < cb.stack[(cb.start + cb.count) % cb.size])
// 		step = 0;
// 	else if (n > ft_max(cb) || n < ft_min(cb))


	// printf("\n---------a------------\n");
	// for (int i = 0; i < data->a.size; i++)
	// 	printf("%d ", data->a.stack[i]);
	// printf("\n---------b------------\n");
	// for (int i = 0; i < data->b.size; i++)
	// 	printf("%d ", data->b.stack[i]);
	// printf("\n\n");
// }

// int	ft_max(t_cb cb)
// {
// 	int	max;

// 	max = cb.stack[cb.start];
// 	while (cb.count--)
// 	{
// 		if (max < cb.stack[(cb.start + 1) % cb.size])
// 			max = cb.stack[(cb.start + 1) % cb.size];
// 	}
// 	return (max);
// }

// int	ft_min(t_cb cb)
// {
// 	int	min;

// 	min = cb.stack[cb.start];
// 	while (cb.count--)
// 	{
// 		if (min > cb.stack[(cb.start + 1) % cb.size])
// 			min = cb.stack[(cb.start + 1) % cb.size];
// 	}
// 	return (min);
// }