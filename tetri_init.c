/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:48:04 by jdavis            #+#    #+#             */
/*   Updated: 2022/01/05 12:53:41 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*	checks if the # is connected or else it is an invalid piece	*/

static int	ft_block_touch(char *board)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		while (board[i] == '.' || board[i] == '\n')
			++i;
		if (i + 1 <= 19 && board[i + 1] == '#')
			++count;
		if (i + 5 <= 19 && board[i + 5] == '#')
			++count;
		if (i - 1 >= 0 && board[i - 1] == '#')
			++count;
		if (i - 5 >= 0 && board[i - 5] == '#')
			++count;
		++i;
	}
	if (count < 6)
		return (-1);
	return (1);
}

/*	loops through to collect tetri in a string	*/

int	ft_tetri_init(char **argv, char **board, int *i)
{
	int		ret;
	char	*line;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	ret = get_next_line(fd, &line);
	while (*i <= 26 && ret)
	{
		if (*i != 0)
			ret = get_next_line(fd, &line);
		if (*i == 26 || !line)
		{
			if (line)
				free(line);
			return (-1);
		}
		board[*i] = NULL;
		ret = ft_tetri_check(line, fd, board, *i);
		++*i;
		if (ret == -1)
			return (-1);
		if (ft_block_touch(board[*i - 1]) == -1)
			return (-1);
	}
	return (*i);
}
