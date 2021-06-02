/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setldouble.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 19:48:48 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/18 14:47:49 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_float		*ft_setldouble(long double nbr)
{
	t_float			*sfloat;
	union u_type	un;

	un.nbr = nbr;
	sfloat = ft_inifloat();
	if (un.rd.sign == -1)
		sfloat->sign = -1;
	else
		sfloat->sign = 1;
	sfloat->exponent = un.rd.exp - 16383;
	sfloat->mantissa = ft_getmantissald(un.rd.mantissa,
			(un.rd.integer ? 1 : 0));
	sfloat->length = ft_strlen(sfloat->mantissa);
	return (sfloat);
}
