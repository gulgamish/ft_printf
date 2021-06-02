/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 18:45:28 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/03 19:21:47 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_tohex(uintmax_t n, char conversion)
{
	char	*str;

	if (conversion == 'x')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	if (n > 15)
		ft_tohex(n / 16, conversion);
	write(1, &str[n % 16], 1);
}
