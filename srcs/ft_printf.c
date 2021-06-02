/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:04:11 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/13 20:23:24 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret;
	t_format	*fmt;

	va_start(ap, format);
	ret = 0;
	while (*format)
	{
		if (*format == '{')
			ft_printcolor(&format);
		if (*format == '%')
		{
			format++;
			fmt = ft_setformat(&format, ap);
			ret += ft_readarg(ap, fmt);
		}
		else if (*format && *format != '%')
		{
			ft_putchar(*format);
			format++;
			ret++;
		}
	}
	va_end(ap);
	return (ret);
}
