/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 16:07:46 by aelamran          #+#    #+#             */
/*   Updated: 2018/10/10 20:41:59 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		chr;
	size_t	i;

	i = 0;
	while (i < n && (*s1 || *s2))
	{
		if ((chr = ((unsigned char)*s1 - (unsigned char)*s2)) != 0)
			return (chr);
		s1++;
		s2++;
		i++;
	}
	return (0);
}
