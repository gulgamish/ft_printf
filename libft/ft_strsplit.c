/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 12:52:45 by aelamran          #+#    #+#             */
/*   Updated: 2018/10/10 11:16:46 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_words(char const *str, char c)
{
	int i;
	int w;

	i = 0;
	w = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			w++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (w);
}

static void		ft_allocation(char **t, char const *str, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (str[k] != '\0')
	{
		j = 1;
		while (str[k] == c)
			k++;
		while (str[k] != c && str[k] != '\0')
		{
			k++;
			j++;
		}
		if (j != 1)
		{
			t[i] = (char *)malloc(sizeof(**t) * j);
			i++;
		}
	}
}

static void		ft_fill(char **t, char const *str, int n, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < n)
	{
		j = 0;
		while (str[k] == c)
			k++;
		while (str[k] != c && str[k] != '\0')
		{
			t[i][j] = str[k];
			k++;
			j++;
		}
		if (j > 0)
		{
			t[i][j] = '\0';
			i++;
		}
	}
	t[i] = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	int		words_c;
	char	**str;

	words_c = ft_words(s, c);
	str = (char **)malloc(sizeof(*str) * (words_c + 1));
	if (str)
	{
		ft_allocation(str, s, c);
		ft_fill(str, s, words_c, c);
		return (str);
	}
	return (NULL);
}
