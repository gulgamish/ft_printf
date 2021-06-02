/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:40:16 by aelamran          #+#    #+#             */
/*   Updated: 2018/10/10 11:24:51 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static	size_t	ft_strlen(const char *str, size_t n)
{
	size_t i;

	i = 0;
	while (str[i] && i < n)
		i++;
	return (i);
}

char			*ft_strndup(const char *s1, size_t n)
{
	char	*str;
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(s1, n);
	str = (char *)malloc(sizeof(*str) * (size + 1));
	if (str)
	{
		while (s1[i] && i < n)
		{
			str[i] = s1[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
