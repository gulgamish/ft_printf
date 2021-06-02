/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 20:31:23 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/03 19:08:02 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printnbr(uintmax_t n)
{
	char c;

	if (n > 9)
		ft_printnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void		ft_putnbr_uint(uintmax_t nbr, t_format *fmt)
{
	if (ft_strstr(fmt->length, "hh"))
		ft_printnbr((unsigned char)nbr);
	else if (ft_strchr(fmt->length, 'h'))
		ft_printnbr((unsigned short)nbr);
	else if (ft_strstr(fmt->length, "ll"))
		ft_printnbr((unsigned long long)nbr);
	else if (ft_strchr(fmt->length, 'l'))
		ft_printnbr((unsigned long)nbr);
	else
		ft_printnbr((unsigned int)nbr);
}
