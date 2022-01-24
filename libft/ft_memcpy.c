/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:46:45 by jdavis            #+#    #+#             */
/*   Updated: 2021/11/19 12:25:10 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dest, const void	*src, size_t	n)
{
	size_t			i;
	unsigned char	*dest_new;
	unsigned char	*src_new;

	i = 0;
	dest_new = dest;
	if (src)
		src_new = (unsigned char *)src;
	if (dest && src)
	{
		while (i < n)
		{
			dest_new[i] = src_new[i];
			++i;
		}
	}
	return (dest);
}
