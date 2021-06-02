/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_formatbin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 20:00:17 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/18 14:28:54 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_print	*ft_print(t_format *fmt)
{
	t_print	*p;

	p = ft_newlist();
	if (fmt->precision == -1)
		fmt->precision = 16;
	if (ft_strchr(fmt->flag, '#'))
	{
		p->prefix = ft_strdup("0b");
		fmt->field_width -= 2;
	}
	if (fmt->field_width > fmt->precision)
		p->spaces = fmt->field_width - fmt->precision;
	if (ft_strchr(fmt->flag, '0') && !ft_strchr(fmt->flag, '-'))
	{
		p->zeros += p->spaces;
		p->spaces = 0;
	}
	return (p);
}

int				ft_write_formatbin(t_format *fmt, int c)
{
	t_print	*pnt;
	int		ret;

	pnt = ft_print(fmt);
	ret = 0;
	if (ft_strchr(fmt->flag, '#'))
		ret += 2;
	if (pnt->spaces && !ft_strchr(fmt->flag, '-'))
		ft_write_spaces(pnt->spaces);
	if (pnt->prefix)
		ft_putstr(pnt->prefix);
	if (pnt->zeros)
		ft_write_zeros(pnt->zeros);
	ft_printbin(c, (fmt->precision == -1 ? 16 : fmt->precision));
	if (pnt->spaces && ft_strchr(fmt->flag, '-'))
		ft_write_spaces(pnt->spaces);
	return (pnt->spaces + pnt->zeros +
			(fmt->precision == -1 ? 16 : fmt->precision) + ret);
}
