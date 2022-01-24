/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:12:36 by jdavis            #+#    #+#             */
/*   Updated: 2021/11/22 10:51:54 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*dest_new;
	const unsigned char	*src_new;

	i = 0;
	dest_new = dest;
	src_new = src;
	if (dest && src)
	{
		while (i < n)
		{
			dest_new[i] = src_new[i];
			if (src_new[i] == (unsigned char)c)
				return (&dest_new[++i]);
			++i;
		}
		return (NULL);
	}
	return (dest_new);
}
