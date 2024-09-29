/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:14:01 by ruzhang           #+#    #+#             */
/*   Updated: 2024/09/10 15:06:36 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif


# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
// delete
# include <stdio.h>
# include <string.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*ft_strchr(char *s);
void	free_list(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
void	add_node(t_list **lst, char	*content);
int		ft_strlen(char *s);
char	*get_next_line(int fd);
// delete it
void	print_list(t_list *lst);

#endif
