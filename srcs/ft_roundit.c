/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roundit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:14:41 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/13 14:14:56 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_roundit(char **str, int i)
{
	char *fraction;

	fraction = *str;
	if (fraction[i] == '9')
	{
		while (fraction[i] == '9')
			fraction[i--] = '0';
	}
	fraction[i]++;
	*str = fraction;
	return (i);
}
