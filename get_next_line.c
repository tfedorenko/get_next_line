/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:25:43 by tfedoren          #+#    #+#             */
/*   Updated: 2022/04/25 20:26:34 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
static char buff[BUFFER_SIZE + 1];
char *line;
int i;
int count;
 
 if (fd < 0)
	return (NULL);
	line = (char *)malloc(sizeof(char));
	line[0] = '\0';	
count = 0;
i = 0;
while (!ft_strchr(buff, '\n'))
	{
		if (*buff)
			line = ft_strjoin(line, buff);
		count = read(fd, buff, BUFFER_SIZE);
		if (count <= 0 && (!*line))	
		{
			free(line);
			return(NULL);
		}
		buff[count] = '\0';
		if (!ft_strchr(buff, '\n') && count < BUFFER_SIZE)
		{
			line = ft_strjoin(line, buff);
			ft_memset(buff, '\0', 1);
			return line;
		}
	}
	line = ft_strjoin(line, buff);
	//Buff - line 
	//9
	ft_memmove(buff, &buff[ft_strlen(line)], (BUFFER_SIZE - ft_strlen(line)));
	ft_memset(&buff[BUFFER_SIZE - ft_strlen(line)], '\0', ft_strlen(line));
	return line;
	
}

//  int	main(int argc, char *argv[])
//  {
//  	int	fd;
// 	char	*output1;

// 	fd = open(argv[1], O_RDONLY);
	
// 	for (int j = 0; j < 10; j++){
// 		output1 = get_next_line(fd);
//  		write(1, output1, ft_strlen(output1));
// 		// free(output1);
// 	}
//  	return (0);
//  }



















// char		*line;
	// static char	storage[BUFFER_SIZE + 1]
	// char		*temp_storage;
	// int			i;
	

	// if (fd < 0 || BUFFER_SIZE <= 0)
	// {
	// 	return (NULL);
	// }
	// // temp_storage = (char *)malloc(sizeof(char) * (ft_strlen(storage) + 1));
	// // if (!temp_storage)
	// // i = 0;
	// // while (i < ft_strlen(storage))
	// // {		
	// // 	temp_storage[i] = storage[i];
	// // 	i++;
	// // }	
	// // 	return (NULL);
	// // if(ft_check_first_entry(temp_storage) == 1)
	// // {
	// // 	temp_storage = ft_read_to_storage(fd, temp_storage);
	// // }else 
	// // {
	// // 	while (temp_storage[i] != '\n')
	// // 	line =ft_create_line(temp_storage);
	// // }
	// // i = 0;
	// // if (firstEntry == 0){
	// // 	firstEntry++;
	// // 	temp_rest[0] = '\0';
	// // }
	// // else{
	
	// // }

	// // printf("address of variable %p\n", temp_rest);
	// temp_rest = ft_check_rest(fd, temp_rest);
	// if (!temp_rest)
	// 	return(NULL);
	// else
	// // printf("Siemnako");
	// line = ft_create_line(temp_rest);
	// temp_rest = ft_update_rest(temp_rest);
	// if(!temp_rest)
	// {
	// 	return NULL;
	// }
	// i = 0;
	// while (i < ft_strlen(temp_storage))
	// {
	
	// 	storage[i] = temp_storage[i];
	// 	i++;
	// }
	// storage[i] = '\0';
	// free(temp_rest);
	// if (!line)
	// 	return (NULL);

	// return (line);
	// //free(line);