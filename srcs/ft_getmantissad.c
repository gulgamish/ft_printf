/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmantissad.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:15:07 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/17 00:06:37 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_getmantissad(long man, int exp)
{
	char	**ptr;
	char	*res;
	int		counter;
	int		i;

	ptr = ft_getitall("1111111111111111111111111111111111111111111111111111");
	res = ft_makefirst(ptr, exp);
	counter = 51;
	i = 0;
	while (counter >= 0)
	{
		if ((man >> counter) & 1)
			res = ft_addition(res, *(ptr + i));
		counter--;
		i++;
	}
	ft_eliminate_zeros(&res);
	return (res);
}
