/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-haib <ael-haib@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:58:46 by ael-haib          #+#    #+#             */
/*   Updated: 2024/07/11 16:41:52 by ael-haib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*get_freed(char **p1, char **p2)
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

char	*get_line_(char **buffer)
{
	char	*line;
	char	*tmp;
	size_t	i;

	if (!*buffer || !**buffer)
		return (get_freed(buffer, NULL));
	i = 0;
	while ((*buffer)[i] != '\n' && (*buffer)[i] != '\0')
		i++;
	if ((*buffer)[i] != '\0')
		i++;
	tmp = *buffer;
	line = ft_substr(*buffer, 0, i);
	if (!line)
		return (get_freed(buffer, NULL));
	*buffer = ft_substr(*buffer, i, ft_strlen(*buffer + i));
	if (!*buffer)
		return (get_freed(&tmp, &line));
	get_freed(&tmp, NULL);
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
		return (get_freed(&s1, &s2));
	ft_memcpy(str, s1, len_s1);
	ft_memcpy(str + len_s1, s2, len_s2);
	str[len_s2 + len_s1] = '\0';
	get_freed(&s1, NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*buff_read;
	int			nbyte;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nbyte = 1;
	buff_read = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff_read)
		return (get_freed(&buffer, NULL));
	while (!ft_strchr(buffer, '\n') && nbyte > 0)
	{
		nbyte = read(fd, buff_read, BUFFER_SIZE);
		if (nbyte == -1)
			return (get_freed(&buffer, &buff_read));
		if (nbyte > 0)
		{
			buff_read[nbyte] = '\0';
			buffer = get_join(buffer, buff_read);
			if (!buffer)
				return (NULL);
		}
	}
	free(buff_read);
	return (get_line_(&buffer));
}
