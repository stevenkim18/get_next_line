/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 03:25:34 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/12 02:07:17 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char	*buff;
	ssize_t	bytes;

	if (!(buff = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	bytes = read(fd, buff, BUFFER_SIZE);
	printf("bytes = %zu\n", bytes);
	*line = buff;
	free(buff);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	fd;
	char	*line;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
}
