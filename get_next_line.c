/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:25:43 by tfedoren          #+#    #+#             */
/*   Updated: 2022/04/10 20:00:14 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char *get_next_line(int fd)
{
    static char buf[1000];
    size_t count;
    size_t bytes_read;
	
    count = 0;
	count = sizeof(buf);
    bytes_read = read(fd, buf, count);
    printf("%s", buf);
}

int main()
{
	int fd;

    fd = open("test1.txt", O_RDONLY);
	get_next_line(fd);
}
