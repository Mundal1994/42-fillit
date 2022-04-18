/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molesen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:43:12 by molesen           #+#    #+#             */
/*   Updated: 2022/01/18 12:43:14 by molesen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*	if valid pieces we will add the tetri piece to the board	*/

static int	ft_create_tetri(char **board, char *line, int i)
{
	char	*temp;

	if (!board[i])
	{
		board[i] = ft_strnew(ft_strlen(line) + 1);
		if (!board[i])
			return (-1);
		ft_strcat(ft_strncpy(board[i], line, 4), "\n");
	}
	else
	{
		temp = ft_strnew(ft_strlen(board[i]) + 5);
		if (!temp)
			return (-1);
		ft_strcat(ft_strcat(ft_strcat(temp, board[i]), line), "\n");
		ft_strdel(&board[i]);
		board[i] = temp;
	}
	return (1);
}

/*	checks if line contains only valid characters	*/

static int	ft_not_val_char(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '#' && line[i] != '.')
			return (-1);
		++i;
	}
	return (0);
}

/*
**	checks with the help of two smaller functions if the line
**	contains valid characters and if the length of the line
**	is 4 or not
*/

static int	ft_check_char_and_create(char *line, char **board, int i)
{
	if (ft_not_val_char(line) == -1 || ft_strlen(line) != 4)
		return (-1);
	if (ft_create_tetri(board, line, i) == -1)
		return (-1);
	return (0);
}

/*	keeps track of and returns the amount of blocks in the read line	*/

static int	ft_block_count(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '#')
			++j;
		++i;
	}
	return (j);
}

/*	loops through to check if piece is valid or not	*/

int	ft_tetri_check(char *line, int fd, char **board, int i)
{
	int	ret;
	int	count_block;
	int	gnl_count;

	ret = 1;
	count_block = 0;
	gnl_count = 0;
	while (ret)
	{
		count_block += ft_block_count(line);
		if (ft_strcmp(line, "\0") == 0)
			break ;
		if (ft_check_char_and_create(line, board, i) == -1)
		{
			return (ft_free_line(line));
		}
		++gnl_count;
		ft_free_line(line);
		ret = get_next_line(fd, &line);
	}
	ft_free_line(line);
	if (count_block != 4 || gnl_count != 4)
		return (-1);
	return (ret);
}
