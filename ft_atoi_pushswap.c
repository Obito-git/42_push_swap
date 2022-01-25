/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_pushswap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:16:40 by amyroshn          #+#    #+#             */
/*   Updated: 2022/01/24 14:24:47 by amyroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_check(char *numb, int *sign)
{
	size_t	i;

	i = 0;
	*sign = 1;
	if (numb[i] == '-')
	{
		*sign = -1;
		i++;
	}
	if (ft_strlen(&numb[i]) > 10 || numb[i] == '0')
		return (0);
	if ((ft_strlen(numb) == 11 && ft_strcmp("-2147483648", numb) < 0)
		|| (i == 0 && ft_strlen(numb) == 10
			&& ft_strcmp("2147483647", numb) < 0))
		return (0);
	while (numb[i] && (numb[i] >= '0' && numb[i] <= '9'))
		i++;
	return (numb[i] == 0);
}

int	ft_atoi_pushswap(char *numb)
{
	int		res;
	size_t	i;
	int		sign;

	res = 0;
	i = 0;
	if (!ft_check(numb, &sign))
		return (0);
	if (numb[i] == '-')
		i++;
	while (numb[i])
	{
		res += (numb[i] - '0') * ft_pow(10, ft_strlen(&numb[i]) - 1);
		i++;
	}
	return (res * sign);
}
