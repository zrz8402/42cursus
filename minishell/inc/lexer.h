/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:30:48 by ruzhang           #+#    #+#             */
/*   Updated: 2024/11/26 09:42:18 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

#include "libft.h"

typedef struct s_token
{
	int				type;
	char			*content;
	struct s_token *next;
}	t_token;

typedef enum	e_type
{
	WORD,
	REDIR_IN,
	REDIR_OUT,
	HEREDOC,
	APPEND,
}	t_type;

#endif