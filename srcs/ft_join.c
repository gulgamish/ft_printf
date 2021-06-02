/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 00:51:37 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/18 20:21:09 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_join(char *str, char c)
{
	char	*s;
	int		size;
	int		i;
	int		j;

	size = ft_strlen(str);
	s = ft_strnew(size + 2);
	i = 0;
	j = 0;
	s[i++] = c;
	if (str)
	{
		while (j < size)
		{
			s[i] = str[j];
			i++;
			j++;
		}
	}
	s[i] = '\0';
	return (s);
}
