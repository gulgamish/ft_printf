/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmantissald.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 19:50:22 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/18 14:49:41 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_getmantissald(unsigned long mantissa, int integer)
{
	char	**ptr;
	char	*res;
	int		counter;
	int		i;

	ptr = ft_getitall(
			"111111111111111111111111111111111111111111111111111111111111111");
	res = ft_makefirst(ptr, (integer ? 1 : -16383));
	i = 0;
	counter = 62;
	while (counter >= 0)
	{
		if ((mantissa >> counter) & 1)
			res = ft_addition(res, *(ptr + i));
		i++;
		counter--;
	}
	ft_eliminate_zeros(&res);
	return (res);
}
