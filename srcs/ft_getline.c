/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 21:11:56 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/17 14:33:48 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_getline(char *s1, char c)
{
	char	*str;
	int		i;
	t_multi	*multi;

	i = ft_strlen(s1) - 1;
	multi = NULL;
	str = ft_strnew(5000);
	while (i >= 0)
	{
		if (multi)
			multi = ft_multiplication(multi->anas, s1[i] - 48, c - 48);
		else
			multi = ft_multiplication(0, s1[i] - 48, c - 48);
		str = ft_join(str, multi->nbr);
		i--;
	}
	if (multi && multi->anas > 0)
		str = ft_join(str, multi->anas + 48);
	return (str);
}
