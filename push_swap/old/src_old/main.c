/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:53:32 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/26 18:49:22 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	a;

	if (ac < 2)
		return (1);
	get_stack_a(++av, &a);
	// printf("\n---------a------------\n");
	// for (int i = 0; i < data.a.size; i++)
	// {
	// 	int n = (data.a.head + i) % data.a.size;
	// 	printf("%d ", data.a.stack[n]);
	// }
	// printf("\n----------b-----------\n");
	// for (int i = 0; i < data.b.size; i++)
	// {
	// 	int n = (data.b.head + i) % data.b.size;
	// 	printf("%d ", data.b.stack[n]);
	// }
	// sort(data);
	// get_ops(data.ops);
}
