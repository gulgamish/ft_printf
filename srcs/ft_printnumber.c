/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 20:13:44 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/18 20:03:40 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printnumber(t_number *nbr, t_format *fmt)
{
	if (nbr->nbr == 0 && fmt->precision == 0)
		return ;
	else
	{
		if (fmt->conversion == 'd' || fmt->conversion == 'i')
			ft_putnbr_int(nbr->nbr, fmt);
		else if (fmt->conversion == 'p')
			ft_tohex((long)nbr->nbr, 'x');
		else if (fmt->conversion == 'o')
			ft_putnbr_octal(nbr->nbr, fmt);
		else if (fmt->conversion == 'u')
			ft_putnbr_uint(nbr->nbr, fmt);
		else if (fmt->conversion == 'x' || fmt->conversion == 'X')
			ft_putnbr_hex(nbr->nbr, fmt);
	}
}
