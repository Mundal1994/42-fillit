/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:49:13 by jdavis            #+#    #+#             */
/*   Updated: 2021/12/01 11:03:46 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	more_than(const char *s)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
				++j;
			++i;
		}
	}
	if (j == i)
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*new;

	i = ft_strlen(s);
	j = 0;
	while (s && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && !more_than(s))
		++j;
	while (s && (s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t'))
		--i;
	i = i - j;
	if (!s)
		return (NULL);
	new = (char *) malloc ((i + 1) * sizeof(char));
	if (s && new)
	{
		ft_memccpy(new, &s[j], '\0', i);
		new[i] = '\0';
	}
	return (new);
}
