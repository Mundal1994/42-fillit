/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:36:23 by jdavis            #+#    #+#             */
/*   Updated: 2021/11/25 11:33:31 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_by_c(char const *s, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	flag = 1;
	count = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			if (s[i] != c && flag == 1)
			{
				++count;
				flag = 0;
			}
			if (s[i] == c)
				flag = 1;
			++i;
		}
		return (count);
	}
	return (count);
}

static int	w_len(char const *s, char c)
{
	int	i;

	i = 0;
	while ((s[i] != c) && s[i] != '\0')
		++i;
	return (i);
}

static void	ft_strcpy_c(char *array, char const *s, char c)
{
	int	i;

	i = 0;
	if (array && s)
	{
		while (s[i] != c && s[i] != '\0')
		{
			array[i] = s[i];
			++i;
		}
		array[i] = '\0';
	}
}

static void	string_allo(char const *s, char c, char **array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((s[i] != '\0') && (j < count_by_c(s, c)))
	{
		while ((s[i] == c))
			++i;
		array[j] = (char *) malloc((w_len(&s[i], c) + 1) * sizeof(char));
		if (!array[j])
		{
			i = 0;
			while (array[i] != NULL)
			{
				free(array[i]);
				++i;
			}
			free(array);
			break ;
		}
		ft_strcpy_c(array[j++], &s[i], c);
		i = i + w_len(&s[i], c);
	}
	array[j] = NULL;
}

char	**ft_strsplit(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = (char **) malloc ((count_by_c(s, c) + 1) * sizeof(char *));
	if (array && s)
		string_allo(s, c, array);
	return (array);
}
