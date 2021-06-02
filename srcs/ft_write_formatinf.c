/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_formatinf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:43:54 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/14 19:15:49 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*ft_printinf(t_format *fmt, char *str, int sign)
{
	t_print *pnt;
	int		size;

	pnt = ft_newlist();
	size = ft_strlen(str);
	if ((ft_strchr(fmt->flag, '+') || sign) && ft_strcmp(str, "nan"))
	{
		if (sign)
			pnt->sign = '-';
		else
			pnt->sign = '+';
		fmt->field_width--;
	}
	if (ft_strchr(fmt->flag, ' ') && sign != 1 && ft_strcmp(str, "nan"))
	{
		pnt->spaces++;
		fmt->field_width--;
	}
	if (fmt->field_width > size)
		pnt->spaces += fmt->field_width - size;
	return (pnt);
}

int		ft_write_formatinf(t_format *fmt, char *str, int sign)
{
	t_print *pnt;

	pnt = ft_printinf(fmt, str, sign);
	if (pnt->spaces && !ft_strchr(fmt->flag, '-'))
		ft_write_spaces(pnt->spaces);
	if (pnt->sign)
		ft_putchar(pnt->sign);
	ft_putstr(str);
	if (pnt->spaces && ft_strchr(fmt->flag, '-'))
		ft_write_spaces(pnt->spaces);
	return (pnt->spaces + 3 + (pnt->sign ? 1 : 0));
}
