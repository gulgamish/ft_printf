/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isgreater.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:18:34 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/13 14:28:34 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isgreater(char *fraction)
{
	while (*fraction)
	{
		if (*fraction > '5')
			return (1);
		fraction++;
	}
	return (0);
}
