/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:57:50 by aelamran          #+#    #+#             */
/*   Updated: 2018/12/28 23:10:51 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_len(long int nbr)
{
	int					size;
	unsigned long int	n;

	size = 1;
	if (nbr < 0)
	{
		n = -nbr;
		size++;
	}
	else
		n = nbr;
	n /= 10;
	while (n >= 1)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static int		ft_pow(long int nb, int power)
{
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	if (power > 1)
		return (nb * ft_pow(nb, power - 1));
	return (0);
}

static void		ft_fill(char *str, long int n, int size)
{
	unsigned long int	nb;
	int					s;
	int					p;
	int					i;

	i = 0;
	s = size;
	if (n < 0)
	{
		str[i++] = '-';
		nb = -n;
		size--;
	}
	else
		nb = n;
	p = ft_pow(10, size - 1);
	while (i < s)
	{
		str[i] = (nb / p) + '0';
		nb %= p;
		p /= 10;
		i++;
	}
	str[i] = '\0';
}

char			*ft_itoa(long int n)
{
	int		size;
	char	*str;

	size = ft_len(n);
	str = (char *)malloc(sizeof(*str) * (size + 1));
	if (str)
	{
		ft_fill(str, n, size);
		return (str);
	}
	return (NULL);
}
