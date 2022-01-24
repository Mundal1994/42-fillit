/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:11:54 by jdavis            #+#    #+#             */
/*   Updated: 2021/11/12 14:20:47 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	l;

	l = n;
	if (l < 0)
	{
		ft_putchar_fd('-', fd);
		l = l * -1;
	}
	if (l > 9)
	{
		ft_putnbr_fd((l / 10), fd);
		ft_putchar_fd(((l % 10) + 48), fd);
	}
	else
		ft_putchar_fd((l + 48), fd);
}
