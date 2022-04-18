/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molesen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:17:38 by molesen           #+#    #+#             */
/*   Updated: 2022/01/05 17:34:04 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*	removes piece from square to try and fit the piece somewhere else	*/

static void	ft_clear_square(int **square, t_location *stats)
{
	int	y;
	int	x;

	y = stats->s_y;
	x = stats->s_x;
	square[y][x] = 0;
	x = x + stats->dif->two_x;
	y = y + stats->dif->two_y;
	square[y][x] = 0;
	x = x + stats->dif->three_x;
	y = y + stats->dif->three_y;
	square[y][x] = 0;
	x = x + stats->dif->four_x;
	y = y + stats->dif->four_y;
	square[y][x] = 0;
}

/*	prints the square to the terminal	*/

static void	ft_print(int **square, int *len)
{
	int	i;
	int	j;

	i = 0;
	while (i < *len)
	{
		j = 0;
		while (j < *len)
		{
			if (square[i][j] == 0)
				ft_putchar('.');
			else
				ft_putchar(64 + square[i][j]);
			++j;
		}
		ft_putchar('\n');
		++i;
	}
}

/*	places the pieces in the square	*/

static void	ft_place(int **square, t_location *stats)
{
	int		y;
	int		x;

	y = stats->s_y;
	x = stats->s_x;
	square[y][x] = stats->tet_placing + 1;
	x = x + stats->dif->two_x;
	y = y + stats->dif->two_y;
	square[y][x] = stats->tet_placing + 1;
	x = x + stats->dif->three_x;
	y = y + stats->dif->three_y;
	square[y][x] = stats->tet_placing + 1;
	x = x + stats->dif->four_x;
	y = y + stats->dif->four_y;
	square[y][x] = stats->tet_placing + 1;
}

/*	checks if all the pieces fit in the square	*/

static int	ft_does_it_fit(int **square, t_location *stats, int *len)
{
	size_t	fit;
	int		y;
	int		x;

	fit = 0;
	x = stats->s_x + stats->dif->two_x;
	y = stats->s_y + stats->dif->two_y;
	if (x < *len && y < *len && square[y][x] == 0)
		fit++;
	else
		return (fit);
	x = x + stats->dif->three_x;
	y = y + stats->dif->three_y;
	if (x < *len && y < *len && square[y][x] == 0)
		fit++;
	else
		return (fit);
	x = x + stats->dif->four_x;
	y = y + stats->dif->four_y;
	if (x < *len && y < *len && square[y][x] == 0)
		fit++;
	if (fit == 3)
		ft_place(square, stats);
	return (fit);
}

/*
**	loops through the columns to check if the beginning
**	part of the piece fit if it does it calls the function
**	ft_does_it_fit to checks if the whole piece fits
**	if it does it will be put there and next piece will
**	be put. If out of pieces the square will be printed
*/

void	ft_square_loop_x(int **square, t_location *stats,
int *len, t_location *head)
{
	while (stats->s_x < *len)
	{
		if (stats->s_x < stats->offset)
			stats->s_x = stats->offset;
		if (square[stats->s_y][stats->s_x] == 0)
		{
			if (ft_does_it_fit(square, stats, len) == 3)
			{
				if (stats->tet_placing == stats->total - 1)
				{
					ft_print(square, len);
					ft_double_voiddel((void **)square, *len);
					ft_statsdel_stats(&head, &ft_statsdel_content, NULL);
					exit(0);
				}
				stats->next->s_x = 0;
				stats->next->s_y = 0;
				ft_find_square(square, stats->next);
				ft_clear_square(square, stats);
			}
		}
		++stats->s_x;
	}
}
