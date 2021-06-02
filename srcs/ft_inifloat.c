/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inifloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:23:37 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/06 15:27:32 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_float	*ft_inifloat(void)
{
	t_float *ft;

	ft = (t_float *)malloc(sizeof(t_float));
	if (!ft)
		return (NULL);
	ft->sign = 0;
	ft->exponent = 0;
	return (ft);
}
