/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_formatchr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 22:20:20 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/18 18:49:11 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_write_formatchr(t_format *fmt, int c)
{
	int size;

	size = 0;
	if (fmt->field_width >= 1)
		size = fmt->field_width - 1;
	if (!ft_strchr(fmt->flag, '-') && size)
	{
		if (ft_strchr(fmt->flag, '0'))
			ft_write_zeros(size);
		else
			ft_write_spaces(size);
	}
	ft_putchar(c);
	if (ft_strchr(fmt->flag, '-') && size)
		ft_write_spaces(size);
	return (size + 1);
}
