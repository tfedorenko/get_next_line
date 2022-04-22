/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:25:43 by tfedoren          #+#    #+#             */
/*   Updated: 2022/04/22 19:40:22 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	char		*line;
	static char	rest[BUFFER_SIZE + 1];
	char		*temp_rest;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp_rest = ft_check_rest(fd, rest);
	if (!temp_rest)
		return (NULL);
	i = 0;
	while (i <= ft_strlen(temp_rest))
	{
		rest[i] = temp_rest[i];
		i++;
	}
	line = ft_create_line(rest);
	temp_rest = ft_update_rest(rest);
	i = 0;
	while (i < ft_strlen(temp_rest))
	{
		rest[i] = temp_rest[i];
		i++;
	}
	rest[i] = '\0';
	if (!line)
		return (NULL);
	return (line);
}

int	main(int argc, char *argv[])
{
	int	fd;
	char	*output1;
	//char	*output2;
	//char	*output2;

	//printf("%d The amount of arguments\n", argc);
	//for (int i = 0; i < argc; i++)
	//	printf("%s This is argument #%d\n", argv[i], i);

	fd = open(argv[1], O_RDONLY);
	
	output1 = get_next_line(fd);
	//write(1, "result is here:\n", 16);
	write(1, output1, ft_strlen(output1));
	printf("%p address of the line\n", output1);
	output1 = get_next_line(fd);
	write(1, output1, ft_strlen(output1));
	printf("%p address of the line\n", output1);
	output1 = get_next_line(fd);
	write(1, output1, ft_strlen(output1));
	printf("%p address of the line\n", output1);
	output1 = get_next_line(fd);
	write(1, output1, ft_strlen(output1));
	printf("%p address of the line\n", output1);
	output1 = get_next_line(fd);
	write(1, output1, ft_strlen(output1));
	printf("%p address of the line\n", output1);
	output1 = get_next_line(fd);
	write(1, output1, ft_strlen(output1));
	return (0);
}
