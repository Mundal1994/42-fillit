/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:01:41 by jdavis            #+#    #+#             */
/*   Updated: 2021/11/30 11:08:46 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (*alst)
	{
		while (*alst)
		{
			temp = *alst;
			*alst = (*alst)->next;
			del(temp->content, temp->content_size);
			ft_memdel((void **)&temp);
		}
	}
}
