/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 03:25:34 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/16 14:07:40 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*data;
	ssize_t		bytes;

	if (!(buff = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!data)
	{
		data = "";
		while ((bytes = read(fd, buff, BUFFER_SIZE)) > 0)
		{
			buff[bytes] = '\0';
			data = ft_strjoin(data, buff);
		}
	}
	if (ft_strchr(data, '\n'))
		*line = ft_strndup(data, ft_strchr(data, '\n') - data);
	else
		return (0);
	data = ft_strchr(data, '\n') + 1;
	free(buff);
	return (1);
}

//int	main(void)
//{
//	int	fd;
//	char	*line;

//	fd = open("text.txt", O_RDONLY);
//	while (get_next_line(fd, &line))
//		printf("line = %s\n", line);
//}
