/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:12:14 by jdavis            #+#    #+#             */
/*   Updated: 2021/12/01 10:36:31 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clear_content(void *content, size_t content_size)
{
	if (content)
	{
		free(content);
		content_size = 0;
	}
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*head;

	head = NULL;
	if (lst)
	{
		new = f(lst);
		head = new;
		while (lst->next)
		{
			new->next = f(lst->next);
			if (!new->next)
			{
				ft_lstdel(&head, &clear_content);
				return (head);
			}
			new = new->next;
			lst = lst->next;
		}
	}
	return (head);
}
