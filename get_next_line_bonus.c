/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:25:43 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/01 16:17:18 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	buff_after_line(char *buff)
{
	int			rest_buff;

	rest_buff = ft_strlen(buff) - ft_strlen(ft_strchr(buff, '\n') + 1);
	ft_memmove(buff, &buff[rest_buff], ft_strlen(ft_strchr(buff, '\n') + 1));
	buff[ft_strlen(buff) - rest_buff] = '\0';
}

char	*create_last(char *buff, char *line)
{
	line = ft_strjoin(line, buff);
	buff[0] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buff[10240][BUFFER_SIZE + 1];
	char		*line;
	int			count;

	if (fd < 0)
		return (NULL);
	line = (char *)malloc(sizeof(char));
	line[0] = '\0';
	while (!ft_strchr(buff[fd], '\n'))
	{
		if (&buff[fd])
			line = ft_strjoin(line, buff[fd]);
		count = read(fd, buff[fd], BUFFER_SIZE);
		if (count <= 0 && (!*line))
		{
			free(line);
			return (NULL);
		}
		buff[fd][count] = '\0';
		if (!ft_strchr(buff[fd], '\n') && count < BUFFER_SIZE)
			return (create_last(buff[fd], line));
	}
	line = ft_strjoin(line, buff[fd]);
	buff_after_line(buff[fd]);
	return (line);
}
