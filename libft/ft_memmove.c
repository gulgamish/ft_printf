/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 16:39:49 by aelamran          #+#    #+#             */
/*   Updated: 2018/10/11 16:42:33 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*cmp;

	cmp = malloc(sizeof(void) * len);
	if (cmp)
	{
		ft_memcpy(cmp, src, len);
		ft_memcpy(dst, cmp, len);
	}
	return (dst);
}
