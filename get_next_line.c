/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puiucorina <puiucorina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:33:25 by puiucorina        #+#    #+#             */
/*   Updated: 2023/08/07 14:27:28 by puiucorina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	if (c == 0)
	{
		i = ft_strlen((char *)s);
		return (&s[i]);
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

char	*ft_read_line(char *start_line)
{
	int		i;
	char	*line;

	if (!start_line || !start_line[0])
		return (NULL);
	i = 0;
	while (start_line[i] && start_line[i] != '\n')
		i++;
	if (start_line[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (start_line[i] && start_line[i] != '\n')
	{
		line[i] = start_line[i];
		i++;
	}
	if (start_line[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_new_start(char *start)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	if (start[i] == '\0')
	{
		free(start);
		return (NULL);
	}
	i = i + (start[i] == '\n');
	buff = (char *)malloc((ft_strlen(start) - i) * sizeof(char) + 1);
	if (!buff)
		return (NULL);
	j = 0;
	while (start [i + j])
	{
		buff[j] = start[i + j];
		j++;
	}
	buff[j] = '\0';
	free(start);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	int			bytes_read;
	char		*buffer;
	char		*merged_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	buffer = (char *)malloc(1 + BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!(ft_strchr(remainder, '\n')) && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(remainder), free(buffer), remainder = NULL);
		buffer[bytes_read] = '\0';
		merged_str = ft_strjoin(remainder, buffer);
		free(remainder);
		remainder = merged_str;
	}
	free (buffer);
	buffer = ft_read_line(remainder);
	remainder = ft_new_start(remainder);
	return (buffer);
}
