/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:42:45 by jdavis            #+#    #+#             */
/*   Updated: 2022/01/18 13:09:02 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_line(char **stat, int fd, char **line)
{
	char	*temp;
	int		i;

	i = 0;
	if (ft_strchr(stat[fd], '\n') != NULL)
	{
		while (stat[fd][i] != '\n')
			++i;
		*line = ft_strnew(i);
		if (!*line)
		{
			ft_strdel(&stat[fd]);
			return (-1);
		}
		ft_strncpy(*line, stat[fd], i);
		temp = stat[fd];
		stat[fd] = ft_strdup(&temp[i + 1]);
		ft_strdel(&temp);
		if (!stat[fd])
			return (-1);
		return (1);
	}
	return (0);
}

static int	is_end(int ret, char *stat, char **line)
{
	if (ret == 0 && ft_strlen(stat) > 0)
	{
		*line = ft_strdup(stat);
		if (!*line)
		{
			ft_strdel(&stat);
			return (-1);
		}
		ft_bzero(stat, ft_strlen(stat));
		return (1);
	}
	return (0);
}

static int	create_join(int ret, char **stat, char *buff, int fd)
{
	char	*temp;

	if (ret < 0)
		return (-1);
	buff[ret] = '\0';
	if (!stat[fd])
	{
		stat[fd] = ft_strdup(buff);
		if (!stat[fd])
			return (-1);
	}
	else
	{
		temp = ft_strjoin(stat[fd], buff);
		if (!temp)
		{
			ft_strdel(&stat[fd]);
			return (-1);
		}
		ft_strdel(&stat[fd]);
		stat[fd] = temp;
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char	*stat[4096];
	char		buff[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || fd >= 4096 || line == NULL)
		return (-1);
	ret = 1;
	*line = NULL;
	if (is_line(stat, fd, line) == -1)
		return (-1);
	else if (*line)
		return (1);
	while (ret != 0)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (create_join(ret, stat, buff, fd) == -1)
			return (-1);
		if (is_line(stat, fd, line) == -1)
			return (-1);
		else if (*line)
			return (1);
	}
	return (is_end(ret, stat[fd], line));
}
