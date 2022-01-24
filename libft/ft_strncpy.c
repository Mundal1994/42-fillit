/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:50:35 by jdavis            #+#    #+#             */
/*   Updated: 2021/11/24 14:10:14 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char	*dest, const char	*src, size_t	len)
{
	size_t	i;

	i = 0;
	if (dest && src && len > 0)
	{
		while (src[i] != '\0' && i < len)
		{
			dest[i] = src[i];
			++i;
		}
		while (i < len)
		{
			dest[i] = '\0';
			++i;
		}
	}
	return (dest);
}
