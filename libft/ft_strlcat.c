/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 09:38:50 by aelamran          #+#    #+#             */
/*   Updated: 2018/10/12 15:11:14 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	s_dst;
	size_t	s_src;

	i = 0;
	j = 0;
	s_dst = ft_strlen(dst);
	s_src = ft_strlen(src);
	if (size <= s_dst)
		return (s_src + size);
	while (j < ((size - 1) - s_dst) && src[j])
	{
		dst[s_dst + j] = src[j];
		j++;
	}
	dst[s_dst + j] = '\0';
	return (s_src + s_dst);
}
