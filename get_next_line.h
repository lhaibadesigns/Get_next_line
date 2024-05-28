/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-haib <ael-haib@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:45:39 by ael-haib          #+#    #+#             */
/*   Updated: 2024/05/28 19:52:46 by ael-haib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GET_NEXT_LINE

#ifdef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <fcntl.h>

char *get_next_line(int fd);
