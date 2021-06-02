/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprecision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 22:35:18 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/03 14:28:43 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isprecision(const char *format)
{
	while ((*format >= '0' && *format <= '9') || *format == '*')
		format++;
	if (*format == '.')
		return (1);
	return (0);
}
