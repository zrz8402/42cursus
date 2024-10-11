/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:11:07 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/11 17:20:26 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	i_part(float n)
{
	return ((int)n);
}

float	f_part(float n)
{
	return (n - i_part(n));
}

float	rf_part(float n)
{
	return (1 - f_part(n));
}
