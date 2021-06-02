/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 23:12:58 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/18 20:20:31 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_addition	*ft_add(int anas, int s, int c)
{
	t_addition	*add;
	int			nb;
	int			temp;

	nb = (s >= 0 && s <= 9 ? s : 0)
		+ (c >= 0 && c <= 9 ? c : 0) + anas;
	add = (t_addition *)malloc(sizeof(t_addition));
	if (nb > 9)
	{
		temp = nb / 10;
		add->anas = temp;
		temp = nb - 10;
		add->nbr = temp + 48;
	}
	else
	{
		add->nbr = nb + 48;
		add->anas = 0;
	}
	return (add);
}

char		*ft_addition(char *s1, char *s2)
{
	char		*str;
	int			i;
	int			j;
	t_addition	*add;

	add = NULL;
	i = ft_strlen(s1) - 1;
	j = ft_strlen(s2) - 1;
	str = ft_strnew(5000);
	while (i >= 0 || j >= 0)
	{
		if (add)
			add = ft_add(add->anas, (i < 0 ? 0 : s1[i] - 48),
					(j < 0 ? 0 : s2[j] - 48));
		else
			add = ft_add(0, s1[i] - 48, s2[j] - 48);
		str = ft_join(str, add->nbr);
		i--;
		j--;
	}
	if (add->anas > 0)
		str = ft_join(str, add->anas + 48);
	return (str);
}
