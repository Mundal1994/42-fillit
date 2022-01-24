/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:36:05 by jdavis            #+#    #+#             */
/*   Updated: 2021/11/13 15:41:15 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t	size)
{
	void	*fresh;

	if (size == 0)
		return (NULL);
	fresh = (void *) malloc(size);
	if (fresh)
	{
		ft_bzero(fresh, size);
		return (fresh);
	}
	return (NULL);
}
