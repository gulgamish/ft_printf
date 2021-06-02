/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:58:07 by aelamran          #+#    #+#             */
/*   Updated: 2018/10/10 20:39:53 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const	char		*str;
	unsigned char		chr;
	size_t				i;

	str = (char *)s;
	chr = c;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)str[i] == chr)
			return ((void *)str + i);
		i++;
	}
	return (NULL);
}
