/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:25:07 by anrogard          #+#    #+#             */
/*   Updated: 2025/12/02 08:48:26 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*take_just_line(char *temp, int len)
{
	char	*line;
	int		i;

	i = 0;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = temp[i];
		i++;
	}
	return (line);
}

int	find_new_line(char *temp)
{
	int	i;

	i = 0;
	if (!temp)
		return (0);
	while (temp[i])
	{
		if (temp[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	r;
	char	*s;
	size_t	i;

	i = 0;
	r = nmemb * size;
	if (nmemb != 0 && r / nmemb != size)
		return (NULL);
	if (r == 0)
	{
		s = malloc(1);
		if (!s)
			return (NULL);
		return (s);
	}
	s = malloc(r);
	if (!s)
		return (NULL);
	while (i < size)
	{
		s[i] = 0;
		i++;
	}
	return (s);
}

char	*ft_strjoin(char *s1, char *temp)
{
	char	*dup;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(temp);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (s1 && s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	while (temp && temp[j])
	{
		dup[i + j] = temp[j];
		j++;
	}
	dup[i + j] = '\0';
	return (dup);
}
