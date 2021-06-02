/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 15:58:01 by aelamran          #+#    #+#             */
/*   Updated: 2018/10/10 16:47:41 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*d;
	const	char	*s;
	unsigned char	p;
	size_t			i;

	d = (char *)dst;
	s = (char *)src;
	p = c;
	i = 0;
	while (i < n && (unsigned char)s[i] != p)
	{
		d[i] = s[i];
		i++;
	}
	if ((unsigned char)s[i] == p)
	{
		d[i] = p;
		return (dst + i + 1);
	}
	else
		return ((void *)0);
}
