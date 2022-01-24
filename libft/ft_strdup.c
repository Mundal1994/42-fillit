/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:02:19 by jdavis            #+#    #+#             */
/*   Updated: 2021/11/29 10:29:16 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*ptr;

	if (!src)
		return (NULL);
	ptr = (char *) malloc((ft_strlen(src) + 1) * sizeof(char));
	if (ptr && src)
	{
		ft_strcpy(ptr, src);
		return (ptr);
	}
	return (ptr);
}
