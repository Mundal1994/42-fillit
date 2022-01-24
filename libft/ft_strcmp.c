/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:45:00 by jdavis            #+#    #+#             */
/*   Updated: 2021/11/20 15:49:03 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*s1_new;
	unsigned char	*s2_new;

	s1_new = (unsigned char *)s1;
	s2_new = (unsigned char *)s2;
	i = 0;
	if (s1 && s2)
	{
		while (s1[i] != '\0' && s2[i] != '\0')
		{
			if (s1[i] != s2[i])
				return (s1_new[i] - s2_new[i]);
			++i;
		}
		return (s1_new[i] - s2_new[i]);
	}
	return (0);
}
