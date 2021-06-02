/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 22:30:04 by aelamran          #+#    #+#             */
/*   Updated: 2018/10/10 11:28:16 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *begin;
	t_list *tmp;

	tmp = lst;
	list = f(tmp);
	if (list == NULL)
		return (NULL);
	begin = list;
	tmp = tmp->next;
	while (tmp)
	{
		if ((list->next = f(tmp)) == NULL)
			return (NULL);
		tmp = tmp->next;
		list = list->next;
	}
	return (begin);
}
