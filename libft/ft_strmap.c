/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 20:17:11 by aelamran          #+#    #+#             */
/*   Updated: 2018/10/11 12:27:10 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s)
	{
		while (s[i])
			i++;
		str = (char *)malloc(sizeof(*str) * (i + 1));
		if (str)
		{
			while (s[j])
			{
				str[j] = f(s[j]);
				j++;
			}
			str[j] = '\0';
			return (str);
		}
	}
	return (NULL);
}
