/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:13:26 by ruzhang           #+#    #+#             */
/*   Updated: 2024/09/29 14:55:09 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_file(int fd, char *buffer)
{
	char	current[BUFFER_SIZE + 1];
	int		sz;
	char	*tmp;

	while (!ft_strchr(buffer, '\n'))
	{
		sz = read(fd, current, BUFFER_SIZE);
		if (sz == -1)
			return (free(buffer), NULL);
		if (sz == 0)
			return (buffer);
		current[sz] = '\0';
		tmp = ft_strjoin(buffer, current);
		free(buffer);
		if (!tmp)
			return (NULL);
		buffer = tmp;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*tmp;
	int			len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		line = ft_substr(buffer, 0, len);
	else
		line = ft_substr(buffer, 0, len + 1);
	tmp = ft_substr(buffer, len + 1, ft_strlen(buffer));
	free(buffer);
	buffer = tmp;
	return (line);
}
