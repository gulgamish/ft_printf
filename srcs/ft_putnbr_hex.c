/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 19:26:50 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/18 18:56:52 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(uintmax_t nbr, t_format *fmt)
{
	if (ft_strstr(fmt->length, "hh"))
		ft_tohex((unsigned char)nbr, fmt->conversion);
	else if (ft_strchr(fmt->length, 'h'))
		ft_tohex((unsigned short)nbr, fmt->conversion);
	else if (ft_strstr(fmt->length, "ll"))
		ft_tohex((unsigned long long)nbr, fmt->conversion);
	else if (ft_strchr(fmt->length, 'l'))
		ft_tohex((unsigned long)nbr, fmt->conversion);
	else
		ft_tohex((unsigned int)nbr, fmt->conversion);
}
