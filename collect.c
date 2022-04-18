/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molesen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:59:57 by molesen           #+#    #+#             */
/*   Updated: 2022/01/18 16:59:58 by molesen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*	add new to alst	*/

static void	ft_lstad_location(t_location	**alst, t_location	*new)
{
	t_location	*temp;

	temp = NULL;
	if (alst && new)
	{
		temp = *alst;
		*alst = new;
		(*alst)->next = temp;
	}
}

/*	calculating the offset and height of the pieces	*/

static void	ft_offset_calc(t_location *new, char **board, int i)
{
	int	j;
	int	temp;
	int	begin;
	int	l_border;
	int	last;

	l_border = 4;
	temp = 4;
	j = 0;
	last = 0;
	begin = ft_strlen_stop(board[i], '#');
	while (board[i][j] != '\0')
	{
		if (board[i][j] == '#' && ((board[i][j - 1] == '.' || \
		board[i][j - 1] == '\n') || j == 0))
			temp = j % 5;
		if (temp < l_border)
			l_border = temp;
		if (board[i][j] == '#')
			last = j;
		++j;
	}
	new->offset = (begin % 5) - l_border;
	new->height = (((last / 5) - (begin / 5)) + 1);
}

/*	storing pieces position and difference from previous piece in struct	*/

static int	ft_dif_calc(t_location *new, int j, int count)
{
	if (count == 1)
	{
		new->piece->two_x = j % 5;
		new->dif->two_x = new->piece->two_x - new->piece->one_x;
		new->piece->two_y = j / 5;
		new->dif->two_y = new->piece->two_y - new->piece->one_y;
	}
	else if (count == 2)
	{
		new->piece->three_x = j % 5;
		new->dif->three_x = new->piece->three_x - new->piece->two_x;
		new->piece->three_y = j / 5;
		new->dif->three_y = new->piece->three_y - new->piece->two_y;
	}
	else if (count == 3)
	{
		new->piece->four_x = j % 5;
		new->dif->four_x = new->piece->four_x - new->piece->three_x;
		new->piece->four_y = j / 5;
		new->dif->four_y = new->piece->four_y - new->piece->three_y;
	}
	return (1);
}

/*
**	storing pieces position in struct and uses the ft_dif_calc to
**	calculate the difference of the pieces position from previous piece
*/

static void	ft_pieces(t_location *new, char **board, int i)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (board[i][j] != '\0' && count < 4)
	{
		if (board[i][j] == '#' && count == 0)
		{
			count++;
			new->piece->one_x = j % 5;
			new->piece->one_y = j / 5;
		}
		else if (board[i][j] == '#' && count == 1)
			count += ft_dif_calc(new, j, count);
		else if (board[i][j] == '#' && count == 2)
			count += ft_dif_calc(new, j, count);
		else if (board[i][j] == '#' && count == 3)
			count += ft_dif_calc(new, j, count);
		j++;
	}
}

/*
**	collecting the nescessary information needed from
**	the tetri pieces in a struct
*/

t_location	*ft_tetri_collect(t_location *stats, char **board,
	int total_tetri, int i)
{
	t_location	*new;

	while (--i >= 0)
	{
		new = (t_location *) malloc(sizeof(t_location));
		if (!new)
			return (ft_statsdel_stats(&stats, &ft_statsdel_content, NULL));
		new->piece = (t_piece *) malloc(sizeof(t_piece));
		new->dif = (t_dif *) malloc(sizeof(t_dif));
		if (!new->dif || !new->piece)
			return (ft_statsdel_stats(&stats, &ft_statsdel_content, new));
		new->s_x = 0;
		new->s_y = 0;
		new->total = total_tetri;
		new->tet_placing = i;
		ft_offset_calc(new, board, i);
		ft_pieces(new, board, i);
		if (i == total_tetri - 1)
			stats = new;
		else
			ft_lstad_location(&stats, new);
	}
	ft_double_arrdel(board, total_tetri);
	return (stats);
}
