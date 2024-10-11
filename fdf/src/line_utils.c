/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:11:07 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/11 13:07:39 by ruzhang          ###   ########.fr       */
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

int	iPartN(float n)
{
	return ((int)n);
}

float	fPartN(float n)
{
	return (n - iPartN(n));
}

float	rfPartN(float n)
{
	return (1 - fPartN(n));
}
