/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_formatldouble.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 20:58:46 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/15 20:52:13 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_check(long double nbr)
{
	union u_type	udouble;
	int				i;
	int				counter;
	int				ret;

	udouble.nbr = nbr;
	counter = 0;
	ret = 0;
	i = 14;
	while (i >= 0 && ((udouble.rd.exp >> i) & 1))
		i--;
	if (i == -1)
	{
		ret = 3;
		if (udouble.rd.sign)
		{
			write(1, "-", 1);
			ret++;
		}
		if (!udouble.rd.mantissa)
			write(1, "inf", 3);
		else
			write(1, "nan", 3);
	}
	return (ret);
}

int				ft_write_formatldouble(t_format *fmt, long double nbr)
{
	int			ret;
	t_fltnbr	*nb;
	t_float		*flt;
	t_print		*pnt;

	if ((ret = ft_check(nbr)))
		return (ret);
	flt = ft_setldouble(nbr);
	nb = ft_getdouble(flt);
	pnt = ft_printit(fmt, nb);
	ft_dorounding(nb, fmt);
	ret = 0;
	if (pnt->spaces > 0 && !ft_strchr(fmt->flag, '-'))
		ft_write_spaces(pnt->spaces);
	if (pnt->sign)
	{
		write(1, &pnt->sign, 1);
		ret++;
	}
	if (pnt->zeros > 0)
		ft_write_zeros(pnt->zeros);
	ret += ft_write_float(nb, fmt);
	if (pnt->spaces > 0 && ft_strchr(fmt->flag, '-'))
		ft_write_spaces(pnt->spaces);
	return (ret + pnt->spaces + pnt->zeros);
}
