/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:17:05 by jdavis            #+#    #+#             */
/*   Updated: 2021/11/11 16:21:59 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void	*dest, const void	*src, size_t	n)
{
	char		*temp;
	char		*dest_new;
	const char	*src_new;
	size_t		i;

	i = 0;
	src_new = src;
	dest_new = dest;
	temp = (char *) malloc(n * sizeof(char));
	if (dest && src && temp)
	{
		while (i < n)
		{
			temp[i] = src_new[i];
			++i;
		}
		i = 0;
		while (i < n)
		{
			dest_new[i] = temp[i];
			++i;
		}
	}
	free(temp);
	return (dest);
}
