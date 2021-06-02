/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_formatint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 18:20:03 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/18 20:07:18 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_setzeros(t_format *fmt, int *spaces, int *zeros)
{
	if (ft_strchr(fmt->flag, '0') && fmt->precision == -1 &&
			!ft_strchr(fmt->flag, '-'))
	{
		*zeros = *zeros + *spaces;
		*spaces = 0;
	}
}

static t_print	*ft_print(t_format *fmt, t_number *nbr)
{
	t_print	*p;

	p = ft_newlist();
	if (ft_strchr(fmt->flag, '#') || fmt->conversion == 'p')
		p->prefix = ft_setprefix(fmt, nbr);
	if (fmt->precision != -1 && fmt->precision > nbr->len)
		p->zeros = fmt->precision - nbr->len;
	if ((fmt->conversion == 'd' || fmt->conversion == 'i') &&
			(nbr->negative || ft_strchr(fmt->flag, '+')))
	{
		if (nbr->negative)
			p->sign = '-';
		else if (ft_strchr(fmt->flag, '+'))
			p->sign = '+';
		fmt->field_width -= 1;
	}
	if (ft_strchr(fmt->flag, ' ') && !ft_strchr(fmt->flag, '+')
	&& !nbr->negative && (fmt->conversion == 'd' || fmt->conversion == 'i'))
	{
		p->space = ' ';
		fmt->field_width -= 1;
	}
	p->spaces = fmt->field_width - p->zeros - nbr->len;
	ft_setzeros(fmt, &p->spaces, &p->zeros);
	return (p);
}

int				ft_write_formatint(t_format *fmt, intmax_t nbr)
{
	t_print		*pnt;
	t_number	*nb;

	nb = ft_newls(nbr, fmt);
	pnt = ft_print(fmt, nb);
	if (pnt->space)
		ft_putchar(pnt->space);
	if (pnt->spaces > 0 && !ft_strchr(fmt->flag, '-'))
		ft_write_spaces(pnt->spaces);
	if (pnt->sign && (fmt->conversion == 'd' || fmt->conversion == 'i'))
		ft_putchar(pnt->sign);
	if (pnt->prefix)
		ft_putstr(pnt->prefix);
	if (pnt->zeros > 0)
		ft_write_zeros(pnt->zeros);
	if (nbr == 0 && fmt->conversion == 'o' &&
			ft_strchr(fmt->flag, '#') && fmt->precision == 0)
		write(1, "0", 1);
	else
		ft_printnumber(nb, fmt);
	if (pnt->spaces > 0 && ft_strchr(fmt->flag, '-'))
		ft_write_spaces(pnt->spaces);
	return (ft_retvalue(nb, pnt, fmt));
}
