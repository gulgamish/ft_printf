/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 21:19:33 by aelamran          #+#    #+#             */
/*   Updated: 2018/10/08 22:20:22 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;

	if (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		list = *alst;
		*alst = (*alst)->next;
		free(list);
		*alst = NULL;
	}
}
