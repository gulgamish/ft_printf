/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmantissa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:08:22 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/17 19:43:13 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_getmantissa(long mantissa, int exp)
{
	char	**str;
	char	*res;
	int		counter;
	int		i;

	i = 0;
	counter = 22;
	str = ft_getitall("11111111111111111111111");
	res = ft_makefirst(str, exp);
	while (counter >= 0)
	{
		if ((mantissa >> counter) & 1)
			res = ft_addition(res, *(str + i));
		counter--;
		i++;
	}
	ft_eliminate_zeros(&res);
	return (res);
}
