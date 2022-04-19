/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:25:43 by tfedoren          #+#    #+#             */
/*   Updated: 2022/04/19 14:05:19 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
    char buf[1000];
    size_t count;
    size_t bytes_read;
	char *oldline;
	char *line;
	char *newline;
    int linelength;
	int k;
    int i;
	int j;

    count = 0;
    bytes_read = read(fd, buf, count);

    k = 0;
    linelength = 0;
    while (buf[k] != '\n' && buf[k] != '\0')
    {
        linelength++;
        k++;
    }
    line = malloc(sizeof(char) * (linelength + 1));
	
    
    i = 0;
	j = 0;
	newline = (char *)malloc(sizeof(char) * (ft_strlen(oldline) + ft_strlen(line) + 1));
	if (!newline)
		return (NULL);
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		newline[i] = buf[i];
		i++;
	}
	
	while (s2[j] && i < (ft_strlen(s1) + ft_strlen(s2)))
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
    
    
    
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
