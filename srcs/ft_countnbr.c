/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:20:15 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/18 19:06:51 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_int(intmax_t nbr, t_format *fmt)
{
	if (ft_strstr(fmt->length, "hh"))
		return (ft_count((char)nbr, 10));
	else if (ft_strchr(fmt->length, 'h'))
		return (ft_count((short)nbr, 10));
	else if (ft_strstr(fmt->length, "ll"))
		return (ft_count((long long)nbr, 10));
	else if (ft_strchr(fmt->length, 'l'))
		return (ft_count((long)nbr, 10));
	else
		return (ft_count((int)nbr, 10));
	return (0);
}

int		ft_count_octal(uintmax_t nbr, t_format *fmt)
{
	if (ft_strstr(fmt->length, "hh"))
		return (ft_ucount((unsigned char)nbr, 8));
	else if (ft_strchr(fmt->length, 'h'))
		return (ft_ucount((unsigned short)nbr, 8));
	else if (ft_strstr(fmt->length, "ll"))
		return (ft_ucount((unsigned long long)nbr, 8));
	else if (ft_strchr(fmt->length, 'l'))
		return (ft_ucount((unsigned long)nbr, 8));
	else
		return (ft_ucount((unsigned int)nbr, 8));
	return (0);
}

int		ft_count_uint(uintmax_t nbr, t_format *fmt)
{
	if (ft_strstr(fmt->length, "hh"))
		return (ft_ucount((unsigned char)nbr, 10));
	else if (ft_strchr(fmt->length, 'h'))
		return (ft_ucount((unsigned short)nbr, 10));
	else if (ft_strstr(fmt->length, "ll"))
		return (ft_ucount((unsigned long long)nbr, 10));
	else if (ft_strchr(fmt->length, 'l'))
		return (ft_ucount((unsigned long)nbr, 10));
	else
		return (ft_ucount((unsigned int)nbr, 10));
	return (0);
}

int		ft_count_hex(uintmax_t nbr, t_format *fmt)
{
	if (ft_strstr(fmt->length, "hh"))
		return (ft_ucount((unsigned char)nbr, 16));
	else if (ft_strchr(fmt->length, 'h'))
		return (ft_ucount((unsigned short)nbr, 16));
	else if (ft_strstr(fmt->length, "ll"))
		return (ft_ucount((unsigned long long)nbr, 16));
	else if (ft_strchr(fmt->length, 'l'))
		return (ft_ucount((unsigned long)nbr, 16));
	else
		return (ft_ucount((unsigned int)nbr, 16));
	return (0);
}

int		ft_countnbr(intmax_t nbr, t_format *fmt)
{
	if (fmt->conversion == 'd' || fmt->conversion == 'i')
		return (ft_count_int(nbr, fmt));
	else if (fmt->conversion == 'p')
		return (ft_count((long)nbr, 16));
	else if (fmt->conversion == 'o')
		return (ft_count_octal(nbr, fmt));
	else if (fmt->conversion == 'u')
		return (ft_count_uint(nbr, fmt));
	else if (fmt->conversion == 'x' || fmt->conversion == 'X')
		return (ft_count_hex(nbr, fmt));
	return (0);
}
