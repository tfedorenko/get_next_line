/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:25:43 by tfedoren          #+#    #+#             */
/*   Updated: 2022/04/19 19:29:00 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
    char *buf;
    size_t bytes_read;
	char *line;
	char *newline;
	static char *rest;
    int linelength;
    int i;
	int j;
	int k;
	int n;
	int m;

	if (*rest != '\0')
	{
		if (ft_strchr(*rest, '\n'))
		{
			n = 0;
			while (*rest != '\n')
			{
				n++;
			}
			line = malloc(sizeof(char) * (n + 1));
			m = 0;
			while (rest[m] != '\n' && m < n)
			{
				line[m] = rest[m];
				m++;
			}
		}	
	}

    bytes_read = read(fd, buf, BUFFER_SIZE);

    linelength = 0;
    while (buf[linelength] != '\n' && buf[linelength] != '\0')
    {
        linelength++;
    }
    line = malloc(sizeof(char) * (linelength + 1));
	rest = malloc(sizeof(char) * (BUFFER_SIZE - linelength));
	
	if(!line)
		return (NULL);
	
	i=0;
	j=0;
	k=0;
	while (buf[i] != '\0')
	{
		if (buf[i] != '\n')
		{
			line[j] = buf[i];
			j++;
			i++;
		}
		else if (j < BUFFER_SIZE)
		{
			rest[k] = buf[i+1];
			k++;
			i++;
		}
		line[linelength] = "\n";
	}

	
	
}

int main()
{
	int fd;

    fd = open("test1.txt", O_RDONLY);
	get_next_line(fd);
}
