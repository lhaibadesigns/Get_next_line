/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-haib <ael-haib@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:58:56 by ael-haib          #+#    #+#             */
/*   Updated: 2024/07/13 17:27:14 by ael-haib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

/* int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while (line > 0)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
	if (close(fd) == -1)
	{
		perror("Error closing file");
		return (1);
	}
	return (0);
} */

int main()
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	if(fd == -1)
		printf("error");
	while(1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
			printf("%s", line);
			free(line);
	}
	return(0);

}