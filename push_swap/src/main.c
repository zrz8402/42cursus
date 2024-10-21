/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:53:32 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/21 17:30:29 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	t_cb stack_a;
	stack_a = get_stack(++av);
	for (int i = 0; i < stack_a.size; i++)
		printf("%d ", stack_a.stack[i]);
	free(stack_a.stack);
}
