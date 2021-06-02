/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 16:00:40 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/18 20:21:16 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_power(int nb, int power)
{
	int res;

	res = 1;
	if (power == 0)
		return (1);
	if (power > 0)
	{
		while (power > 0)
		{
			res *= nb;
			power--;
		}
	}
	else
		return (0);
	return (res);
}
