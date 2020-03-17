/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 03:25:34 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/17 15:00:24 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_error(char **buff, int fd)
{
	if (!(*buff = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (0);
	if (fd <= -1 || fd >= 6)
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
	static char	*data;
	ssize_t		bytes;
	
	if (!(check_error(&buff, fd)))
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
	free(buff);
	return (getlinestr(&*line, &data));
}

