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

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;
	
	i = 0;
	if (s)
	{
		
		while (s[i])
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

	i = 0;
	j = 0;
	while(s2[j] && s2[j] != '\n')
	{
		j++;
	}
	if(s2[j] && s2[j] == '\n')
	{
		j++;
	}
	str = (char *)malloc(sizeof(char) *(ft_strlen(s1) + j + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\n')
	{
		str[i++] = s2[j++];
	}
	if (s2[j] && s2[j] == '\n')
	{
		str[i++] = '\n';
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
	
	if (!dst || !src)
		return (NULL);

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
