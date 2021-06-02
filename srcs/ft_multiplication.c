/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiplication.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 00:50:17 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/18 20:21:27 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_multi		*ft_multiplication(int anas, int s, int c)
{
	t_multi	*multi;
	int		nb;
	int		temp;
	int		p;

	nb = (s * c) + anas;
	multi = (t_multi *)malloc(sizeof(t_multi));
	if (nb > 9)
	{
		temp = nb / 10;
		multi->anas = temp;
		p = temp * 10;
		temp = nb - p;
		multi->nbr = temp + 48;
	}
	else
	{
		multi->nbr = nb + 48;
		multi->anas = 0;
	}
	return (multi);
}
