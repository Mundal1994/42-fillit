/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:40:25 by jdavis            #+#    #+#             */
/*   Updated: 2021/11/23 12:09:08 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_count(long int n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		++count;
		n = n * -1;
	}
	while (n != 0)
	{
		n = n / 10;
		++count;
	}
	return (count);
}

static char	*ft_array_assign(char *array, int count, int sign, long int n)
{	
	if (array)
	{
		if (n == 0)
			array[0] = '0';
		array[count] = '\0';
		while (n != 0)
		{
			if (sign == -1)
				array[0] = '-';
			array[--count] = (n % 10) + 48;
			n = n / 10;
		}
	}
	return (array);
}

char	*ft_itoa(int n)
{
	int			count;
	int			sign;
	char		*array;
	long int	ln;

	ln = n;
	count = ft_itoa_count(ln);
	sign = 1;
	if (ln <= 0)
	{
		sign = -1;
		ln = ln * -1;
	}
	array = (char *) malloc((count + 1) * sizeof(char));
	if (array)
	{
		array = ft_array_assign(array, count, sign, ln);
		return (array);
	}	
	return (NULL);
}
