/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:25:36 by ruzhang           #+#    #+#             */
/*   Updated: 2024/09/29 11:33:46 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_file(int fd, char *buffer)
{
	char	*current;
	int		sz;
	char	*tmp;

	while (!ft_strchr(buffer, '\n'))
	{
		current = malloc(BUFFER_SIZE + 1);
		if (!current)
			return (NULL);
		sz = read(fd, current, BUFFER_SIZE);
		if (sz == -1)
			return (free(current), free(buffer), NULL);
		if (sz == 0)
			return (free(current), buffer);
		current[sz] = '\0';
		tmp = ft_strjoin(buffer, current);
		free(current);
		free(buffer);
		if (!tmp)
			return (NULL);
		buffer = tmp;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[LIMIT];
	char		*line;
	char		*tmp;
	int			len;

	if (fd > LIMIT)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	len = 0;
	while (buffer[fd][len] && buffer[fd][len] != '\n')
		len++;
	line = ft_substr(buffer[fd], 0, len + 1);
	tmp = ft_substr(buffer[fd], len + 1, ft_strlen(buffer[fd]));
	free(buffer[fd]);
	buffer[fd] = tmp;
	return (line);
}
