/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:25:38 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/13 14:52:49 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_determine_sign(t_format *fmt, t_fltnbr *flt)
{
	char sign;

	sign = '\0';
	if (ft_strchr(fmt->flag, '+') || flt->sign == '-')
	{
		if (flt->sign == '-')
			sign = '-';
		else
			sign = '+';
		fmt->field_width--;
	}
	return (sign);
}

t_print	*ft_printit(t_format *fmt, t_fltnbr *flt)
{
	t_print *pnt;
	int		size;

	pnt = ft_newlist();
	size = flt->lengthd;
	if (fmt->precision == -1)
		size = flt->lengthd + 7;
	else if (fmt->precision > 0)
		size = flt->lengthd + fmt->precision + 1;
	pnt->sign = ft_determine_sign(fmt, flt);
	if (ft_strchr(fmt->flag, ' ') && !ft_strchr(fmt->flag, '+')
			&& flt->sign != '-')
	{
		fmt->field_width--;
		pnt->spaces++;
	}
	if (fmt->field_width > size)
		pnt->spaces = fmt->field_width - size;
	if (ft_strchr(fmt->flag, '0') && !ft_strchr(fmt->flag, '-'))
	{
		pnt->zeros += pnt->spaces;
		pnt->spaces = 0;
	}
	return (pnt);
}
