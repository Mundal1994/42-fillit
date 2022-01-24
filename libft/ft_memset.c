/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:21:15 by jdavis            #+#    #+#             */
/*   Updated: 2021/11/19 11:44:07 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_new;
	unsigned char	c_new;

	i = 0;
	c_new = c;
	s_new = s;
	if (s)
	{
		while (i < n)
		{
			s_new[i] = c_new;
			++i;
		}
	}
	return (s);
}
