/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmantissa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:17:20 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/16 23:44:02 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_joinit(int size, char *s)
{
	char	*str;
	int		i;

	str = ft_strnew(size);
	i = 0;
	while (i < size)
	{
		str[i] = '0';
		i++;
	}
	str[i] = '\0';
	return (ft_strjoin(str, s));
}

char	*ft_getit(char *str, int size, char *s)
{
	static int	pad = 1;
	int			i;

	i = 1;
	while (i < size)
	{
		str = ft_getline(str, '5');
		i++;
	}
	str = ft_joinit(pad, str);
	if (s)
	{
		if (ft_strlen(str) - ft_strlen(s) <= 0)
		{
			str = ft_strjoin("0", str);
			pad++;
		}
	}
	return (str);
}

char	*ft_fillitb(char *str, int size)
{
	char	*s;
	int		j;
	int		i;

	i = size - ft_strlen(str);
	j = 0;
	s = ft_strnew(i);
	while (j < i)
	{
		s[j] = '0';
		j++;
	}
	s[j] = '\0';
	return (ft_strjoin(str, s));
}

void	ft_fill(char **str)
{
	int i;
	int size;

	i = 0;
	while (*(str + i))
		i++;
	i--;
	size = ft_strlen(*(str + i));
	i = 0;
	while (*(str + i))
	{
		*(str + i) = ft_fillitb(*(str + i), size);
		i++;
	}
}

char	**ft_getitall(char *man)
{
	char	**ptr;
	int		j;
	int		i;

	i = 1;
	j = 0;
	ptr = (char **)malloc(sizeof(char *) * 64);
	while (*man)
	{
		if (*man == '1')
		{
			*(ptr + j) = ft_getit("5", i, (j > 0 ? *(ptr + (j - 1)) : NULL));
			j++;
		}
		i++;
		man++;
	}
	*(ptr + j) = NULL;
	ft_fill(ptr);
	return (ptr);
}
