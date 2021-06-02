/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:50:17 by aelamran          #+#    #+#             */
/*   Updated: 2018/10/12 10:40:43 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	while (len > 0 && *haystack)
	{
		i = 0;
		while (needle[i] && (haystack[i] == needle[i]) && i < len)
			i++;
		if (ft_strlen(needle) == i)
			return ((char *)haystack);
		len--;
		haystack++;
	}
	return (NULL);
}
