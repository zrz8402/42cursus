/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:11:07 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/12 13:32:58 by ruzhang          ###   ########.fr       */
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

int	ipt(float n)
{
	return ((int)n);
}

float	fpt(float n)
{
	return (n - ipt(n));
}

float	rfpt(float n)
{
	return (1 - fpt(n));
}
