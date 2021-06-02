/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toctal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 19:32:55 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/03 19:21:33 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_toctal(uintmax_t n)
{
	char c;

	if (n > 7)
		ft_toctal(n / 8);
	c = (n % 8) + '0';
	write(1, &c, 1);
}
