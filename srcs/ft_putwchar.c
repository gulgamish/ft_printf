/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 18:56:35 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/17 18:40:21 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwchr1(wchar_t c)
{
	char	nbr;

	nbr = 192 | (31 & (c >> 6));
	write(1, &nbr, 1);
	nbr = 128 | (63 & c);
	write(1, &nbr, 1);
}

void	ft_putwchr2(wchar_t c)
{
	char nbr;

	nbr = 224 | (15 & (c >> 12));
	write(1, &nbr, 1);
	nbr = 128 | (63 & (c >> 6));
	write(1, &nbr, 1);
	nbr = 128 | (63 & c);
	write(1, &nbr, 1);
}

void	ft_putwchr3(wchar_t c)
{
	char nbr;

	nbr = 240 | (7 & (c >> 18));
	write(1, &nbr, 1);
	nbr = 128 | (63 & (c >> 12));
	write(1, &nbr, 1);
	nbr = 128 | (63 & (c >> 6));
	write(1, &nbr, 1);
	nbr = 128 | (63 & c);
	write(1, &nbr, 1);
}

void	ft_putwchar(wchar_t c)
{
	int		size;

	size = ft_count(c, 2);
	if (size <= 7)
		write(1, &c, 1);
	else if (size <= 11)
		ft_putwchr1(c);
	else if (size <= 16)
		ft_putwchr2(c);
	else if (size <= 21)
		ft_putwchr3(c);
}
