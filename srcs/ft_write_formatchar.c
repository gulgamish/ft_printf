/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_formatchar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 22:16:12 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/17 18:51:23 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_print	*ft_print(t_format *fmt, char *str)
{
	t_print	*pnt;
	int		size;

	pnt = ft_newlist();
	size = ft_strlen(str);
	if (fmt->precision != -1 &&
		fmt->precision < size && fmt->field_width > fmt->precision)
		pnt->spaces = fmt->field_width - fmt->precision;
	else if (fmt->field_width > size)
		pnt->spaces = fmt->field_width - size;
	if (ft_strchr(fmt->flag, '0') && !ft_strchr(fmt->flag, '-'))
	{
		pnt->zeros += pnt->spaces;
		pnt->spaces = 0;
	}
	return (pnt);
}

int				ft_write_formatchar(t_format *fmt, char *str)
{
	t_print *pnt;
	int		size;

	if (!str)
		str = "(null)";
	pnt = ft_print(fmt, str);
	size = ft_strlen(str);
	if (!ft_strchr(fmt->flag, '-') && pnt->spaces)
		ft_write_spaces(pnt->spaces);
	if (pnt->zeros)
		ft_write_zeros(pnt->zeros);
	if (fmt->precision != -1 && fmt->precision < size)
		write(1, str, fmt->precision);
	else
		write(1, str, size);
	if (ft_strchr(fmt->flag, '-') && pnt->spaces)
		ft_write_spaces(pnt->spaces);
	return ((fmt->precision != -1 &&
	fmt->precision < size ? fmt->precision : size) + pnt->spaces + pnt->zeros);
}
