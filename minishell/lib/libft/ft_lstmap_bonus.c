/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:19:31 by kmartin           #+#    #+#             */
/*   Updated: 2024/04/29 13:48:32 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // for node struct and other linked list functions
#include <stdlib.h> // for malloc and free

// FUNCTION ft_lstmap
/**
 * @brief Makes a new list by applying a function to each node.
 *
 * Iterates the list `lst` and applies the function `f` on the content of each
 * node. Creates a new list resulting of the successive applications of the
 * function ’f’. 
 * The ’del’ function is used to delete the content of a node if needed.
 *
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delete the content of a node
 *  if needed.
 *
 * @return The new list.
 * @return NULL if the allocation fails.
 *
 * @note Depends on malloc and free.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*ptr_orig;
	t_list	*ptr_cmod;

	head = NULL;
	ptr_orig = lst;
	while (ptr_orig)
	{
		ptr_cmod = ft_lstnew(f(ptr_orig->content));
		if (!ptr_cmod)
		{
			ft_lstclear(&head, del);
			break ;
		}
		if (!head)
			head = ptr_cmod;
		else
			ft_lstadd_back(&head, ptr_cmod);
		ptr_orig = ptr_orig->next;
	}
	return (head);
}
