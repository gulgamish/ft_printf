/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dorounding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:14:08 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/17 19:04:49 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dorounding(t_fltnbr *nb, t_format *fmt)
{
	int		i;
	int		holder;

	if (fmt->precision >= 1 || fmt->precision == -1)
	{
		i = (fmt->precision >= 1 ? fmt->precision - 1 : 5);
		if (nb->fraction[i + 1] >= '5')
		{
			i = ft_roundit(&nb->fraction, i);
			if (i == -1)
				nb->decimal = ft_add_toit(nb->decimal);
		}
	}
	else if (fmt->precision == 0)
	{
		holder = ft_getlast(nb->decimal);
		if (holder % 2 == 1 && nb->fraction[0] == '5')
			nb->decimal = ft_add_toit(nb->decimal);
		else if (nb->fraction[0] > '5' ||
				(nb->fraction[0] == '5' && ft_isgreater(nb->fraction)))
			nb->decimal = ft_add_toit(nb->decimal);
	}
}
