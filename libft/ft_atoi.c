/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idryab <idryab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:26:43 by osabir            #+#    #+#             */
/*   Updated: 2023/08/09 13:08:08 by idryab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	long long	i;
	long long	j;
	long long	res;

	i = 0;
	res = 0;
	j = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			j = j * -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10;
		res = res + (str[i] - 48);
		if ((res * j) > LONG_MAX)
			return (LONG_MAX);
		i++;
	}
	return (res * j);
}
