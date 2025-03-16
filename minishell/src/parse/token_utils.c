/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <kmartin@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:52:34 by kmartin           #+#    #+#             */
/*   Updated: 2025/03/12 17:27:03 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

// FUNCTION valid_redir_len
// Checks if a token beginning with '<' or '>' is a valid redirection, and 
// assigns the appropriate token type (or NO_TYPE, if not valid).
//
// @param in_ptr = a pointer to the start of the token in the input string
// @param rtype = a pointer to the token type (update as appropriate)
// 
// @return the length of the redirection token if a valid redirection 
// @return 0 if it is not a valid redirection token
int	valid_redir_len(char *in_ptr, enum e_ltype *rtype)
{
	if (in_ptr[0] == '<' && in_ptr[1] != '<' && in_ptr[1] != '>')
	{
		*rtype = RED_IN;
		return (1);
	}
	if (in_ptr[0] == '>' && in_ptr[1] != '<' && in_ptr[1] != '>')
	{
		*rtype = RED_OUT;
		return (1);
	}
	if (ft_strncmp(in_ptr, "<<", 2) == 0 && in_ptr[2] != '<' && in_ptr[2] != '>')
	{
		*rtype = HEREDOC;
		return (2);
	}
	if (ft_strncmp(in_ptr, ">>", 2) == 0 && in_ptr[2] != '<' && in_ptr[2] != '>')
	{
		*rtype = APPEND;
		return (2);
	}
	*rtype = NO_TYPE;
	return (0);
}

// FUNCTION count_var_len
// Count the number of characters (including $ in a variable)
// 
// Note variable naming conventions: first character can be alphabetical or '_'
// but not a digit... subsequent characters can be alphanumerical or '_'.
//
// NB: only counts the first variable it finds - best to pass it the possition of
// the $ of the variable to be counted, or it may attempt to count from any '$'
// it finds earlier in the string (e.g. if '$' is included in previous expansion).
//
// @param input = the string to search for a variable to count (counts first one)
// @param i = the index in the string to start searching for a variable
//
// @return length of valid variable name (including $)
int	count_var_len(char *input, int i)
{
	int	var_len;
	char *in_ptr;

	in_ptr = input + i;

	var_len = 0;
	while (*in_ptr && *in_ptr != '$')
		in_ptr++;
	if (*in_ptr == '$')
	{
		in_ptr++;
		var_len++;
	}
	else
		return (0);
	if (!(ft_isalpha(*in_ptr)) && *in_ptr != '_')
		return (2);
	while (*in_ptr && (ft_isalnum(*in_ptr) || *in_ptr == '_'))
	{
		var_len++;
		in_ptr++;
	}
	return (var_len);
}

// FUNCTION expand_replace_input 
// Handle variables - both individual tokens and as parts of larger tokens.
//
// Expand variables where possible (when not ' quoted) - create a new string
// that includes the expanded variable (variables without values will be removed),
// and replace the original input with the new string. 
//
// Note that the index is updated to advance past the expanded variable.
//
// @param input = the entire instruction (variables to be progressively expanded)
// @param i = the index to the current character in the input string
// @param tok_len = the length of the token so far (up to the start of the variable)
//
// @return the updated token length
int	expand_replace_input(char **input, int *i, int tok_len)
{
	int		exp_var_len;
	int		new_str_len;
	char	*exp_var;
	char	*new_str;

	exp_var = expand_variable(*input + *i);
	exp_var_len = ft_strlen(exp_var);

	new_str_len = ft_strlen(*input) - count_var_len(*input, *i) + exp_var_len;
	new_str = (char *)malloc(sizeof(char) * (new_str_len + 1));

	if (!new_str)
		printf("GRACEFUL EXIT!\n");
	
	replace_input(&new_str, *input, *i, exp_var);
	
	free(exp_var); // free expanded variable
	free(*input); // free original input
	(*input) = new_str; // set original input to point to new expanded string 
	
	*i = *i + exp_var_len;

	return (tok_len + exp_var_len);
}

// FUNCTION expand_variable
// Return the expanded value of a variable, if it exists;
// otherwise, return an empty string.
// String memory allocated with malloc must be freed by caller.
//
// NB variable names can start with alphabetic character or underscores
//    and can contain digits... 
//
// PLACEHOLDER FUNCTION - MUST USE GETENV...
char	*expand_variable(char *in_ptr)
{
	int		exp_var_len;
	//char	*var_name;
	char	*exp_var;

	exp_var_len = 0;
	if (in_ptr[1] == ' ') // isolated $ - return as uninterpreted character
		exp_var_len = 1;
	else if (!ft_isalpha(in_ptr[1]) && in_ptr[1] != '_')
		exp_var_len = 0;
	// else get value from get_env... strdup variable name using token name... free after
	// ft_strlen(exp_var) to get exp_var_len
	// use ft_strdup instead of mallocing directly? Only malloc for isolated $?

	exp_var = (char *)malloc(sizeof(char) * (exp_var_len + 1));

	if (!exp_var)
		printf("GRACEFUL EXIT!\n");

	if (exp_var_len == 1)
		exp_var[0] = '$';

	exp_var[exp_var_len] = 0;

	return (exp_var);
}

// FUNCTION replace_input
// 
// Replace the provided input string with a shorter/longer one.
// 
// @param new_str = the memory allocated to copy the variable-expanded input
// @param input = the original input string (including unexpanded variable)
// @param i = index of start of current token
// @param exp_var = the expanded value of the variable being processed
void	replace_input(char **new_str, char *input, int i, char *exp_var)
{
	int	var_len;
	int tok_ind;
	int n;

	var_len = count_var_len(input, i);

	// copy input string before current variable
	n = 0;
	while (n < i)
	{
		(*new_str)[n] = input[n];
		n++;
	}

	// copy result of expanding variable (might be empty string)
	tok_ind = i;
	n = 0;
	while (exp_var[n])
	{
		(*new_str)[i] = exp_var[n];
		i++;
		n++;
	}

	// copy rest of input string, after expanded variable, and null-term
	n = tok_ind + var_len;
	while (input[n])
	{
		(*new_str)[i] = input[n];
		i++;
		n++;
	}
	(*new_str)[i] = 0;
}

