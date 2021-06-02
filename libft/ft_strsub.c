/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:29:57 by aelamran          #+#    #+#             */
/*   Updated: 2018/10/10 11:14:23 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(*str) * (len + 1));
	i = 0;
	if (str)
	{
		while (i < len)
		{
			str[i] = s[start];
			start++;
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
