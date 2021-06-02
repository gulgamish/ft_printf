/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:54:43 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/17 20:40:52 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_addtodouble(int size, char **str)
{
	char	*s;
	char	*ptr;
	int		i;

	s = *str;
	ptr = ft_strnew(size);
	i = 0;
	while (i < size)
		ptr[i++] = '0';
	s = ft_strjoin(ptr, s);
	*str = s;
}

t_fltnbr	*ft_getdouble(t_float *flt)
{
	t_fltnbr	*fltn;
	char		*str;
	int			sizenbr;

	str = ft_calcfloat(flt);
	sizenbr = ft_strlen(str);
	fltn = (t_fltnbr *)malloc(sizeof(t_fltnbr));
	fltn->sign = (flt->sign < 0 ? '-' : '\0');
	if (flt->length > sizenbr)
	{
		fltn->decimal = ft_strdup("0");
		fltn->lengthd = 1;
		ft_addtodouble(flt->length - sizenbr - 1, &str);
		fltn->fraction = str;
	}
	else
	{
		fltn->decimal = ft_strsub(str, 0, sizenbr - flt->length + 1);
		fltn->lengthd = sizenbr - flt->length + 1;
		fltn->fraction = ft_strsub(str, sizenbr - flt->length + 1,
				sizenbr - (sizenbr - flt->length + 1));
	}
	return (fltn);
}
