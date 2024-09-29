/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:57:30 by ruzhang           #+#    #+#             */
/*   Updated: 2024/09/11 13:38:55 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*read_file(int fd, t_list *buffer, int sz)
{
	char	*current;

	while (sz > 0)
	{
		current = malloc(BUFFER_SIZE + 1);
		if (!current)
			return (NULL);
		sz = read(fd, current, BUFFER_SIZE);
		if (sz == -1)
		{
			free(current);
			return (NULL);
		}
		if (sz == 0)
		{
			free(current);
			return (buffer);
		}
		current[sz] = '\0';
		add_node(&buffer, current);
		if (ft_strchr(current))
			break ;
	}
	return (buffer);
}

int	line_len(t_list *buffer)
{
	char	*newline_pos;
	int		len;

	len = 0;
	if (!buffer)
		return (0);
	while (buffer)
	{
		if (!buffer->content)
			return (0);
		newline_pos = ft_strchr(buffer->content);
		if (newline_pos)
			return (len + newline_pos - buffer->content + 1);
		len += ft_strlen(buffer->content);
		buffer = buffer->next;
	}
	return (len);
}

char	*extract_line(t_list **buffer, char *line)
{
	t_list	*tmp;
	int		i;
	int		j;

	if (!line || !buffer || !*buffer)
		return (NULL);
	tmp = *buffer;
	j = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->content[i])
		{
			if (tmp->content[i] == '\n')
			{
				line[j++] = '\n';
				line[j] = '\0';
				return (line);
			}
			line[j++] = tmp->content[i++];
		}
		tmp = tmp->next;
	}
	line[j] = '\0';
	return (line);
}

t_list	*polish_buffer(t_list *buffer)
{
	t_list	*rest;
	char	*left;
	int		i;

	if (!buffer || !ft_lstlast(buffer) || !ft_lstlast(buffer)->content)
		return (NULL);
	left = ft_strchr(ft_lstlast(buffer)->content);
	if (!left)
		return (NULL);
	left++;
	if (*left == '\0')
		return (NULL);
	rest = malloc(sizeof(t_list));
	if (!rest)
		return (NULL);
	rest->content = bzero(malloc(ft_strlen(left) + 1));
	if (!rest->content)
	{
		free(rest);
		return (NULL);
	}
	i = 0;
	while (*left)
		rest->content[i++] = *left++;
	rest->content[i] = '\0';
	return (rest);
}

char	*get_next_line(int fd)
{
	static t_list	*buffer;
	char			*line;
	t_list			*rest;
	int				sz;
	int				len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	sz = 1;
	buffer = read_file(fd, buffer, sz);
	if (!buffer)
		return (NULL);
	len = line_len(buffer);
	if (!len)
		return (NULL);
	line = bzero(malloc(line_len(buffer) + 1));
	if (!line)
		return (NULL);
	line = extract_line(&buffer, line);
	rest = polish_buffer(buffer);
	free_list(&buffer);
	buffer = rest;
	return (line);
}
