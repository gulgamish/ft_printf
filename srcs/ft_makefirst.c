/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makefirst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:07:59 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/18 14:49:18 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_makefirst(char **str, int exp)
{
	char	*s;
	int		i;
	int		j;
	int		size;

	i = 0;
	while (*(str + i))
		i++;
	size = ft_strlen(*(str + (i - 1)));
	s = ft_strnew(size);
	if (exp == -1023 || exp == -16383)
		s[0] = '0';
	else
		s[0] = '1';
	j = 1;
	while (j < size)
	{
		s[j] = '0';
		j++;
	}
	return (s);
}
