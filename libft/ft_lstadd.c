/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:25:29 by jdavis            #+#    #+#             */
/*   Updated: 2021/11/22 16:27:41 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list	**alst, t_list	*new)
{
	t_list	*temp;

	temp = NULL;
	if (alst && new)
	{
		temp = *alst;
		*alst = new;
		(*alst)->next = temp;
	}
}
