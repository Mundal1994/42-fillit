/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:19:28 by jdavis            #+#    #+#             */
/*   Updated: 2021/11/16 16:51:05 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*fresh;

	i = ft_strlen(s);
	fresh = (char *) malloc ((i + 1) * sizeof(char));
	if (s && fresh)
	{
		i = 0;
		while (s[i] != '\0')
		{
			fresh[i] = f(s[i]);
			++i;
		}
		fresh[i] = '\0';
		return (fresh);
	}
	return (NULL);
}
