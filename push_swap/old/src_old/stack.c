/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:32:23 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/26 19:05:24 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_stack_a(char **av, t_list *a)
{
	int	*nums;
	int size;
	int	*num;
	int	i;

	nums = get_nums(av, &size);
	i = size;
	while (i--)
	{	num = malloc(sizeof(int));
		num = &nums[i];
		ft_lstadd_front(&a, ft_lstnew(num));
	}
	for (int i = 0; i < size; i++)
	{
		printf("%d ", *(int *)a->content);
		a = a->next;
	}
	// if (size == 2)
	// {
	// 	if (nums[0] > nums[1])
	// 		sort_two();
	// }
	// else if (size == 3)
	// 	sort_three();
	// else if (size == 5)
	// 	sort_five();
	// else
	// {
		
	// }
	
}

int	is_sorted(int *arr, int n)
{
	int	i;

	if (n == 0 || n == 1)
		return (1);
	i = 1;
	while (i < n)
	{
		if (arr[i - 1] > arr[i])
			return (0);
		i++;
	}
	return (1);
}
