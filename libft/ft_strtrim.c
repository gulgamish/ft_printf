/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 11:18:24 by aelamran          #+#    #+#             */
/*   Updated: 2018/10/10 11:15:04 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_size(char const *s)
{
	int i;

	i = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (s[i + 1])
		i++;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	return (i + 1);
}

char			*ft_strtrim(char const *s)
{
	int		size;
	char	*str;
	int		i;

	size = ft_size(s);
	str = (char *)malloc(sizeof(*str) * size + 1);
	i = 0;
	if (str)
	{
		while (*s == ' ' || *s == '\n' || *s == '\t')
			s++;
		while (i < size)
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
