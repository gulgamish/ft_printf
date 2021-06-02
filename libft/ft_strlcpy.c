/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 22:00:41 by aelamran          #+#    #+#             */
/*   Updated: 2018/10/10 22:27:02 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static	size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t			ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s_src;

	i = 0;
	s_src = ft_strlen(src);
	if (size <= 0)
		return (s_src);
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (s_src);
}
