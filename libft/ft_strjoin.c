/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:53:08 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/08 22:03:01 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static int		ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static	char	*ft_join(char *str, char const *s1, char const *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[j])
	{
		str[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*str;

	size = sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2)) + 1;
	str = (char *)malloc(size);
	if (str)
	{
		str = ft_join(str, s1, s2);
		return (str);
	}
	return (NULL);
}
