/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molesen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:55:16 by molesen           #+#    #+#             */
/*   Updated: 2022/01/04 13:51:11 by molesen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list **alst)
{
	t_list	*current;

	if (!alst)
		return ;
	current = *alst;
	while (current)
	{
		ft_putstr(current->content);
		current = current->next;
	}
}
