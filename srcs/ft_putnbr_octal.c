/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_octal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 20:17:41 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/18 18:56:57 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_octal(uintmax_t nbr, t_format *fmt)
{
	if (ft_strstr(fmt->length, "hh"))
		ft_toctal((unsigned char)nbr);
	else if (ft_strchr(fmt->length, 'h'))
		ft_toctal((unsigned short)nbr);
	else if (ft_strstr(fmt->length, "ll"))
		ft_toctal((unsigned long long)nbr);
	else if (ft_strchr(fmt->length, 'l'))
		ft_toctal((unsigned long)nbr);
	else
		ft_toctal((unsigned int)nbr);
}
