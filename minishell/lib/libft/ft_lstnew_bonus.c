/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 02:03:01 by kmartin           #+#    #+#             */
/*   Updated: 2024/04/29 13:48:36 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // for bonus functions and node struct
#include <stdlib.h> // for malloc

// FUNCTION ft_lstnew
/**
 * @brief Creates a new node in a linked list.
 *
 * Allocates (with malloc(3)) and returns a new node.
 *
 * The member variable `content` is initialized with the value of the parameter 
 * `content`. The variable `next` is initialized to NULL
 *
 * @param content The content to create the node with.
 * @return The new node.
 *
 * @note Depends on malloc.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
