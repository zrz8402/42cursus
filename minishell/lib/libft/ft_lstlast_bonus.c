/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:09:42 by kmartin           #+#    #+#             */
/*   Updated: 2024/04/29 13:48:27 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// FUNCTION ft_lstlast
/**
 * @brief Returns the last node of the list.
 *
 * @param lst The beginning of the list.
 * @return Last node of the list
 *
 * @note No external dependencies.
 */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	ptr = lst;
	while (ptr)
	{
		if (!ptr->next)
			break ;
		ptr = ptr->next;
	}
	return (ptr);
}
