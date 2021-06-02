/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_formatdouble.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:46:18 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/15 20:51:42 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check(double nbr, t_format *fmt)
{
	union u_typed	udouble;
	char			str[4];
	int				i;
	int				counter;

	udouble.nbr = nbr;
	counter = 0;
	i = 10;
	while (i >= 0 && ((udouble.rd_double.exp >> i) & 1))
		i--;
	if (i == -1)
	{
		if (!udouble.rd_double.mantissa)
			ft_strcpy(str, "inf");
		else
			ft_strcpy(str, "nan");
		return (ft_write_formatinf(fmt, str, udouble.rd_double.sign));
	}
	return (0);
}

int		ft_write_formatdouble(t_format *fmt, double nbr)
{
	int			ret;
	t_fltnbr	*nb;
	t_float		*flt;
	t_print		*pnt;

	if ((ret = ft_check(nbr, fmt)))
		return (ret);
	flt = ft_setdouble(nbr);
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
