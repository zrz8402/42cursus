/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <kmartin@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:52:34 by kmartin           #+#    #+#             */
/*   Updated: 2025/03/21 14:54:21 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// FUNCTION valid_redir_len
// Checks if a token beginning with '<' or '>' is a valid redirection, and 
// assigns the appropriate token type (or NO_TYPE, if not valid).
//
// @param inp = a pointer to the start of the token in the input string
// @param rtype = a pointer to the token type (update as appropriate)
// 
// @return the length of the redirection token if a valid redirection 
// @return 0 if it is not a valid redirection token
int	valid_redir_len(char *inp, enum e_ltype *rtype)
{
	if (inp[0] == '<' && inp[1] != '<' && inp[1] != '>')
	{
		*rtype = RED_IN;
		return (1);
	}
	if (inp[0] == '>' && inp[1] != '<' && inp[1] != '>')
	{
		*rtype = RED_OUT;
		return (1);
	}
	if (ft_strncmp(inp, "<<", 2) == 0 && inp[2] != '<' && inp[2] != '>')
	{
		*rtype = HEREDOC;
		return (2);
	}
	if (ft_strncmp(inp, ">>", 2) == 0 && inp[2] != '<' && inp[2] != '>')
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
// Isolated '$' are left as-is.
//
// '$?' are replaced with the minishell status of the last command.
// 
// Note variable naming conventions: first character can be alphabetical or '_'
// but not a digit... subsequent characters can be alphanumerical or '_'; if a 
// variable starts with a digit (forbidden) then only the '$' and first digit
// are counted (and will be removed from the string).
//
// @param input = string containing variable to count chars (including '$') 
// @param i = the index in the string of the start of the variable (must be '$')
//
// @return length of valid variable name (including $)
int	count_var_len(char *input, int i)
{
	int		var_len;
	char	*in_ptr;

	in_ptr = input + i;
	var_len = 0;
	if (*in_ptr == '$')
	{
		in_ptr++;
		var_len++;
	}
	else
		return (0);
	if (*in_ptr == ' ' || *in_ptr == '"' || *in_ptr == '\0')
		return (1);
	if (*in_ptr == '?')
		return (2);
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
// Create a new string that includes the expanded variable (variables without
// values and variables with invalid names will be removed), and replace the 
// original input with the new string. 
//
// Note that the index is updated to advance past the expanded variable.
//
// If there is an error in allocating memory for the new string, the input is
// freed and set to NULL.
//
// @param input = entire instruction (variables to be progressively expanded)
// @param i = the index to the current character in the input string
// @param tok_len = length of the token so far (to the start of the variable)
// @param mshell = struct containing the previous command status and envp
//
// @return the updated token length
int	expand_replace_input(char **input, int *i, int tok_len, t_program *mshell)
{
	int		exp_var_len;
	int		new_str_len;
	char	*exp_var;
	char	*new_str;

	exp_var = expand_variable(*input + *i, mshell);
	if (!exp_var)
	{
		free_null_input(input);
		return (tok_len);
	}
	exp_var_len = ft_strlen(exp_var);
	new_str_len = ft_strlen(*input) - count_var_len(*input, *i) + exp_var_len;
	new_str = (char *)malloc(sizeof(char) * (new_str_len + 1));
	if (!new_str)
		free_null_input(input);
	else
		replace_input(&new_str, *input, *i, exp_var);
	free(exp_var);
	free(*input);
	(*input) = new_str;
	*i = *i + exp_var_len;
	return (tok_len + exp_var_len);
}

// FUNCTION expand_variable
// Return the expanded value of a variable, if it exists;
// otherwise, return an empty string.
//
// NB variable names can start with alphabetic character or underscores
// and can contain digits; if a variable starts with another character, 
// the '$' and one subsequent character are excised from the input string. 
//
// String memory allocated with malloc must be freed by caller.
//
// @param in_ptr = the index to the start of the variable ('$')
// @param mshell = struct containing the previous command status and envp
//
// @return the expanded value of the variable if it exists
// @return an empty string if the variable does not exit
// @return NULL if an error in memory allocation
char	*expand_variable(char *in_ptr, t_program *mshell)
{
	char	*exp_var;
	char	*var_name;
	char	*var_val_ptr;

	exp_var = NULL;
	if (in_ptr[1] == ' ' || in_ptr[1] == '"' || in_ptr[1] == '\0')
		exp_var = ft_strdup("$");
	else if (in_ptr[1] == '?')
		exp_var = ft_itoa(mshell->prev_status);
	else if (!ft_isalpha(in_ptr[1]) && in_ptr[1] != '_')
		exp_var = ft_strdup("");
	else
	{
		var_name = ft_substr(in_ptr, 1, count_var_len(in_ptr, 0) - 1);
		if (!var_name)
			return (NULL);
		var_val_ptr = get_var_value(var_name, mshell->envlst);
		free(var_name);
		if (var_val_ptr)
			exp_var = ft_strdup(var_val_ptr);
		else
			exp_var = ft_strdup("");
	}
	return (exp_var);
}

// FUNCTION replace_input
// 
// Replace the provided input string with a shorter/longer one (new_str):
// - copy input string before current variable (which starts at i),
// - copy result of expanding variable (the exp_var string)
// - copy the rest of the input string, starting after the unexpanded variable
// 
// @param new_str = the memory allocated to copy the variable-expanded input
// @param input = the original input string (including unexpanded variable)
// @param i = index of start of current variable to be expanded 
// @param exp_var = the expanded value of the variable being processed
void	replace_input(char **new_str, char *input, int i, char *exp_var)
{
	int	var_ind;
	int	var_len;
	int	n;

	var_ind = i;
	var_len = count_var_len(input, i);
	n = -1;
	while (n++ < i)
		(*new_str)[n] = input[n];
	n = 0;
	while (exp_var[n])
	{
		(*new_str)[i] = exp_var[n];
		i++;
		n++;
	}
	n = var_ind + var_len;
	while (input[n])
	{
		(*new_str)[i] = input[n];
		i++;
		n++;
	}
	(*new_str)[i] = 0;
}
