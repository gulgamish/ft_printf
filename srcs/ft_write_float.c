/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:15:42 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/17 19:58:00 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_write_float(t_fltnbr *fltn, t_format *fmt)
{
	int		i;
	int		toit;
	int		ret;

	i = 0;
	if (fmt->precision == -1)
		toit = 6;
	else
		toit = fmt->precision;
	ret = toit;
	ft_putstr(fltn->decimal);
	ret += ft_strlen(fltn->decimal);
	if (fmt->precision != 0)
	{
		write(1, ".", 1);
		ret++;
	}
	write(1, fltn->fraction, ((size_t)toit < ft_strlen(fltn->fraction) ?
				toit : ft_strlen(fltn->fraction)));
	ft_write_zeros(toit - ft_strlen(fltn->fraction));
	return (ret);
}
