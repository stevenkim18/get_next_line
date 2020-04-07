/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 15:57:28 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/14 17:04:42 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char		*ft_strchr(char *s, int c)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
	{
		if (s[idx] == (char)c)
			return (s + idx);
		idx++;
	}
	if (!(char)c)
		return (s + idx);
	else
		return (NULL);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	s1_len;
	size_t	s2_len;
	size_t	idx;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(ptr = (char*)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	idx = 0;
	while (s1[idx] && idx < s1_len)
	{
		ptr[idx] = s1[idx];
		idx++;
	}
	while (s2[idx - s1_len] && idx - s1_len < s2_len)
	{
		ptr[idx] = s2[idx - ft_strlen(s1)];
		idx++;
	}
	ptr[idx] = '\0';
	return (ptr);
}

char		*ft_strndup(char const *s, int n)
{
	int		idx;
	char	*ptr;

	idx = 0;
	if (!(ptr = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (idx < n)
	{
		ptr[idx] = s[idx];
		idx++;
	}
	ptr[idx] = '\0';
	return (ptr);
}
