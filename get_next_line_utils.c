/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:31:26 by tfedoren          #+#    #+#             */
/*   Updated: 2022/04/22 19:27:43 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;
	
	i = 0;
	if (s)
	{
		while (s[i] != '\0')
			i++;
		return (i);		
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	//if (!s1 || !s2)
	//	return (NULL);
	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\n' && i < ft_strlen(s1))
	{
		str[i] = s1[i];
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
}

char	*ft_strchr(char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		++s;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
			i++;
	return (i);
}

char	*ft_create_line(char *rest)
{
	int	linelength;
	char *line;

	linelength = 0;
	if (!rest[linelength])
		return (NULL);
	while (rest[linelength] != '\n' && rest[linelength] != '\0')
	{
		linelength++;
	}
	line = (char *)malloc(sizeof(char) * (linelength + 1));
	if (!line)
		return (NULL);
	linelength = 0;
	while (rest[linelength] != '\n' && rest[linelength] != '\0')
	{
		line[linelength] = rest[linelength];
		linelength++;
	}
	if (rest[linelength] == '\n')
	{
		line[linelength] = rest[linelength];
		linelength++;
	}
	//if(linelength <= 0)
	//	return (NULL);
	line[linelength] = '\0';
	return (line);
}

char	*ft_check_rest(int fd, char *rest)
{
	char	buf[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = 1;
	while (!ft_strchr(rest, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buf, (BUFFER_SIZE));
		if (bytes_read == -1)
			return (NULL);
		buf[bytes_read] = '\0';
		rest = ft_strjoin (rest, buf);
		if (!rest)
			return (NULL);
	}
	return (rest);
}

char *ft_update_rest(char *rest)
{
	char *str;
	int i;
	int	j;

	i = 0;
	if (!rest[i])
		return (NULL);
	while (rest[i] != '\n' && rest[i] != '\0')
	{
		i++;
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(rest) - i + 2));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (rest[i] != '\0')
	{
		str[j] = rest[i];
		i++;
		j++;
	}
	//rest[0] = '\0';
	return (str);
}
