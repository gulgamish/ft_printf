/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readarg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:41:00 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/17 20:07:14 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_readfloat(va_list ap, t_format *fmt)
{
	if (ft_strchr(fmt->length, 'L'))
		return (ft_write_formatldouble(fmt, va_arg(ap, long double)));
	return (ft_write_formatdouble(fmt, va_arg(ap, double)));
}

int		ft_readarg(va_list ap, t_format *fmt)
{
	if (fmt->conversion == 'c' && ft_strchr(fmt->length, 'l'))
		return (ft_write_formatwchr(fmt, va_arg(ap, wchar_t)));
	else if (fmt->conversion == 'c')
		return (ft_write_formatchr(fmt, va_arg(ap, int)));
	else if (fmt->conversion == 'C')
		return (ft_write_formatwchr(fmt, va_arg(ap, wchar_t)));
	else if (fmt->conversion == 'S' || (fmt->conversion == 's' &&
				ft_strchr(fmt->length, 'l')))
		return (ft_write_formatwstr(fmt, va_arg(ap, wchar_t *)));
	else if (fmt->conversion == 'p')
		return (ft_write_formatint(fmt, va_arg(ap, long)));
	else if (fmt->conversion == 'd' || fmt->conversion == 'i')
		return (ft_write_formatint(fmt, va_arg(ap, intmax_t)));
	else if (fmt->conversion == 's')
		return (ft_write_formatchar(fmt, va_arg(ap, char *)));
	else if (fmt->conversion == 'o' || fmt->conversion == 'u'
			|| fmt->conversion == 'x' || fmt->conversion == 'X')
		return (ft_write_formatint(fmt, va_arg(ap, uintmax_t)));
	else if (fmt->conversion == '%')
		return (ft_write_formatchr(fmt, '%'));
	else if (fmt->conversion == 'b')
		return (ft_write_formatbin(fmt, va_arg(ap, int)));
	else if (fmt->conversion == 'f')
		return (ft_readfloat(ap, fmt));
	return (0);
}
