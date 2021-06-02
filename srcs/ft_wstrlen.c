/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 23:06:21 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/03 14:35:39 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wstrlen(wchar_t *str)
{
	int size;

	size = 0;
	while (*str)
	{
		size += ft_chrlen(*str);
		str++;
	}
	return (size);
}
