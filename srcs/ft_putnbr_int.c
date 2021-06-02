/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 21:21:48 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/17 16:40:47 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printnbr(intmax_t n)
{
	uintmax_t	max;
	char		c;

	if (n < 0)
		max = -n;
	else
		max = n;
	if (max > 9)
		ft_printnbr(max / 10);
	c = (max % 10) + '0';
	write(1, &c, 1);
}

void	ft_putnbr_int(intmax_t nbr, t_format *fmt)
{
	if (ft_strstr(fmt->length, "hh"))
		ft_printnbr((char)nbr);
	else if (ft_strchr(fmt->length, 'h'))
		ft_printnbr((short)nbr);
	else if (ft_strstr(fmt->length, "ll"))
		ft_printnbr((long long)nbr);
	else if (ft_strchr(fmt->length, 'l'))
		ft_printnbr((long)nbr);
	else
		ft_printnbr((int)nbr);
}
