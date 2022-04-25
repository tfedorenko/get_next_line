/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:50:24 by tfedoren          #+#    #+#             */
/*   Updated: 2022/04/25 19:32:56 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char *get_next_line(int fd);
void	*ft_memmove(void *dst, void *src, size_t n);
void	*ft_memset(void *dst, int c, size_t len);
size_t ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

char	*ft_check_rest(int fd, char *rest);
char	*ft_create_line(char *rest);
char    *ft_update_rest(char *rest);


#endif 