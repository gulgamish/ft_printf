/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 13:38:22 by aelamran          #+#    #+#             */
/*   Updated: 2018/10/10 15:51:50 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char			*s;
	unsigned char	chr;
	size_t			i;

	s = (char *)b;
	chr = c;
	i = 0;
	while (i < len)
	{
		s[i] = chr;
		i++;
	}
	return (b);
}
