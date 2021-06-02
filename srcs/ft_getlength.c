/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlength.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 23:38:16 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/17 16:28:27 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_length(const char *format)
{
	int length;

	length = 0;
	while (*format == 'h' || *format == 'l' || *format == 'L')
	{
		length++;
		format++;
	}
	return (length);
}

char		*ft_getlength(const char **format)
{
	char		*length;
	const char	*fmt;
	int			size;
	int			i;

	fmt = *format;
	size = ft_length(*format);
	length = ft_strnew(size);
	i = 0;
	while (*fmt == 'h' || *fmt == 'l' || *fmt == 'L')
	{
		length[i] = *fmt;
		i++;
		fmt++;
	}
	length[i] = '\0';
	*format = fmt;
	return (length);
}
