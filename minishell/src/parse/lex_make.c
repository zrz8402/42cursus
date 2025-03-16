/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_make.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <kmartin@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:50:45 by kmartin           #+#    #+#             */
/*   Updated: 2025/03/12 17:30:15 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_lex	*init_lex_node(enum e_ltype ltype, char *lex, int lex_len);

// FUNCTION append_lex
// Add t_lex struct (containing lexeme type and value) to end of list,
//   where the linear linked list is connected using the next_lex member.
//
// Note that the other pointer members (parent, first_kid, next_sib) are for
//  constructing an AST tree structure on top of the linear list structure.
//
// @param root = first node in t_lex list (each node is one lexeme)
// @param ltype = the type of the lexeme being added
// @param lex = the string representation of the lexeme being added
// @param lex_len = the number of characters from the start of lex to include
//
// Return 1 if there is an error with appending to the list
// Return 0 if the t_lex node was correctly appended to the list
//
// Note that lexeme->value is dynamically allocated (=> must be freed)
int	append_lex(t_lex **root, enum e_ltype ltype, char *lex, int lex_len)
{
	t_lex	*ptr;
	t_lex	*newn;
	
	ptr = NULL;

	newn = init_lex_node(ltype, lex, lex_len);
	if (!newn)
		return (1);

	if (!(*root))
	{
		*root = newn;
		return (0);
	}
	ptr = *root;
	while (ptr->next_lex)
		ptr = ptr->next_lex;
	ptr->next_lex = newn;
	return (0);
}

// FUNCTION init_lex_node
t_lex	*init_lex_node(enum e_ltype ltype, char *lex, int lex_len)
{
	t_lex	*newn;

	newn = (t_lex *)malloc(sizeof(t_lex));
	if (!newn)
	{
		printf("Error: Failed to allocated memory for lexeme node\n");
		return (NULL);
	}
	newn->type = ltype;
	if (lex_len == -1)
		lex_len = ft_strlen(lex);
	newn->value = ft_substr(lex, 0, lex_len);
	newn->fd_int = -1;
	newn->next_lex = NULL;

	return (newn);
}

// FUNCTION free_lex_list
// Free each node in a t_lex list
void	free_lex_list(t_lex *head)
{
	t_lex	*lead;

	while (head)
	{
		lead = head->next_lex;
		free(head->value);
		if (head->fd_int != -1)
			close(head->fd_int);
		free(head);
		head = lead;
	}
}

