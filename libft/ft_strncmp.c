/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:35:00 by jdavis            #+#    #+#             */
/*   Updated: 2021/11/19 17:19:12 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char	*s1, const char	*s2, size_t	n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	if (s1 && s2)
	{
		while (s1[i] != '\0' && s2[i] != '\0' && i < n)
		{
			if (s1[i] != s2[i])
				return ((unsigned char)s1[i] - s2[i]);
			i++;
		}
		if (i == n)
			return (0);
		return ((unsigned char)s1[i] - s2[i]);
	}
	return (0);
}
