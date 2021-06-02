/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:22:29 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/17 19:44:07 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_float		*ft_setdouble(double nbr)
{
	t_float			*sfloat;
	union u_typed	udouble;

	udouble.nbr = nbr;
	sfloat = ft_inifloat();
	if (udouble.rd_double.sign)
		sfloat->sign = -1;
	else
		sfloat->sign = 1;
	sfloat->exponent = udouble.rd_double.exp - 1023;
	sfloat->mantissa = ft_getmantissad(udouble.rd_double.mantissa
			, sfloat->exponent);
	sfloat->length = ft_strlen(sfloat->mantissa);
	return (sfloat);
}
