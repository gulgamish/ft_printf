/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_formatwchr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:40:41 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/17 18:40:00 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_write_formatwchr(t_format *fmt, wchar_t c)
{
	int size;
	int length;

	size = 0;
	length = ft_chrlen(c);
	if (fmt->field_width > length)
		size = fmt->field_width - length;
	if (!ft_strchr(fmt->flag, '-') && size)
	{
		if (ft_strchr(fmt->flag, '0'))
			ft_write_zeros(size);
		else
			ft_write_spaces(size);
	}
	ft_putwchar(c);
	if (ft_strchr(fmt->flag, '-') && size)
		ft_write_spaces(size);
	return (size + length);
}
