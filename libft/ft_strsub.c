/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:01:30 by jdavis            #+#    #+#             */
/*   Updated: 2021/12/01 10:35:17 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		elem;
	size_t	i;
	char	*array;
	int		stalen;

	i = 0;
	elem = ft_strlen(s);
	stalen = start + len;
	if ((stalen > elem) || !s)
		return (NULL);
	array = (char *) malloc ((len + 1) * sizeof(char));
	if (array)
	{
		while (i < len)
		{
			array[i] = s[start + i];
			++i;
		}
		array[i] = '\0';
	}
	return (array);
}
