/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:53:46 by jdavis            #+#    #+#             */
/*   Updated: 2022/01/19 11:53:49 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_free_line(char *line)
{
	if (line)
		free(line);
	line = NULL;
	return (-1);
}

void	ft_statsdel_content(t_location *stats)
{
	free(stats->piece);
	stats->piece = NULL;
	free(stats->dif);
	stats->dif = NULL;
}

t_location	*ft_statsdel_stats(t_location **stats, void (*del)(t_location *),
t_location *new)
{
	t_location	*temp;
	size_t		i;

	if (new)
	{
		if (new->dif)
			free(new->dif);
		if (new->piece)
			free(new->piece);
		free(new);
	}
	i = (*stats)->total;
	if (*stats)
	{
		while (i--)
		{
			temp = *stats;
			del(temp);
			ft_memdel((void **)&temp);
			*stats = (*stats)->next;
		}
	}
	return (NULL);
}
