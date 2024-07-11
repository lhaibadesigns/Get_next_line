/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-haib <ael-haib@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:17:15 by ael-haib          #+#    #+#             */
/*   Updated: 2024/07/11 17:17:19 by ael-haib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    char buf[100];
    int fd;
    int nb_read;
    int count;
    int pos = 0;
    static char var[100];

    fd = open("cat.txt", O_RDWR | O_CREAT, 777);
    if (fd == -1)
    {
        perror("failed");
        return 1;
    }

    if (write(fd, "KKKKKKKK", 8) == -1)
    {
        perror("failed");
        close(fd);
        return 1;
    }

    lseek(fd, 0, SEEK_SET);
    count = 0;
    while ((nb_read = read(fd, buf, 2)) > 0)
    {

        buf[nb_read] = '\0';

        if (pos + nb_read < sizeof(var))
        {
            memcpy(&var[pos], buf, nb_read);
            pos += nb_read;
            var[pos] = '\0';
        }
        else
        {
            fprintf(stderr, "static array is full\n");
            close(fd);
            return 1;
        }
        count++;
    }

    printf("%s\n", var);
    if (nb_read == -1)
    {
        perror("read error");
        close(fd);
        return 1;
    }
    return 0;
}