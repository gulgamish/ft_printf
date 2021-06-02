/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 15:18:04 by aelamran          #+#    #+#             */
/*   Updated: 2018/10/11 16:26:13 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long	int		nbr;
	int				bool;

	nbr = 0;
	bool = 0;
	while (*str == '\t' || *str == '\n' || *str == '\r'
		|| *str == ' ' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
	{
		bool = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while ((*str >= '0' && *str <= '9') && *str)
	{
		nbr += *str - '0';
		nbr *= 10;
		str++;
	}
	if (bool == 1)
		nbr = -nbr;
	return (nbr / 10);
}
