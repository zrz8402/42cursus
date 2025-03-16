/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:09:24 by kmartin           #+#    #+#             */
/*   Updated: 2024/04/29 13:48:22 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// FUNCTION ft_lstclear
/**
 * @brief Deletes a sequence of nodes.
 *
 * Deletes and frees the given node and every successor of that node, using the
 * function `del` and free(3).
 * Finally, the pointer to the list must be set to NULL.
 *
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete the content of the node.
 * @return None.
 *
 * @note Depends on free.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;

	while (*lst != NULL)
	{
		ptr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = ptr;
	}
}
