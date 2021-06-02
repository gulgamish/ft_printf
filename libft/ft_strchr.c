/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 11:13:49 by aelamran          #+#    #+#             */
/*   Updated: 2018/10/11 16:30:02 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strchr(const char *s, int c)
{
	char			chr;
	size_t			i;
	size_t			size;

	chr = c;
	i = 0;
	size = ft_strlen(s);
	while (i <= size)
	{
		if (s[i] == chr)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
