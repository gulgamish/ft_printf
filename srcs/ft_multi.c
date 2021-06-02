/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:44:19 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/16 23:33:55 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_concattoleft(char *str, int k)
{
	char	*temp;
	char	*t;
	int		i;

	t = ft_strnew(k);
	i = 0;
	while (k)
	{
		t[i++] = '0';
		k--;
	}
	t[i] = '\0';
	temp = str;
	str = ft_strjoin(str, t);
	free(temp);
	free(t);
	return (str);
}

char		*ft_addthem(char **ptr, int j)
{
	char	*res;
	int		i;

	i = 1;
	res = *ptr;
	while (i < j)
	{
		res = ft_addition(res, *(ptr + i));
		i++;
	}
	return (res);
}

char		*ft_multi(char *s1, char *s2)
{
	char	**ptr;
	int		i;
	int		j;
	t_multi	*multi;

	i = ft_strlen(s2) - 1;
	multi = NULL;
	ptr = (char **)malloc(sizeof(char *) * 100);
	j = 0;
	while (i >= 0)
	{
		*(ptr + j) = ft_getline(s1, s2[i]);
		*(ptr + j) = ft_concattoleft(*(ptr + j), j);
		i--;
		j++;
	}
	return (ft_addthem(ptr, j));
}
