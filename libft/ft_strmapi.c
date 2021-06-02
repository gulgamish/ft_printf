/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:04:31 by aelamran          #+#    #+#             */
/*   Updated: 2018/10/10 21:00:31 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	int				i;
	unsigned int	j;

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
				str[j] = f(j, s[j]);
				j++;
			}
			str[j] = '\0';
			return (str);
		}
	}
	return (NULL);
}
