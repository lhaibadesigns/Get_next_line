/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-haib <ael-haib@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:17:05 by ael-haib          #+#    #+#             */
/*   Updated: 2024/07/13 17:58:12 by ael-haib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*get_free(char **p1, char **p2)
{
	if (p1 && *p1 != NULL)
	{
		free(*p1);
		*p1 = NULL;
	}
	if (p2 && *p2 != NULL)
	{
		free(*p2);
		*p2 = NULL;
	}
	return (NULL);
}

char	*get_the_line(char **buffer)
{
	char	*line;
	char	*tmp;
	size_t	i;

	if (!*buffer || !**buffer)
		return (get_free(buffer, NULL));
	i = 0;
	while ((*buffer)[i] != '\n' && (*buffer)[i] != '\0')
		i++;
	if ((*buffer)[i] != '\0')
		i++;
	tmp = *buffer;
	line = ft_substr(*buffer, 0, i);
	if (!line)
		return (get_free(buffer, NULL));
	*buffer = ft_substr(*buffer, i, ft_strlen(*buffer + i));
	if (!*buffer)
		return (get_free(&tmp, &line));
	get_free(&tmp, NULL);
	return (line);
}

char	*get_join(char *s1, char *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1)
		len_s1 = 0;
	else
		len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (get_free(&s1, &s2));
	ft_memcpy(str, s1, len_s1);
	ft_memcpy(str + len_s1, s2, len_s2);
	str[len_s2 + len_s1] = '\0';
	get_free(&s1, NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*read_buffer;
	int			byte_number;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	byte_number = 1;
	read_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buffer)
		return (get_free(&buffer, NULL));
	while (!ft_strchr(buffer, '\n') && byte_number > 0)
	{
		byte_number = read(fd, read_buffer, BUFFER_SIZE);
		if (byte_number == -1)
			return (get_free(&buffer, &read_buffer));
		if (byte_number > 0)
		{
			read_buffer[byte_number] = '\0';
			buffer = get_join(buffer, read_buffer);
			if (!buffer)
				return (NULL);
		}
	}
	free(read_buffer);
	return (get_the_line(&buffer));
}
