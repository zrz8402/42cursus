/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:53:32 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/31 20:31:38 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		return (1);
	init_data(av, &data);
	if (data.a.size == 2)
		sort_three(&data);
	else if (data.a.size == 3)
		sort_three(&data);
	else if (data.a.size == 5)
		sort_five(&data);
	else
		sortn(&data);
	free_data(&data);
}
