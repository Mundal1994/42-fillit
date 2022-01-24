/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:19:56 by jdavis            #+#    #+#             */
/*   Updated: 2021/11/18 14:48:19 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char	*haystack, const char	*needle)
{
	int		i;
	int		j;
	char	*haystack_new;

	i = 0;
	if (!needle || !haystack)
		return (NULL);
	haystack_new = (char *)haystack;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (haystack && needle)
	{
		while (haystack[i] != '\0')
		{
			j = 0;
			while (haystack[i + j] == needle[j])
			{
				if (needle[j + 1] == '\0')
					return (&haystack_new[i]);
				j++;
			}
			++i;
		}
	}
	return (NULL);
}
