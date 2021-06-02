/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:51:30 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/18 20:10:59 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_isnegative(intmax_t nbr, t_format *fmt)
{
	if (ft_strstr(fmt->length, "hh"))
	{
		if ((char)nbr < 0)
			return (1);
	}
	else if (ft_strchr(fmt->length, 'h'))
	{
		if ((short)nbr < 0)
			return (1);
	}
	else if (ft_strstr(fmt->length, "ll"))
	{
		if ((long long)nbr < 0)
			return (1);
	}
	else if (ft_strchr(fmt->length, 'l'))
	{
		if ((long)nbr < 0)
			return (1);
	}
	else if ((int)nbr < 0)
		return (1);
	return (0);
}

t_number		*ft_newls(intmax_t nbr, t_format *fmt)
{
	t_number	*nb;

	nb = (t_number *)malloc(sizeof(t_number));
	if (!nb)
		return (NULL);
	nb->nbr = nbr;
	if (nbr == 0 && fmt->precision == 0 && fmt->conversion != 'o')
		nb->len = 0;
	else if (nbr == 0 && fmt->precision == 0 && fmt->conversion == 'o'
			&& !ft_strchr(fmt->flag, '#'))
		nb->len = 0;
	else
		nb->len = ft_countnbr(nbr, fmt);
	if (fmt->conversion == 'd' || fmt->conversion == 'i')
		nb->negative = ft_isnegative(nbr, fmt);
	return (nb);
}
