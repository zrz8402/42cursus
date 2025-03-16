/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:54:36 by kmartin           #+#    #+#             */
/*   Updated: 2024/04/29 13:48:23 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// FUNCTION ft_lstdelone
/**
 * @brief Deletes a node.
 *
 * Takes as a parameter a node and frees the memory of the node’s content using
 * the function `del` given as a parameter and free the node. The memory of
 * `next` must not be freed.
 *
 * @param lst The node to free.
 * @param del The address of the function used to delete the content.
 * @return None.
 *
 * @note Depends on free.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	del(lst->content);
	lst->content = NULL;
	lst->next = NULL;
	free(lst);
}
