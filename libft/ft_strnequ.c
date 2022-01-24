/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:36:08 by jdavis            #+#    #+#             */
/*   Updated: 2021/11/22 11:02:10 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const	*s1, char const	*s2, size_t	n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (s1 && s2)
	{
		while (s1[i] != '\0' && s2[i] != '\0' && i < n)
		{
			if (s1[i] != s2[i])
				return (0);
			++i;
		}
		if (i == n)
			return (1);
		if (s1[i] != s2[i])
			return (0);
		else
			return (1);
	}
	return (0);
}
