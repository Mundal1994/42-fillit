/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:32:54 by jdavis            #+#    #+#             */
/*   Updated: 2021/11/19 14:30:46 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void	*s1, const void	*s2, size_t	n)
{
	size_t				i;
	const unsigned char	*s1_new;
	const unsigned char	*s2_new;

	i = 0;
	s1_new = s1;
	s2_new = s2;
	if (n == 0)
		return (0);
	if (s1 && s2)
	{
		while (i < n)
		{
			if (s1_new[i] != s2_new[i])
				return (s1_new[i] - s2_new[i]);
			++i;
		}
		if (i == n)
			return (0);
	}
	return (0);
}
