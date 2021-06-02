/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 19:20:08 by aelamran          #+#    #+#             */
/*   Updated: 2018/10/10 11:11:46 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*b;
	char	*s;
	size_t	i;

	b = malloc(size);
	s = b;
	i = 0;
	if (b)
	{
		while (i < size)
		{
			s[i] = 0;
			i++;
		}
		return (b);
	}
	return (NULL);
}
