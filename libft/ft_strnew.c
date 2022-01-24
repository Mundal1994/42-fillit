/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:49:48 by jdavis            #+#    #+#             */
/*   Updated: 2021/12/01 10:37:54 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t	size)
{
	char	*fresh;

	fresh = (char *) malloc((size + 1) * sizeof(char));
	if (fresh)
		ft_bzero(fresh, (size + 1));
	return (fresh);
}
