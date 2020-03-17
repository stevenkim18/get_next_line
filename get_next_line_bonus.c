/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 03:25:34 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/18 01:26:26 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_error(char **buff, int fd)
{
	if (BUFFER_SIZE <= 0)
		return (0);
	if (!(*buff = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (0);
	if (fd <= -1 || fd >= 100)
		return (0);
	return (1);
}
int	getlinestr(char **line, char **data)
{
	if (ft_strchr(*data, '\n'))
	{
		*line = ft_strndup(*data, ft_strchr(*data, '\n') - *data);
		*data = ft_strchr(*data, '\n') + 1;
		return (1);
	}
	else
	{
		*line = ft_strndup(*data, ft_strchr(*data, '\0') - *data);
		*data = NULL;
		return (0);
	}
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*data[4096];
	ssize_t		bytes;
	
	if (!(check_error(&buff, fd)))
		return (-1);
	if (!data[fd])
	{
		data[fd] = "";
		while ((bytes = read(fd, buff, BUFFER_SIZE)) > 0)
		{
			buff[bytes] = '\0';
			data[fd] = ft_strjoin(data[fd], buff);
		}
	}
	free(buff);
	return (getlinestr(&*line, &data[fd]));
}

