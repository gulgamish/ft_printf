/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcfloat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 23:21:09 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/18 14:49:51 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_calcfloat(t_float *flt)
{
	char	*res;
	char	c;
	int		i;

	if (flt->exponent < 0)
	{
		c = '5';
		flt->exponent = -flt->exponent;
		flt->length += flt->exponent;
	}
	else
		c = '2';
	if (flt->exponent > 0)
	{
		res = flt->mantissa;
		i = 0;
		while (i++ < flt->exponent)
			res = ft_getline(res, c);
	}
	else
		res = flt->mantissa;
	return (res);
}
