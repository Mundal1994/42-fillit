/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:10:37 by jdavis            #+#    #+#             */
/*   Updated: 2021/11/18 16:48:42 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t	n)
{
	size_t	d_size;
	size_t	s_size;
	int		i;

	d_size = ft_strlen(dest);
	s_size = ft_strlen(src);
	i = 0;
	if (n < d_size)
		return (n + s_size);
	if (dest && src)
	{
		while ((src[i] != '\0') && ((d_size + i) < (n - 1)))
		{
			dest[d_size + i] = src[i];
			++i;
		}
		dest[d_size + i] = '\0';
	}
	return (d_size + s_size);
}
