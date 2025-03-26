/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <kmartin@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:52:34 by kmartin           #+#    #+#             */
/*   Updated: 2025/03/26 09:56:06 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	handle_pipe(char **input, int i, t_lex **input_lex);
int	handle_redir(char **input, int i, t_lex **input_lex, t_program *mshell);
int	handle_other(char **input, int i, t_lex **input_lex, t_program *mshell);
int	remove_quotes(char **input, int *i, int tok_len, t_program *mshell);

// FUNCTION tokenize
//
// Break an input string of tokens into a lex list, with member value in
// each node holding the value of the token, with variables expanded.
//
// The input string is passed from readline, and an index is used to process
// characters while searching for the start of tokens sequentially.
// 
// When each token is processed, the index is updated to jump to the start of
// the next character after the processed token, taking into account variable
// expansion.
//
// Note that the input string is replaced with a shorter/longer string
// each time a variable is expanded; an error in a replacement (malloc) step
// will result in the input string being set equal to NULL.
//
// If the input string is set to NULL (indicating a problem with parsing,
// then the lex list is also freed and set to NULL, and exit status = 1.
//
// If a string with only whitespaces is provided, the input will not be freed, 
// and input_lex will be contain an ARGUMENT node with whitespaces as value.
//
// @param input = input from readline (may be replaced for variable expansion)
// @param minishell = a struct containing minishell exit status and env vars
//
// @return input_lex = a linked list of t_lex, with one node per token.
// @return NULL if a parsing problem (status 1) or invalid input
t_lex	*tokenize(char **input, t_program *minishell)
{
	t_lex	*input_lex;
	int		i;

	input_lex = NULL;
	minishell->prev_status = minishell->status;
	minishell->status = 0;
	i = 0;
	while (input && (*input)[i])
	{
		while ((*input)[i] && (*input)[i] == ' ')
			i++;
		if ((*input)[i] == '|')
			i = handle_pipe(input, i, &input_lex);
		else if ((*input)[i] == '<' || (*input)[i] == '>')
			i = handle_redir(input, i, &input_lex, minishell);
		else if ((*input)[i])
			i = handle_other(input, i, &input_lex, minishell);
		if (!(*input))
			return (parse_exit(1, minishell, input, &input_lex));
	}
	if (input_lex)
		type_check(input, &input_lex, minishell);
	return (input_lex);
}

// FUNCTION handle_other
// Handle tokens that start with a character other than `>`, `<`, or `|`; create
// a t_lex node with type ARGUMENT (starting default - identify COMMANDS later).
//
// If quotes are found, they are removed, and sequential quoted strings without
// intervening spaces are concatenated.
//
// If variables are found within a space-delimited token, they are processed:
// the input string is replaced with a new string, with variables expanded
// (this doesn't happen in `'`-quoted string segments).
//
// If there is a problem expanding and replacing input, input is set to NULL.
//
// If there is a problem with appending to the lex list, input_lex is set to
// NULL, and input is set to NULL (all memory is freed).
//
// @param input = input string (replace as variables are expanded)
// @param i = index to the start character of the current token being processed
// @param input_lex = the lex list for tokens to be added to as nodes
// @param minishell = a struct containing minishell exit status and env vars
//
// @return i = the index to the first character after the processed token.
int	handle_other(char **input, int i, t_lex **input_lex, t_program *mshell)
{
	int	tok_ind;
	int	tok_len;
	int	quotes;

	quotes = token_has_quotes(*input, i);
	tok_ind = i;
	tok_len = 0;
	while (*input && (*input)[i] && !(space_pipe_redir((*input)[i])))
	{
		if ((*input)[i] == '$')
			tok_len = expand_inp(input, &i, tok_len, mshell);
		else if ((*input)[i] == '"' || (*input)[i] == 39)
			tok_len = remove_quotes(input, &i, tok_len, mshell);
		else
		{
			tok_len++;
			i++;
		}
	}
	if (*input && (tok_len != 0 || quotes))
		add_lex(input_lex, ARGUMENT, *input + tok_ind, tok_len);
	if (!(*input_lex) && tok_len)
		free_null_input(input);
	return (i);
}

// FUNCTION remove_quotes 
// Strip quotes from quoted strings (either with " or ').
//
// Shift the characters in the string to the left, once at the start quote, and
// again at the end quote (if it is found in the string). 
//
// If variables are found within a space-delimited token, they are processed:
// the input string is replaced with a new string, with variables expanded
// (this doesn't happen in `'`-quoted string segments).
//
// If unclosed quotes are found, or if there is an error with expanding 
// variables, the input string is freed and set to NULL.
//
// If the token being processed contains quotes and is 0-length after being
// processed, a token with an empty-string value is created.
//
// @param input = input string (replace as variables are expanded)
// @param i = index to the start character of the current token being processed
// @param tok_len = the number of characters in the current token so far 
// @param minishell = a struct containing minishell exit status and env vars
//
// @return i = the index to the first character after the processed token.
int	remove_quotes(char **input, int *i, int tok_len, t_program *mshell)
{
	char	start_quote;

	start_quote = (*input)[*i];
	ft_strlcpy(*input + *i, *input + *i + 1, ft_strlen(*input) - *i);
	while (*input && (*input)[*i] && (*input)[*i] != start_quote)
	{
		if (start_quote == '"' && (*input)[*i] == '$')
			tok_len = expand_inp(input, i, tok_len, mshell);
		else
		{
			tok_len++;
			(*i)++;
		}
	}
	if (*input && (*input)[*i] == '\0')
	{
		free(*input);
		*input = NULL;
	}
	if (*input && (*input)[*i] == start_quote)
		ft_strlcpy(*input + *i, *input + *i + 1, ft_strlen(*input) - *i);
	return (tok_len);
}

// FUNCTION handle_pipe
// Handle pipe tokens (|) - create a PIPE type t_lex node.
//
// @param input = pointer to the input string
// @param i = index to the start character of the current token being processed
// @param input_lex = the lex list for tokens to be added to as nodes
//
// @return i = the index to the first character after the processed token.
int	handle_pipe(char **input, int i, t_lex **input_lex)
{
	int	tok_ind;
	int	tok_len;

	tok_ind = i;
	tok_len = 1;
	add_lex(input_lex, PIPE, *input + tok_ind, tok_len);
	if (!(*input_lex))
		free_null_input(input);
	return (tok_ind + tok_len);
}

// FUNCTION handle_redir
// Handle tokens that start with a redirection character (< or >): create t_lex
// node with the redirection type (e.g. RED_IN, APPEND, etc).
//
// @param input = pointer to the input string
// @param i = index to the start of the current token being processed
// @param input_lex = the lex list for tokens to be added to as nodes
// @param minishell = a struct containing minishell exit status and env vars
//
// @return i = the index to the first character after the processed token.
int	handle_redir(char **input, int i, t_lex **input_lex, t_program *mshell)
{
	int				tok_ind;
	int				tok_len;
	enum e_ltype	rtype;

	tok_ind = i;
	tok_len = 0;
	if (valid_redir_len(*input + i, &rtype))
		tok_len = valid_redir_len(*input + i, &rtype);
	else
		print_syntax_error(*input + i, "redir");
	if (tok_len == 0)
		parse_exit(2, mshell, input, input_lex);
	if (*input)
		add_lex(input_lex, rtype, *input + tok_ind, tok_len);
	if (!(*input_lex))
		free_null_input(input);
	return (tok_ind + tok_len);
}
