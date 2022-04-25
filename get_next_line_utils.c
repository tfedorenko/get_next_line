/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:31:26 by tfedoren          #+#    #+#             */
/*   Updated: 2022/04/25 20:24:47 by tfedoren         ###   ########.fr       */
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

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		// printf("%c\n", str[i]);
		str[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\n')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	if (s2[j] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	free(s1);
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

void	*ft_memset(void *dst, int c, size_t len)
{
	size_t	i;
	char	*d;

	d = dst;
	i = 0;
	while (i < len)
	{
		d[i] = c;
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (d == s)
		return (d);
	if (s < d)
	{
		i = n;
		while (i--)
			((char *)d)[i] = ((char *)s)[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((char *)d)[i] = ((char *)s)[i];
			i++;
		}
	}
	return (d);
}



int ft_check_first_entry(char *str)
{
	if(str)
		return (0);
	else
		return (1);
}

// char *ft_check_storage(char *str)
// {
	
// }

// char *ft_read_to_storage(int fd, char *str1)
// {
// 	char *buff;
// 	int count;
	
// 	count = 0;
// 	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	count = read(fd, buff, BUFFER_SIZE);
// 	if (count == -1);
// 	{
// 		free(buff);
// 		return(NULL);
// 	}

// 	buff[count] = '\0';
// 	str1 = ft_strjoin (str1, buff);
// 	free (buff);
// 	if (!str1)
// 		return (NULL);
// 	return (str1);
// }

// char	*ft_create_line(char *str2)
// {
// 	int	linelength;
// 	char *line;


// 	linelength = 0;
// 	if (!str2)
// 		return (NULL);
// 	while (str2[linelength] != '\n' && str2[linelength] != '\0')
// 	{
// 		linelength++;
// 	}
// 	line = (char *)malloc(sizeof(char) * (linelength + 1));
// 	if (!line)
// 		return (NULL);
// 	linelength = 0;
// 	while (str2[linelength] != '\n' && str[linelength] != '\0')
// 	{
// 		line[linelength] = str2[linelength];
// 		linelength++;
// 	}
// 	if (str2[linelength] == '\n')
// 	{
// 		line[linelength] = str2[linelength];
// 		linelength++;
// 	}
// 	line[linelength] = '\0';
// 	return (line);
// 	//free(line);
// }

// char	*ft_check_rest(int fd, char *str)
// {
// 	char	buf[BUFFER_SIZE + 1];
// 	int		bytes_read;
// 	//int i;
// 	int k = 0;
// 	char 	*temp_line;
// 	temp_line = calloc(1, '\0');
// 	// printf("address of variable %p\n", str);
// 	bytes_read = 1;
// 	while (!ft_strchr(str, '\n') && bytes_read != 0)
// 	{	
	
// 		if(*str && k == 0)
// 		{
// 			printf("i'm here\n");
// 			temp_line = ft_strjoin(temp_line,str);
// 		}
// 		printf("this is the rest ->>>><=\n");
// 		k++;
// 		//buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 		bytes_read = read(fd, buf, (BUFFER_SIZE));
// 		if (bytes_read <= 0 && !*temp_line)
// 		{
// 			free (str);
// 			free(temp_line);
// 		 	return (NULL);
// 		 }
	
// 		str = ft_strjoin (str, buf);
// 		buf[bytes_read] = '\0';
// 		// printf("in the buff is liegt = %s\n", buf);
// 		//printf("in the str is liegt = %s\n", str);
// 		if (!str)
// 		{
// 			free (str);
// 			return (NULL);
// 		}
// 		//free (str);
// 	}
// 	// if(*temp_line)
// 		free(temp_line);
// 	return (str);
// 	//free (str);
// }

// char *ft_update_rest(char *str)
// {
// 	char *s;
// 	int i;
// 	int	j;

// 	i = 0;
// 	if (!str)
// 		return (NULL);
// //	if (!str[i])
// //		return (NULL);
// 	// {
// 	// 	free(str);
// 	// 	return (NULL);
// 	// }
// 	// printf("String S(before == str) --->%s<----\n", str);
// 	while (str[i] != '\n' && str[i] != '\0')
// 	{
// 		i++;
// 	}
// 	s = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
// 	// printf("int i is ->%d\n", i);
// 	if (!s)
// 		return (NULL);
// 	//free (s);
// 	i++;
// 	j = 0;
// 	// printf("%c character is\n", str[i]);
// 	// printf("%c character is\n", str[i+1]);
// 	while (str[i] != '\0')
// 	{	
		
// 		s[j] = str[i];
// 		i++;
// 		j++;
// 	}
// 	s[j] = '\0';
// 	free(str);
// 	// printf("String S --->%s<----\n", s);
// 	return (s);
// 	//free(s);
// }
