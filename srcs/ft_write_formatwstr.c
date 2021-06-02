/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_formatwstr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:16:28 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/17 18:50:24 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_print	*ft_print(t_format *fmt, wchar_t *str)
{
	t_print	*pnt;
	int		size;

	pnt = ft_newlist();
	size = ft_wstrlen(str);
	if (fmt->field_width && fmt->precision < size &&
		fmt->precision != -1)
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

static	void	ft_putwstr(wchar_t *str)
{
	while (*str)
	{
		ft_putwchar(*str);
		str++;
	}
}

int				ft_printwstr(t_format *fmt, wchar_t *str, int size)
{
	int i;
	int ret;

	i = 0;
	if (fmt->precision != -1 && fmt->precision < size)
	{
		while (*str && i < fmt->precision)
		{
			if ((ret = ft_chrlen(*str)) > (fmt->precision - i))
				return (i);
			else
				i += ret;
			ft_putwchar(*str);
			str++;
		}
	}
	else
	{
		ft_putwstr(str);
		return (size);
	}
	return (fmt->precision);
}

int				ft_write_formatwstr(t_format *fmt, wchar_t *str)
{
	t_print *pnt;
	int		size;
	int		len;

	if (!str)
		str = L"(null)";
	pnt = ft_print(fmt, str);
	size = ft_wstrlen(str);
	if (!ft_strchr(fmt->flag, '-') && pnt->spaces)
		ft_write_spaces(pnt->spaces);
	if (pnt->zeros)
		ft_write_zeros(pnt->zeros);
	len = ft_printwstr(fmt, str, size);
	if (ft_strchr(fmt->flag, '-') && pnt->spaces)
		ft_write_spaces(pnt->spaces);
	return (len + pnt->spaces + pnt->zeros);
}
