/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:03:13 by jdavis            #+#    #+#             */
/*   Updated: 2021/11/24 14:21:33 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char	*s1, const char	*s2, size_t	n)
{
	size_t	size;
	size_t	i;

	size = ft_strlen(s1);
	i = 0;
	if (s1 && s2)
	{
		while (s2[i] != '\0' && i < n)
		{
			s1[size + i] = s2[i];
			++i;
		}
		s1[size + i] = '\0';
	}
	return (s1);
}
