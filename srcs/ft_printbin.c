/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 19:47:54 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/17 15:01:11 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printbin(int nbr, int count)
{
	char	*str;
	int		counter;
	int		i;
	int		n;

	counter = 63;
	i = 0;
	str = ft_strnew(64);
	while (counter >= 0)
	{
		n = (nbr >> counter) & 1;
		str[i] = n + 48;
		counter--;
		i++;
	}
	i--;
	i -= count - 1;
	while (count > 0)
	{
		ft_putchar(str[i++]);
		count--;
	}
	ft_strdel(&str);
}
