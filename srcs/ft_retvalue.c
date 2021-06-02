/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 14:46:39 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/18 19:08:00 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_retvalue(t_number *nbr, t_print *pnt, t_format *fmt)
{
	int ret;

	ret = 0;
	if (pnt->sign)
		ret++;
	if (pnt->space)
		ret++;
	if (pnt->prefix && (fmt->conversion == 'x' || fmt->conversion == 'X'
				|| fmt->conversion == 'p'))
		ret += 2;
	if (pnt->spaces > 0)
		ret += nbr->len + pnt->spaces + pnt->zeros;
	else if (pnt->zeros > 0)
		ret += nbr->len + pnt->zeros;
	else
		ret += nbr->len;
	return (ret);
}
