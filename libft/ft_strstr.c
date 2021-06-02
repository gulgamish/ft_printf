/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 11:25:31 by aelamran          #+#    #+#             */
/*   Updated: 2018/10/11 18:20:14 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s2)
	{
		if ((*s1 - *s2) != 0)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

char			*ft_strstr(const char *haystack, const char *needle)
{
	if (!*haystack && !*needle)
		return ("");
	while (*haystack)
	{
		if (ft_strcmp(haystack, needle) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return ((char *)0);
}
