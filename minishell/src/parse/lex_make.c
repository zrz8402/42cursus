/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_make.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <kmartin@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:50:45 by kmartin           #+#    #+#             */
/*   Updated: 2025/03/18 12:06:02 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_lex	*init_lex_node(enum e_ltype ltype, char *lex, int lex_len);

// FUNCTION append_lex
// Add t_lex struct (containing lexeme type and value) to end of list,
//   where the linear linked list is connected using the next_lex member.
//
// If there is a problem appending to the list, the list memory is freed and 
// set to NULL.
//
// @param root = first node in t_lex list (each node is one lexeme)
// @param ltype = the type of the lexeme being added
// @param lex = the string representation of the lexeme being added
// @param lex_len = the number of characters from the start of lex to include
//
// @return 1 if there is an error with appending to the list (list set to NULL)
// @return 0 if the t_lex node was correctly appended to the list
//
// Note that lexeme->value is dynamically allocated (=> must be freed)
int	append_lex(t_lex **root, enum e_ltype ltype, char *lex, int lex_len)
{
	t_lex	*ptr;
	t_lex	*newn;
	
	ptr = NULL;
	newn = init_lex_node(ltype, lex, lex_len);
	if (!newn)
	{
		free_null_lex_list(root);
		return (1);
	}
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
// Initializes a t_lex node to be added to the end of a linked list.
//
// If there is an error with allocating memory for the node or for the
// char * value member, any allocated memory is freed, and NULL is returned.
//
// @param ltype = the node type
// @param lex = the starting character of the string representing lex value
// @param lex_len = the number of characters to copy from lex to 'value'
//
// @return a t_lex node if successfully initialized
// @return NULL if there was an error initializing the t_lex node
t_lex	*init_lex_node(enum e_ltype ltype, char *lex, int lex_len)
{
	t_lex	*newn;

	newn = (t_lex *)malloc(sizeof(t_lex));
	if (!newn)
		return (NULL);
	newn->type = ltype;
	if (lex_len == -1)
		lex_len = ft_strlen(lex); 
	newn->value = ft_substr(lex, 0, lex_len);
	if (!newn->value)
	{
		free_null_lex_list(&newn);
		return (NULL);
	}
	newn->next_lex = NULL;
	return (newn);
}

// FUNCTION free_null_lex_list
// Free each node in a t_lex list (including the memory allocated to
// the 'value' member of each node), and set the root node to NULL.
void	free_null_lex_list(t_lex **root)
{
	t_lex	*lead;
	t_lex	*chase;

	lead = *root;
	chase = *root;
	while (lead)
	{
		lead = lead->next_lex;
		if (chase->value)
			free(chase->value);
		free(chase);
		chase = lead;
	}
	*root = NULL;
}

