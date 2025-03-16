/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <kmartin@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:52:34 by kmartin           #+#    #+#             */
/*   Updated: 2025/03/14 13:22:24 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	handle_pipe(char *inp, int i, t_lex **input_lex);
int	handle_redir(char *inp, int i, t_lex **input_lex);
int	handle_other(char **input, int i, t_lex **input_lex);
int	remove_quotes(char **input, int *i, int tok_len);

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
// each time a variable is expanded.
//
// @return input_lex = a linked list, with one node per token.
t_lex	*tokenize(char **input)
{
	t_lex	*input_lex;
	int		i;

	input_lex = NULL;
	i = 0;
	while (input && (*input)[i])
	{
		while ((*input)[i] && (*input)[i] == ' ')
			i++;
		if ((*input)[i] == '|')
			i = handle_pipe(*input, i, &input_lex);
		else if ((*input)[i] == '<' || (*input)[i] == '>')
			i = handle_redir(*input, i, &input_lex);
		else if ((*input)[i])
			i = handle_other(input, i, &input_lex);
		if (!input || !(*input)) // useful conditions?
		{
			free_lex_list(input_lex);
			return (NULL);
		}
	}
	type_check_lex(&input_lex);
	return (input_lex);
}

// FUNCTION handle_other
// Handle tokens that start with a character other than >, <, |, " or '.
//
// @param input = pointer to the input string (update as variables are expanded)
// @param i = index to the start of the current token being processed
// @param input_lex = the lex list for tokens to be added to as nodes
//
// @return i = the index to the first character after the processed token.
int	handle_other(char **input, int i, t_lex **input_lex)
{
	int	tok_ind;
	int	tok_len;
	int	error;

	tok_ind = i;
	tok_len = 0;
	error = 0;
	while ((*input)[i] && (*input)[i] != ' ')
	{
		if ((*input)[i] == '|' || (*input)[i] == '>' || (*input)[i] == '<')
			break ;
		if ((*input)[i] == '$')
			tok_len = expand_replace_input(input, &i, tok_len);
		else if ((*input)[i] == '"' || (*input)[i] == 39)
			tok_len = remove_quotes(input, &i, tok_len);
		else
		{
			tok_len++;
			i++;
		}
	}

	error += append_lex(input_lex, ARGUMENT, *input + tok_ind, tok_len);
	if (error)
		printf("ERROR: problem creating lex list in handle_alnum\n"); // free and set input to NULL?

	return (i);
}

// FUNCTION remove_quotes 
// Handle tokens that are quoted strings (either with " or ')
//
// @param input = pointer to the input string (update as variables are expanded)
// @param i = index to the start of the current token being processed
// @param input_lex = the lex list for tokens to be added to as nodes
//
// @return i = the index to the first character after the processed token.
int	remove_quotes(char **input, int *i, int tok_len)
{
	char	start_quote;

	start_quote = (*input)[*i];

	ft_strlcpy(*input + *i, *input + *i + 1, ft_strlen(*input) - *i);

	while ((*input)[*i] && (*input)[*i] != start_quote)
	{
		if (start_quote == '"' && (*input)[*i] == '$')
			tok_len = expand_replace_input(input, i, tok_len);
		else
		{
			tok_len++;
			(*i)++;
		}
	}
	if ((*input)[*i] == start_quote)
		ft_strlcpy(*input + *i, *input + *i + 1, ft_strlen(*input) - *i);

	//if (!(*input)[i])
	// ERROR... end of readline without closing quote... exit gracefully!

	return (tok_len);

	// modify to take input_lex = null (don't create lex list)
	// May to re-use for export function when parsing concatenated strings
}

// FUNCTION handle_pipe
// Handle pipe tokens (|)
//
// @param inp = pointer to the input string (update as variables are expanded)
// @param i = index to the start of the current token being processed
// @param input_lex = the lex list for tokens to be added to as nodes
//
// @return i = the index to the first character after the processed token.
int	handle_pipe(char *inp, int i, t_lex **input_lex)
{
	int	tok_ind;
	int	tok_len;
	int	error;

	tok_ind = i;
	tok_len = 1;
	error = 0;
	error += append_lex(input_lex, PIPE, inp + tok_ind, tok_len);
	if (error)
		printf("ERROR: problem creating lex list in handle_pipe\n"); // free and set input to NULL?
	return (tok_ind + tok_len);
}


// FUNCTION handle_redir
// Handle tokens that start with a redirection character (< or >)
//
// @param inp = pointer to the input string (update as variables are expanded)
// @param i = index to the start of the current token being processed
// @param input_lex = the lex list for tokens to be added to as nodes
//
// @return i = the index to the first character after the processed token.
int	handle_redir(char *inp, int i, t_lex **input_lex)
{
	int				tok_ind;
	int				tok_len;
	int				error;
	enum e_ltype	rtype;

	tok_ind = i;
	tok_len = 0;
	error = 0;
	if (valid_redir_len(inp + i, &rtype))
		tok_len = valid_redir_len(inp + i, &rtype);
	else if (inp[i] != inp[i + 1])
	{
		printf("mshell: syntax error near unexpected token `%c'\n", inp[i + 1]);
		// EXIT GRACEFULLY ... free and set inp to NULL? Needs to get **inp if so...
	}
	else if (inp[i] == inp[i + 1] && (inp[i + 2] == '>' || inp[i + 2] == '<'))
	{
		printf("mshell: syntax error near unexpected token `%c'\n", inp[i + 2]);
		// EXIT GRACEFULLY ... free and set inp to NULL? Needs to get **inp if so...
	}
	error += append_lex(input_lex, rtype, inp + tok_ind, tok_len);
	if (error)
		printf("ERROR: problem creating lex list in handle_redir\n");

	return (tok_ind + tok_len);
}


