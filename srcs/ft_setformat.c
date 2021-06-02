/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 16:30:18 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/17 23:57:35 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_getfieldwidth(const char **format, t_format *frmt, va_list ap)
{
	const char	*fmt;
	int			f_width;

	fmt = *format;
	if (*fmt == '*')
	{
		f_width = va_arg(ap, int);
		if (f_width < 0)
		{
			frmt->flag = ft_strjoin(frmt->flag, "-");
			f_width = -f_width;
		}
		fmt++;
	}
	else
	{
		f_width = ft_atoi(fmt);
		while (*fmt >= '0' && *fmt <= '9')
			fmt++;
	}
	*format = fmt;
	return (f_width);
}

int			ft_getprecision(const char **format, va_list ap)
{
	const char	*fmt;
	int			num;

	fmt = *format;
	if (*fmt == '.')
		fmt++;
	if (*fmt == '*')
	{
		num = va_arg(ap, int);
		if (num < 0)
			num = -1;
		fmt++;
	}
	else
	{
		num = ft_atoi(fmt);
		while (*fmt >= '0' && *fmt <= '9')
			fmt++;
	}
	*format = fmt;
	return (num);
}

char		ft_getconversion(const char **format)
{
	const char	*fmt;
	char		c;

	fmt = *format;
	if (*fmt == 'c' || *fmt == 'C' || *fmt == 's' || *fmt == 'p' ||
			*fmt == 'd' || *fmt == 'i' || *fmt == 'o' || *fmt == 'u' ||
			*fmt == 'x' || *fmt == 'X' || *fmt == 'f' || *fmt == '%' ||
			*fmt == 'S' || *fmt == 'b')
	{
		c = *fmt;
		fmt++;
	}
	else
		c = 0;
	*format = fmt;
	return (c);
}

t_format	*ft_setformat(const char **pfmt, va_list ap)
{
	t_format	*fmt;
	const char	*format;

	fmt = (t_format *)malloc(sizeof(t_format));
	if (!fmt)
		return (NULL);
	format = *pfmt;
	fmt->flag = ft_getflags(&format);
	if (ft_isprecision(format))
	{
		fmt->field_width = ft_getfieldwidth(&format, fmt, ap);
		fmt->precision = ft_getprecision(&format, ap);
		fmt->length = ft_getlength(&format);
	}
	else
	{
		fmt->field_width = ft_getfieldwidth(&format, fmt, ap);
		fmt->precision = -1;
		fmt->length = ft_getlength(&format);
	}
	fmt->conversion = ft_getconversion(&format);
	*pfmt = format;
	return (fmt);
}
