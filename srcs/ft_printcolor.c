/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 19:38:42 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/15 22:27:58 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_getcolor(const char **str)
{
	const char	*s;
	int			counter;
	char		*color;

	s = *str;
	counter = 0;
	while (*s != '}')
	{
		counter++;
		s++;
	}
	color = ft_strsub(*str, 0, counter);
	*str = s + 1;
	return (color);
}

void	ft_putcolor(char *col)
{
	if (ft_strcmp(col, "red") == 0)
		ft_putstr(RED);
	else if (ft_strcmp(col, "green") == 0)
		ft_putstr(GREEN);
	else if (ft_strcmp(col, "yellow") == 0)
		ft_putstr(YELLOW);
	else if (ft_strcmp(col, "blue") == 0)
		ft_putstr(BLUE);
	else if (ft_strcmp(col, "cyan") == 0)
		ft_putstr(CYAN);
	else if (ft_strcmp(col, "eoc") == 0)
		ft_putstr(EOC);
}

int		ft_iscolor(char *col)
{
	if (ft_strcmp(col, "red") == 0)
		return (1);
	else if (ft_strcmp(col, "green") == 0)
		return (1);
	else if (ft_strcmp(col, "yellow") == 0)
		return (1);
	else if (ft_strcmp(col, "blue") == 0)
		return (1);
	else if (ft_strcmp(col, "cyan") == 0)
		return (1);
	else if (ft_strcmp(col, "eoc") == 0)
		return (1);
	return (0);
}

void	ft_printcolor(const char **format)
{
	const char	*str;
	char		*col;

	str = *format;
	str++;
	col = ft_getcolor(&str);
	ft_putcolor(col);
	if (ft_iscolor(col))
		*format = str;
	ft_strdel(&col);
}
