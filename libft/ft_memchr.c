/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:24:11 by jdavis            #+#    #+#             */
/*   Updated: 2021/11/15 16:54:15 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	cc;
	unsigned char	*s_new;

	cc = (unsigned char)c;
	s_new = (unsigned char *)s;
	i = 0;
	if (s)
	{
		while (i < n)
		{
			if (s_new[i] == cc)
				return (&((void *)s)[i]);
			++i;
		}
	}
	return (NULL);
}
