/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:25:43 by tfedoren          #+#    #+#             */
/*   Updated: 2022/04/21 22:18:37 by tfedoren         ###   ########.fr       */
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
	char	*temp_rest;
	int i;
	

	temp_rest = ft_check_rest(fd, rest);
	//printf("%s <= here 1\n", temp_rest);
	i = 0;
	while (i <= ft_strlen(temp_rest))
	{
		//ft_strlcpy(rest, temp_rest, ft_strlen(temp_rest));
		rest[i] = temp_rest[i];
		i++;
	}
	//printf("%s <= here 1,5\n", rest);
	
	//free(temp_rest);
	//printf("I'm here party time");
	line = ft_create_line(rest);
	
	//free(temp_rest);
	//printf("%s <= here 2\n", line);
	temp_rest = ft_update_rest(rest);
	i = 0;
	while (i <= ft_strlen(temp_rest))
	{
		//ft_strlcpy(rest, temp_rest, ft_strlen(temp_rest));
		rest[i] = temp_rest[i];
		i++;
	}
	rest[i] = '\0';
	//ft_strlcpy(rest, temp_rest, ft_strlen(temp_rest-1));
	//printf("%s <= here 3\n", temp_rest);
	//printf("%s <= here 4\n", rest);
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
	//printf("I'm here\n");
	output1 = get_next_line(fd);
	write(1, "result is here:\n", 16);
	write(1, output1, ft_strlen(output1));
	output1 = get_next_line(fd);
	write(1, output1, ft_strlen(output1));
	output1 = get_next_line(fd);
	write(1, output1, ft_strlen(output1));
	return (0);
}
