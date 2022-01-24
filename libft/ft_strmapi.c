/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:15:09 by jdavis            #+#    #+#             */
/*   Updated: 2021/11/16 16:51:21 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			fresh[i] = f(i, s[i]);
			++i;
		}
		fresh[i] = '\0';
		return (fresh);
	}
	return (NULL);
}
