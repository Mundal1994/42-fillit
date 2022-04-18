/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molesen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:27:48 by molesen           #+#    #+#             */
/*   Updated: 2022/01/12 17:14:22 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*	mallocing and making of the square where everything is initialized to 0	*/

static int	**ft_make_square(int **square, int *len)
{
	int	i;
	int	j;

	if (square)
		ft_double_voiddel((void **)square, *len - 1);
	i = 0;
	square = (int **)malloc(sizeof(int *) * *len);
	if (!square)
		return (NULL);
	while (i < *len)
	{
		square[i] = (int *)malloc(sizeof(int) * *len);
		if (!square)
			return (NULL);
		j = 0;
		while (j < *len)
		{
			square[i][j] = 0;
			++j;
		}
		++i;
	}
	return (square);
}

/*	calculating the initial minimum size of the square	*/

static void	ft_size_calc(int *len, int total)
{
	int	min_size;
	int	size;

	size = *len * *len;
	min_size = 4 * total;
	while (min_size > size)
	{
		*len = *len + 1;
		size = *len * *len;
	}
}

/*	initializing the making of the square	*/

static int	**ft_square_init(int **square, int *len, int total)
{
	ft_size_calc(len, total);
	square = ft_make_square(square, len);
	return (square);
}

/*	resizing and making the square bigger	*/

static int	**ft_resize(t_location *head, t_location *stats,
int *len, int **square)
{
	++*len;
	square = ft_make_square(square, len);
	if (!square)
	{
		stats = head;
		return (NULL);
	}
	stats = head;
	stats->s_y = 0;
	return (square);
}

/*
**	creates square and starts the recursive loop of trying to fit the pieces
*/

int	ft_find_square(int **square, t_location *stats)
{
	static int			a = 2;
	int					*len;
	static t_location	*head = NULL;

	len = &a;
	if (!square)
	{
		head = stats;
		square = ft_square_init(square, len, stats->total);
		if (!square)
			return (-1);
	}
	while (stats->s_y < *len && (stats->s_y - *len <= stats->height))
	{
		ft_square_loop_x(square, stats, len, head);
		++stats->s_y;
		stats->s_x = 0;
		if (stats->tet_placing == 0 && stats->s_y == *len)
		{
			square = ft_resize(head, stats, len, square);
			if (!square)
				return (-1);
		}
	}
	return (0);
}
