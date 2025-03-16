/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:34:33 by kmartin           #+#    #+#             */
/*   Updated: 2024/04/29 13:48:25 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// FUNCTION ft_lstiter
/**
 * @brief Applies a function to each node.
 *
 * Description Iterates the list ’lst’ and applies the function `f` on the
 * content of each node.
 *
 * @param f The address of the function used to iterate on the list.
 * @param lst The address of a pointer to a node.
 * @return None.
 *
 * @note No external dependencies.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ptr;

	ptr = lst;
	while (ptr)
	{
		f(ptr->content);
		ptr = ptr->next;
	}
}
