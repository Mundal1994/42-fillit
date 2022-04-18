/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:48:04 by jdavis            #+#    #+#             */
/*   Updated: 2022/01/05 11:17:07 by molesen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	the main takes care of calling the functions in the correct order to
**	arrange tetriminos among themselves and determine the smallest square that
**	can fit all of them
*/

int	main(int argc, char **argv)
{
	int			tetri_count;
	char		*board[26];
	int			**square;
	t_location	*stats;
	int			i;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit file.txt\n");
		return (-1);
	}
	i = 0;
	tetri_count = ft_tetri_init(argv, board, &i);
	if (tetri_count == -1)
		return (ft_print_error(board, i, NULL));
	stats = NULL;
	stats = ft_tetri_collect(stats, board, tetri_count, tetri_count);
	if (!stats)
		return (ft_print_error(board, i, stats));
	square = NULL;
	if (ft_find_square(square, stats) == -1)
		return (ft_print_error(board, i, stats));
	return (0);
}
