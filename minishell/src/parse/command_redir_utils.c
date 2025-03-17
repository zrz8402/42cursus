/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_redir_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:50:45 by kmartin           #+#    #+#             */
/*   Updated: 2025/03/17 17:25:07 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "minishell.h"

t_redir	*init_redir_node(enum e_ltype type, t_lex *tok_ptr);
 
// FUNCTION add_command_redirs
// Add a linked list of t_redir nodes as the redirection member of a t_command
// node, if the t_command node exists.
//
// Redirections are represented as a linked list with the following members:
// - e_ltype type = the type of redirection (RED_IN, APPEND, etc)
// - char *file = the target/source file name (NULL for HEREDOC)
// - int heredoc_fd = the fd for a HEREDOC (-1 for non-HEREDOC)
// - t_redir *next = pointer to next redirection
//
// @param cmd_node = pointer to t_command node
// @param tok_ptr = pointer to t_lex node at start of series of command tokens 
void	add_command_redirs(t_command *cmd_node, t_lex *tok_ptr)
{
	enum e_ltype	type;
	t_redir			*new_redir;
	t_redir			*redir_ptr;

	if (tok_ptr && tok_ptr->type == PIPE)
			tok_ptr = tok_ptr->next_lex;
	while (cmd_node && tok_ptr && tok_ptr->type != PIPE)
	{
		type = tok_ptr->type;
		if (type == RED_IN || type == RED_OUT || type == APPEND || type == HEREDOC)
		{
			new_redir = init_redir_node(type, tok_ptr);
			if (!(cmd_node->redirections))
			{
				cmd_node->redirections = new_redir;
				redir_ptr = new_redir;
			}
			else
			{
				redir_ptr->next = new_redir;
				redir_ptr = redir_ptr->next;
			}
		}
		tok_ptr = tok_ptr->next_lex;
	}
}

// FUNCTION init_redir_node
// Initialize a new t_redir node
t_redir	*init_redir_node(enum e_ltype type, t_lex *tok_ptr)
{
	t_redir	*new_redir;

	new_redir = (t_redir *)malloc(sizeof(t_redir));
	if (!new_redir)
		printf("ERROR in add_command_redirs: EXIT GRACEFULLY!!\n");

	new_redir->type = type;
	new_redir->heredoc_fd = -1;
	new_redir->file = NULL;
	if (type == HEREDOC)
	{
		new_redir->heredoc_fd = handle_heredoc(tok_ptr->next_lex->value);
	}
	else
		new_redir->file = ft_strdup(tok_ptr->next_lex->value);
	new_redir->next = NULL;

	return (new_redir);
}

// FUNCTION free_command_redirs
// Free memory allocated to all nodes of a t_redir linked list, including memory
// allocated to char* 'file' member.
//
// @param pointer to pointer to the root node of the t_redir linked list.
//
// @return NULL
t_redir	*free_command_redirs(t_redir **redir_list)
{
	t_redir	*redir_ptr;

	redir_ptr = (*redir_list);
	while (redir_ptr)
	{
		redir_ptr = redir_ptr->next;
		if ((*redir_list)->heredoc_fd != -1)
			close((*redir_list)->heredoc_fd);
		if ((*redir_list)->file)
			free((*redir_list)->file);
		(*redir_list)->file = NULL;
		free(*redir_list);
		(*redir_list) = redir_ptr;
	}
	return (NULL);
}

