/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:25:43 by tfedoren          #+#    #+#             */
/*   Updated: 2022/04/20 21:18:12 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	char	*buf;
	size_t	bytes_read;
	char	*line;
	char	*newline;
	static char	rest[BUFFER_SIZE + 1];
	int	linelength;
	int	i;
	int	j;
	int	restlength;
	

	

	bytes_read = read(fd, buf, BUFFER_SIZE);
	buf[bytes_read] = '\0';
	
	if (bytes_read != 0)
	{
		
	}
	/*linelength = 0;
	while (buf[linelength] != '\n' && buf[linelength] != '\0')
	{
		linelength++;
	}
	//printf("I'm here\n");
	line = (char *)malloc(sizeof(char) * (linelength + 1));
	//rest = malloc(sizeof(char) * (BUFFER_SIZE - linelength));
	if (!line)
		return (NULL);

	i = 0;
	j = 0;
	restlength = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
	{
		line[j] = buf[i];
		j++;
		i++;
		line[linelength] = '\n';
	}
	return (line);*/

	while (i < BUFFER_SIZE && buf != '\0')
	{
		restlength++;
		rest = (char *)malloc(sizeof(char) * restlength);
	}
}

int	main(int argc, char *argv[])
{
	int	fd;
	char	*output;

	//printf("%d The amount of arguments\n", argc);
	//for (int i = 0; i < argc; i++)
	//	printf("%s This is argument #%d\n", argv[i], i);

	fd = open(argv[1], O_RDONLY);
	// printf("I'm here\n");
	output = get_next_line(fd);
	write(1, output, ft_strlen(output));
	return (0);
}
