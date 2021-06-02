/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_toit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:15:10 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/13 20:59:02 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_toit(char *s)
{
	char	*str;
	int		size;
	int		i;

	size = ft_strlen(s);
	str = ft_strnew(size);
	i = 0;
	while (i < size - 1)
		str[i++] = '0';
	str[i++] = '1';
	str[i] = '\0';
	s = ft_addition(str, s);
	return (s);
}
