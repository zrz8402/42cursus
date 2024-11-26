/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:16:02 by ruzhang           #+#    #+#             */
/*   Updated: 2024/11/20 18:21:47 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char *env = getenv("PATH");
	if (env && *env)
		printf("%s\n", env);
	else
		printf("no path");
}
