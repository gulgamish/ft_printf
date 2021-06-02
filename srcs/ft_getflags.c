/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 22:14:16 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/13 21:06:01 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_getflagslength(const char *format)
{
	int length;

	length = 0;
	while (*format == '-' || *format == '+' || *format == ' ' || *format == '0'
			|| *format == '#')
	{
		length++;
		format++;
	}
	return (length);
}

char	*ft_getflags(const char **format)
{
	char		*flags;
	int			size;
	const char	*fmt;
	int			i;

	fmt = *format;
	size = ft_getflagslength(*format);
	flags = ft_strnew(size);
	i = 0;
	while (*fmt == '-' || *fmt == '+' || *fmt == ' ' || *fmt == '0'
			|| *fmt == '#')
	{
		flags[i] = *fmt;
		i++;
		fmt++;
	}
	flags[i] = '\0';
	*format = fmt;
	return (flags);
}
