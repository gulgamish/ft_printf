/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eliminate_zeros.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:25:20 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/13 21:02:21 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_eliminate_zeros(char **str)
{
	char	*s;
	int		sz;
	int		size;

	s = *str;
	size = ft_strlen(s);
	sz = size;
	while (size >= 0 && s[size] == '0')
		size--;
	size++;
	while (size < sz)
		s[size++] = '\0';
	*str = s;
}
