/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:28:59 by jdavis            #+#    #+#             */
/*   Updated: 2021/11/22 12:56:37 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const	*content, size_t	content_size)
{
	t_list	*fresh;

	fresh = (t_list *) malloc(sizeof(t_list));
	if (fresh && content)
	{
		fresh->content = (void *)malloc(content_size);
		if (!fresh->content)
		{
			free(fresh);
			return (NULL);
		}
		ft_memcpy(fresh->content, content, content_size);
		fresh->content_size = content_size;
		fresh->next = NULL;
	}
	if (!content && fresh)
	{
		fresh->content = NULL;
		fresh->content_size = 0;
		fresh->next = NULL;
	}
	return (fresh);
}
