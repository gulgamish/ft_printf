/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 14:19:06 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/01 15:29:40 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*ft_newlist(void)
{
	t_print *p;

	p = (t_print *)malloc(sizeof(t_print));
	if (!p)
		return (NULL);
	p->sign = 0;
	p->space = 0;
	p->prefix = NULL;
	p->spaces = 0;
	p->zeros = 0;
	return (p);
}
