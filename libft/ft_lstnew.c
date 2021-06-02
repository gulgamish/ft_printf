/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 21:07:54 by aelamran          #+#    #+#             */
/*   Updated: 2018/10/09 21:42:56 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	list = (t_list *)malloc(sizeof(*list));
	if (list)
	{
		if (content)
		{
			list->content = (void *)content;
			list->content_size = content_size;
		}
		else
		{
			list->content = NULL;
			list->content_size = 0;
		}
		list->next = NULL;
		return (list);
	}
	return (NULL);
}
