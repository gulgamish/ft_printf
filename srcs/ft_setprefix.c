/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setprefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 20:55:50 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/18 19:04:25 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_setprefix(t_format *fmt, t_number *nbr)
{
	char *prefix;

	prefix = NULL;
	if (nbr->nbr != 0 && fmt->conversion == 'o')
	{
		nbr->len++;
		prefix = ft_strdup("0");
	}
	else if (nbr->nbr != 0 &&
			(fmt->conversion == 'x' || fmt->conversion == 'X'))
	{
		fmt->field_width -= 2;
		if (fmt->conversion == 'x')
			prefix = ft_strdup("0x");
		else
			prefix = ft_strdup("0X");
	}
	else if (fmt->conversion == 'p')
	{
		fmt->field_width -= 2;
		prefix = ft_strdup("0x");
	}
	return (prefix);
}
