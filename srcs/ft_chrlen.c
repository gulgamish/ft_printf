/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 22:42:05 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/03 17:45:35 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_chrlen(wchar_t c)
{
	int	size;

	size = ft_count(c, 2);
	if (size <= 7)
		return (1);
	if (size <= 11)
		return (2);
	else if (size <= 16)
		return (3);
	else if (size <= 21)
		return (4);
	return (0);
}
