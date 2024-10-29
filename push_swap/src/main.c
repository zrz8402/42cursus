/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:53:32 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/29 19:06:40 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_cb	a;
	t_data	data;

	if (ac < 2)
		return (1);
	a = get_stack_a(++av);
	init_data(a, &data);
	//sort_three(&data);
	// sort_five(&data);
	sortn(&data);
	// printf("\n---------a------------\n");
	// for (int i = 0; i < data.a.size; i++)
	// {
	// 	printf("%d ", data.a.stack[i]);
	// 	//int n = (data.a.start + i) % data.a.size;
	// 	//printf("%d ", data.a.stack[n]);
	// }
	// get_ops(data.ops);
}
// ARG="38 71 43 36 1 33 5 76 28 15 21 61 80 58 9 22 87 57 42 69 46 50 25 7 97 54 92 78 81 18 26 8 77 49 2 34 20 52 91 63 30 99 88 53 3 68 56 83 60 100 31 62 90 19 72 39 47 86 16 24 17 70 45 41 37 93 12 13 4 66 23 10 59 55 64 85 84 44 96 14 48 94 89 51 32 82 29 11 65 6 27 79 35 67 95 73 74 98 75 40 "; ./push_swap $ARG | ./checker_linux $ARG

// ARG="519024 124 24 5 2 4"; ./push_swap $ARG | ./checker_linux $ARG
// ARG="38 71 43 36 1 33 5 76 "; ./push_swap $ARG | ./checker_linux $ARG
