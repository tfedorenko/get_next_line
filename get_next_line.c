/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:25:43 by tfedoren          #+#    #+#             */
/*   Updated: 2022/04/11 17:44:15 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
    static char buf[1000];
    size_t count;
    size_t bytes_read;
	char *line;
    int linelength;
    int i;

    count = 0;
	count = sizeof(buf);
    bytes_read = read(fd, buf, count);

    i = 0;
    linelength = 0;
    while (buf[i] != '\n' && buf[i] != '\0')
    {
        linelength++;
        i++;
    }

    while(!)
    
    line = malloc(sizeof(char) * linelength);
    line = ft_strlcpy
    if (!line)
        return (NULL);
    ft_putstr(line);
       
}

int main()
{
	int fd;

    fd = open("test1.txt", O_RDONLY);
	get_next_line(fd);
}
