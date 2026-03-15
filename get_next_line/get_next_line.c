/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@stmpdent.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:25:03 by anrogard          #+#    #+#             */
/*   Updated: 2025/11/19 23:12:22 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

void	help_split_str(int len_line, char *temp, int place_of_n, char **result)
{
	int	i;

	i = 0;
	while (i < len_line || (i == len_line && temp[i] == '\n'))
	{
		result[0][i] = temp[i];
		i++;
	}
	result[0][i] = '\0';
	if (result[1])
	{
		i = 0;
		while (i < ft_strlen(temp) - len_line - 1)
		{
			result[1][i] = temp[place_of_n + 1 + i];
			i++;
		}
		result[1][i] = '\0';
	}
}

char	**split_str(char *temp)
{
	int		len_line;
	int		place_of_n;
	char	**result;

	len_line = 0;
	place_of_n = 0;
	while (temp[len_line] && temp[len_line] != '\n')
		len_line++;
	result = malloc(sizeof(char *) * 2);
	if (!result)
		return (NULL);
	if (temp[len_line] == '\n')
	{
		place_of_n = len_line;
		result[0] = malloc(len_line + 2);
		if (!result[0])
			return (NULL);
		result[1] = malloc(ft_strlen(temp) - len_line);
		if (!result[1])
			return (NULL);
	}
	else
	{
		result[0] = malloc(len_line + 1);
		if (!result[0])
			return (NULL);
		result[1] = NULL;
	}
	help_split_str(len_line, temp, place_of_n, result);
	return (result);
}

char	*help_gnl(char *read_buf, int fd, char **static_temp, char *str_static)
{
	int	bytes_read;
	int	end;

	static_temp[1] = ft_strjoin(str_static, read_buf);
	end = 0;
	while (find_new_line(read_buf) == 0 && end != 1)
	{
		static_temp[0] = static_temp[1];
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read == 0)
		{
			end = 1;
		}
		else if (bytes_read == -1)
		{
			free(static_temp[1]);
			return (NULL);
		}
		read_buf[bytes_read] = '\0';
		static_temp[1] = ft_strjoin(static_temp[1], read_buf);
		free(static_temp[0]);
	}
	return (static_temp[1]);
}

char	*help2_gnl(char *read_buf, char **result, char **static_temp,
		char **str_static)
{
	char	*line_return;

	free(read_buf);
	free(static_temp[1]);
	line_return = result[0];
	if (!line_return || (line_return[0] == '\0' && (result[1] == NULL
				|| result[1][0] == '\0')))
	{
		free(result[0]);
		free(result[1]);
		free(result);
		free(*str_static);
		*str_static = NULL;
		return (NULL);
	}
	free(*str_static);
	*str_static = result[1];
	if (line_return[0] == '\0' && (result[1] == NULL || result[1][0] == '\0'))
	{
		free(str_static);
		*str_static = NULL;
	}
	free(result);
	return (line_return);
}

char	*get_next_line(int fd)
{
	char		*read_buf;
	char		**result;
	char		*static_temp[2];
	static char	*str_static;	
	char		*line_return;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(str_static);
		str_static = NULL;
		return (NULL);
	}
	static_temp[0] = NULL;
	read_buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	static_temp[1] = help_gnl(read_buf, fd, static_temp, str_static);
	if (static_temp[1] == NULL)
	{
		free(read_buf);
		free(str_static);
		str_static = NULL;
		return (NULL);
	}
	if (static_temp[1][1] == '\0')
		return (NULL);
	result = split_str(static_temp[1]);
	if (!result)
		return (NULL);
	line_return = help2_gnl(read_buf, result, static_temp, &str_static);
	return (line_return);
}
